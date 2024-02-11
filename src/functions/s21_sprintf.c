#include "../headers/s21_common.h"


int s21_sprintf(char *str, const char *format, ...) {
  char *str_start = str;
  char spec[] = "cdeEfgGosuxXp%";
  va_list(args);
  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;
      specifiers specs = {0};
      specs.num_sys = 10;
      format = s21_set_specs(&specs, format, &args);
      while (!s21_strchr(spec, *format)) format++;
      str = s21_parser(str, str_start, format, &specs, &args);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  *str = '\0';
  va_end(args);
  return (str - str_start);
}