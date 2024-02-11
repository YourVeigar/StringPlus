#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include "../s21_string.h"
#define int8_ long long

typedef struct type_info_pr {
  char left;
  char sign;
  char space;
  char grid;
  char zero;
  char ns_up;
  char sp_e;
  char sp_g;
  int number_systems;
  int width;
  int pc;
} type_info_pr;

const char *set_type_pr(type_info_pr *fmt, const char *format, va_list *args);
const char *get_flags(const char *format, type_info_pr *type);
const char *get_width_pr(const char *format, int *width, va_list *args);
int get_default_pc(char format, int val, const char *specifiers);
char *parser_pr(char *str, char *old, const char *format, type_info_pr type,
                va_list *args);
char *print_dec(char *str, type_info_pr type, char bytec, va_list *args);
s21_size_t get_buf_size_dec(s21_size_t w, s21_size_t p, long int n, int sign);
s21_size_t dec_to_str(char *dest, type_info_pr type, long int d,
                      s21_size_t bsize);
type_info_pr set_number_systems_pr(type_info_pr type, char format);
char *print_u(char *str, type_info_pr type, char bytec, va_list *args);
s21_size_t udec_to_str(char *dest, type_info_pr type, unsigned int8_ d,
                       s21_size_t bsize);
char *print_c(char *str, type_info_pr type, va_list *args);
char *print_s(char *str, type_info_pr type, char bytec, va_list *args);
char *print_p(char *str, type_info_pr type, va_list *args);
char *print_double(char *str, type_info_pr type, char bytec, va_list *args);
s21_size_t get_buf_size_udec(s21_size_t w, s21_size_t p, unsigned int8_ n,
                             s21_size_t ns, int sign);
s21_size_t get_buf_size_double(s21_size_t w, s21_size_t p, long double n,
                               int sign);
type_info_pr set_num_sys_double(type_info_pr type, char format);
s21_size_t flt_to_str(char *dest, type_info_pr type, long double d,
                      s21_size_t bsize);
s21_size_t set_curved_pr(char *dest, long double d, int upper);
char get_num_char(int num, int up);
int normalize(long double *d);
type_info_pr cutter(type_info_pr type, long double d);

#endif  // SRC_S21_SPRINTF_H_
