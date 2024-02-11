#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void *s21_trim(const char *src, const char *trim_chars);
size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
#endif