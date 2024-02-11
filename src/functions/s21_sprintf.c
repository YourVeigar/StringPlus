#include "../headers/s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char specifiers[] = "diuoxXcsnpfFeEgG%";
  int flag = -1;
  char *old = str;
  va_list args;
  va_start(args, format);

  for (; *format && str; format++) {
    if (*format == '%') {
      type_info_pr type = {0, 0, 0, 0, 0, 0, 0, 0, 10, 0, INT_MAX};
      format++;
      format = set_type_pr(&type, format, &args);
      while (!s21_strchr(specifiers, *format)) format++;
      type.pc = get_default_pc(*format, type.pc, specifiers);
      str = parser_pr(str, old, format, type, &args);
    } else {
      *(str++) = *format;
    }
  }
  va_end(args);
  if (str) {
    *str = '\0';
    flag = (int)(str - old);
  }
  return flag;
}

const char *set_type_pr(type_info_pr *type, const char *format, va_list *args) {
  format = get_flags(format, type);
  format = get_width_pr(format, &(type->width), args);
  if (*format == '.') format = get_width_pr(++format, &(type->pc), args);
  if (type->width < 0) {
    type->width = -type->width;
    type->left = 1;
  }
  if (type->pc < 0) type->pc = INT_MAX;
  return format;
}

const char *get_flags(const char *format, type_info_pr *type) {
  while (format) {
    if (*format == '+')
      type->sign = 1;
    else if (*format == '-')
      type->left = 1;
    else if (*format == '#')
      type->grid = 1;
    else if (*format == ' ')
      type->space = 1;
    else if (*format == '0')
      type->zero = 1;
    else
      break;
    format++;
  }
  type->space = (char)(type->space && !type->sign);
  type->zero = (char)(type->zero && !type->left);
  return format;
}

const char *get_width_pr(const char *format, int *width, va_list *args) {
  *width = 0;
  if (*format == '*') {
    *width = va_arg(*args, int);
    format++;
  }
  while (format) {
    if ('0' <= *format && *format <= '9' &&
        *width < (INT_MAX - *format + '0') / 10)
      *width = (*width) * 10 + *format - '0';
    else
      break;
    format++;
  }
  return format;
}

int get_default_pc(char format, int val, const char *specifiers) {
  int flag = val;
  if (val == INT_MAX) {
    for (int i = 0; i < 17; i++) {
      if (format == specifiers[i]) {
        if (i >= 0 && i < 6) flag = 1;
        if (i >= 10 && i < 17) flag = 6;
        if (format == 'p') flag = 1;
      }
    }
  }
  return flag;
}

char *parser_pr(char *str, char *old, const char *format, type_info_pr type,
                va_list *args) {
  if (*format == 'd' || *format == 'i') {
    str = print_dec(str, type, *(format - 1), args);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    type = set_number_systems_pr(type, *format);
    str = print_u(str, type, *(format - 1), args);
  } else if (*format == 'c') {
    str = print_c(str, type, args);
  } else if (*format == 's') {
    str = print_s(str, type, *(format - 1), args);
  } else if (*format == 'p') {
    str = print_p(str, type, args);
  } else if (*format == 'n') {
    int *n = va_arg(*args, int *);
    *n = (int)(str - old);
  } else if (*format == 'f' || *format == 'F' || *format == 'e' ||
             *format == 'E' || *format == 'g' || *format == 'G') {
    type = set_num_sys_double(type, *format);
    str = print_double(str, type, *(format - 1), args);
  } else if (*format == '%') {
    *(str++) = *format;
  } else {
    str = S21_NULL;
  }
  if (!str) *old = '\0';
  return str;
}

