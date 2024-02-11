#pragma once

#include <stdarg.h>
#include <math.h>
#include <limits.h>
#include "../s21_string.h"
#include "s21_structs.h"

const char *s21_set_specs(specifiers *specs, const char *format, va_list *args);
const char *s21_get_specs(const char *format, specifiers *specs);
const char *s21_get_width(const char *format, specifiers *specs, va_list *args);
const char *s21_get_precision(const char *format, specifiers *specs, va_list *args);
char *s21_parser(char *str, char *str_start, const char *format, specifiers *specs,
             va_list *args);
char *s21_print_c(char *str, specifiers *specs, int sym);
char *s21_print_di(char *str, specifiers *specs, va_list *args);
s21_size_t s21_get_size_of_d(specifiers *specs, long int num);
int s21_decimal_to_string(specifiers *specs, long int num, char *str_to_num,
                      s21_size_t size_to_d);
void s21_check_plus_minus_space(long int num, specifiers *specs, char *str_to_num,
                            int *i, s21_size_t *size_to_d);
char s21_get_num_char(int num, int up_case);
void s21_set_specs_for_ge(specifiers *specs, const char *format);
char *s21_print_f(char *str, specifiers *specs, va_list *args);
s21_size_t s21_get_size_of_f(specifiers *specs, long double num);
char *s21_print_eg(char *str, specifiers *specs, va_list *args);
void s21_cutter(specifiers *specs, long double num);
int s21_normalize(specifiers *specs, long double *num);
int s21_double_to_string(char *str_to_double, specifiers *specs, long double num,
                     s21_size_t size, int e);
void s21_check_plus_minus_space_double(long double num, char *str_to_double,
                                   specifiers *specs, int *i, s21_size_t *size);
void s21_add_sym_from_double_to_str(char *str_to_double, specifiers *specs,
                                int precision, s21_size_t *size, int *i,
                                long double frac, long double integer);
int s21_nan_or_inf(char *str_to_double, long double num);
void s21_print_e(int e, s21_size_t *size, char *str_to_double, specifiers *specs,
             int *i);
void s21_add_sym_to_str(char *str, int *i, char c);
char *s21_print_s(char *str, specifiers *specs, va_list *args);
char *s21_print_p(char *str, specifiers *specs, va_list *args);
void s21_set_num_sys(specifiers *specs, const char *format);
char *s21_print_u(char *str, specifiers *specs, va_list *args);
s21_size_t s21_get_size_of_unsigneg(specifiers *specs, unsigned long int num);
int s21_unsigned_to_string(char *str_to_num, specifiers *specs,
                       unsigned long int num, s21_size_t size_to_unsigned,
                       int flag_ptr);
void s21_check_hash(specifiers *specs, char *str_to_num, int *i,
                s21_size_t *size_to_unsigned);
int s21_is_delim(char ch, const char *delim);