char *print_dec(char *str, type_info_pr type, char bytec, va_list *args) {
  long int var = 0;
  s21_size_t bsize = 0;
  if (bytec == 'l')
    var = (long int)va_arg(*args, long int);
  else if (bytec == 'h')
    var = (short)va_arg(*args, int);
  else
    var = (int)va_arg(*args, int);
  bsize = get_buf_size_dec(type.width, type.pc, var,
                           type.sign | type.space | (var < 0));
  char *buffer = malloc(bsize);
  if (buffer) {
    int i = (int)(dec_to_str(buffer, type, var, bsize));
    for (int j = i - 1; j >= 0; j--, str++) *str = buffer[j];
    for (; i < type.width; i++, str++) *str = ' ';
  }
  if (buffer) free(buffer);
  return str;
}

s21_size_t get_buf_size_dec(s21_size_t w, s21_size_t p, long int n, int sign) {
  s21_size_t i = 0;
  while (n != 0) {
    n /= 10;
    i++;
  }
  i += sign;
  p += sign;
  s21_size_t result = i;
  if (w > result) result = w;
  if (p > result) result = p;
  return result;
}

s21_size_t dec_to_str(char *dest, type_info_pr type, long int d,
                      s21_size_t bsize) {
  s21_size_t i = 0;
  long double n = fabsl((long double)d);
  int sign = type.sign || type.space || d < 0;
  for (; (i < bsize && n >= 1.0); i++, n /= 10)
    dest[i] = (char)(fmodl(n, 10.0l) + 48);
  for (; (i + sign < (s21_size_t)type.width && type.zero) ||
         i < (s21_size_t)type.pc;
       i++)
    dest[i] = '0';

  if (type.space && d >= 0) dest[i++] = ' ';
  if (d < 0) dest[i++] = '-';
  if (type.sign && d > 0) dest[i++] = '+';

  for (; i < (s21_size_t)type.width && !type.left; i++) dest[i] = ' ';
  return i;
}

type_info_pr set_number_systems_pr(type_info_pr type, char format) {
  if (format == 'o')
    type.number_systems = 8;
  else if (format == 'x' || format == 'X')
    type.number_systems = 16;
  if (format == 'X') type.ns_up = 1;
  return type;
}

char *print_u(char *str, type_info_pr type, char bytec, va_list *args) {
  unsigned int8_ var = 0;
  if (bytec == 'l')
    var = (unsigned long int)va_arg(*args, unsigned long int);
  else if (bytec == 'h')
    var = (unsigned short)va_arg(*args, unsigned int);
  else
    var = (unsigned int)va_arg(*args, unsigned int);
  s21_size_t bsize =
      get_buf_size_udec(type.width, type.pc, var, type.number_systems,
                        type.space + type.grid + (type.number_systems == 16));
  char *buffer = malloc(bsize);
  if (buffer) {
    int i = (int)(udec_to_str(buffer, type, var, bsize));
    for (int j = i - 1; j >= 0; j--, str++) *str = buffer[j];
    for (; i < type.width; i++, str++) *str = ' ';
  }
  if (buffer) free(buffer);
  return str;
}

s21_size_t udec_to_str(char *dest, type_info_pr type, unsigned int8_ d,
                       s21_size_t bsize) {
  s21_size_t i = 0;
  unsigned int8_ n = d;
  int sign = (((type.space && type.number_systems == 10) ||
               (type.grid && type.number_systems == 8)) +
              2 * (type.grid && type.number_systems == 16));
  for (sign *= (d != 0); i < bsize && n > 0; i++, n /= type.number_systems)
    dest[i] = (char)(get_num_char((int)(n % type.number_systems), type.ns_up));
  for (; (i + sign < (s21_size_t)type.width && type.zero) ||
         i + type.grid * (type.number_systems == 8) < (s21_size_t)type.pc;
       i++)
    dest[i] = '0';

  if (d || type.sp_g) {
    if (type.grid && type.number_systems == 16 && type.ns_up)
      dest[i++] = 'X';
    else if (type.grid && type.number_systems == 16 && !type.ns_up)
      dest[i++] = 'x';
    if (type.grid && type.number_systems != 10) dest[i++] = '0';
  }

  for (; i < (s21_size_t)type.width && !type.left; i++) dest[i] = ' ';
  return i;
}

char *print_c(char *str, type_info_pr type, va_list *args) {
  char *flag = S21_NULL;
  int var = va_arg(*args, int);
  for (int i = 0; i < type.width - 1 && !type.left; i++, str++) *str = ' ';
  *str = '\0';
  if (var <= UCHAR_MAX) {
    *(str++) = (char)(var);
    for (int i = 0; i < type.width - 1 && type.left; i++, str++) *str = ' ';
    flag = str;
  }
  return flag;
}

char *print_s(char *str, type_info_pr type, char bytec, va_list *args) {
  char *flag = str;
  char *var = va_arg(*args, char *);
  if (var) {
    int blank = type.width;
    if (s21_strlen(var) >= (s21_size_t)type.pc)
      blank -= type.pc;
    else
      blank -= (int)(s21_strlen(var));
    for (int i = 0; i < blank && !type.left; i++, str++) *str = ' ';
    for (int i = 0; i < type.pc && *var; i++, str++) {
      if (bytec == 'l') {
        if (*((wchar_t *)var) <= UCHAR_MAX)
          *str = *var;
        else
          flag = S21_NULL;
        var += sizeof(wchar_t);
      } else {
        *str = *var;
        var++;
      }
    }
    for (int i = 0; i < blank && type.left; i++, str++) *str = ' ';
  } else {
    str = s21_memcpy(str, "(null)", 6);
    str += 6;
  }
  if (flag) flag = str;
  return flag;
}

char *print_p(char *str, type_info_pr type, va_list *args) {
  s21_size_t bsize = 0;
  void *var = va_arg(*args, void *);
  unsigned int8_ ptr = (unsigned int8_)var;
  type.number_systems = 16;
  type.sp_g = 1;
  type.grid = 1;
  bsize = get_buf_size_udec(type.width, type.pc, ptr, type.number_systems,
                            type.grid * 2);
  char *buffer = malloc(bsize);
  if (buffer) {
    int i = (int)(udec_to_str(buffer, type, ptr, bsize));
    for (int j = i - 1; j >= 0; j--, str++) *str = buffer[j];
    for (; i < type.width; i++, str++) *str = ' ';
  }
  if (buffer) free(buffer);
  return str;
}

s21_size_t get_buf_size_udec(s21_size_t w, s21_size_t p, unsigned int8_ n,
                             s21_size_t ns, int sign) {
  s21_size_t i = 0;
  while (n != 0) {
    n /= ns;
    i++;
  }
  i += sign;
  p += sign;
  s21_size_t result = i;
  if (w > result) result = w;
  if (p > result) result = p;
  return result;
}

s21_size_t get_buf_size_double(s21_size_t w, s21_size_t p, long double n,
                               int sign) {
  s21_size_t i = 1 + (p > 0);
  while (fabsl(n) - 1.0 >= 0 && isfinite(n)) {
    n /= 10.0;
    i++;
  }
  i += p + sign;
  if (!isfinite(n)) i = 5;
  return (w > i) ? w : i;
}

type_info_pr set_num_sys_double(type_info_pr type, char format) {
  if (format == 'g' || format == 'G')
    type.sp_g = 1;
  else if (format == 'e' || format == 'E')
    type.sp_e = 1;
  if (format == 'G' || format == 'E' || format == 'F') type.ns_up = 1;
  return type;
}

char *print_double(char *str, type_info_pr type, char bytec, va_list *args) {
  long double var = 0.0;
  s21_size_t bsize = 0;
  int e = 0;
  if (bytec == 'L')
    var = va_arg(*args, long double);
  else
    var = va_arg(*args, double);
  if (type.sp_g) type = cutter(type, var);
  if (type.sp_e) e = normalize(&var);
  bsize = get_buf_size_double(type.width, type.pc, var,
                              type.sign | type.space | (var < 0));
  char *buffer = malloc(bsize);
  if (buffer) {
    int i = (int)(flt_to_str(buffer, type, var, bsize));
    for (int j = i - 1; j >= 0; j--, str++) *str = buffer[j];
    if (type.sp_e) {
      *(str++) = (char)('e' - type.ns_up * 32);
      *(str++) = (char)('-' * (e < 0) + '+' * (e >= 0));
      *(str++) = (char)(abs(e / 10) + 48);
      *(str++) = (char)(abs(e % 10) + 48);
    }
    for (; i + 4 * type.sp_e < type.width; i++, str++) *str = ' ';
  }
  if (buffer) free(buffer);
  return str;
}

s21_size_t flt_to_str(char *dest, type_info_pr type, long double d,
                      s21_size_t bsize) {
  s21_size_t i = 0;
  i = (s21_size_t)(set_curved_pr(dest, d, type.ns_up));
  if (!i) {
    long double whol = 0.0, frac = 0.0;
    frac = modfl(d, &whol);
    frac = roundl(fabsl(frac) * powl(10.0l, type.pc));
    if (type.sp_g && !type.grid) {
      for (; (int)frac % 10 == 0 && frac > 0; frac /= 10.0l, type.pc--) {
      }
    }
    if (type.sp_g && !frac) type.pc = 0;
    if (type.pc) {
      for (; i < bsize && i < (s21_size_t)type.pc; i++, frac /= 10.0l)
        dest[i] = (char)((frac - floorl(frac / 10.0l) * 10.0l) + 48);
      dest[i++] = '.';
    }
    for (whol = roundl(fabsl(whol) + frac * (type.pc == 0));
         i < bsize && whol >= 10.0l; i++, whol /= 10.0l)
      dest[i] = (char)((whol - floorl(whol / 10.0l) * 10.0l) + 48);
    dest[i++] = (char)(whol + 48);
    for (; i + (type.sign || type.space || d < 0) + 4 * type.sp_e <
               (s21_size_t)type.width &&
           type.zero;
         i++)
      dest[i] = '0';
    if (type.space && d >= 0) dest[i++] = ' ';
    if (d < 0) dest[i++] = '-';
    if (type.sign && d > 0) dest[i++] = '+';
    for (; i + 4 * type.sp_e < (s21_size_t)type.width && !type.left; i++)
      dest[i] = ' ';
  }
  return i;
}

s21_size_t set_curved_pr(char *dest, long double d, int upper) {
  int flag = 0;
  if (isnan(d)) {
    if (upper) {
      s21_strcpy(dest, "NAN");
    } else {
      s21_strcpy(dest, "nan");
    }
    flag = 3;
  } else if (d == INFINITY) {
    if (upper) {
      s21_strcpy(dest, "INF");
    } else {
      s21_strcpy(dest, "inf");
    }
    flag = 3;
  } else if (d == -INFINITY) {
    if (upper) {
      s21_strcpy(dest, "INF-");
    } else {
      s21_strcpy(dest, "inf-");
    }
    flag = 4;
  }
  return flag;
}

char get_num_char(int num, int up) {
  char flag = '?';
  switch (num) {
    case 10:
      flag = (char)('a' - up * 32);
      break;
    case 11:
      flag = (char)('b' - up * 32);
      break;
    case 12:
      flag = (char)('c' - up * 32);
      break;
    case 13:
      flag = (char)('d' - up * 32);
      break;
    case 14:
      flag = (char)('e' - up * 32);
      break;
    case 15:
      flag = (char)('f' - up * 32);
      break;
  }
  if (0 <= num && num <= 9) flag = (char)(num + 48);
  return flag;
}
// for double
type_info_pr cutter(type_info_pr type, long double d) {
  int e = normalize(&d);
  if (!type.pc) type.pc = 1;
  if (-4 <= e && e < type.pc) {
    type.pc = type.pc - e - 1;
  } else {
    type.sp_e = 1;
    type.pc -= 1;
  }
  return type;
}
// for double
int normalize(long double *d) {
  int e = 0;
  if (*d) {
    if (fabsl(*d) < 1.0) {
      for (; fabsl(*d) < 1.0; *d = *d * 10, e--) {
      }
    } else if (fabsl(*d) >= 10.0) {
      for (; fabsl(*d) >= 10.0; *d = *d / 10, e++) {
      }
    }
  }
  return e;
}
