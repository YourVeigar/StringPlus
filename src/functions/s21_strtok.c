#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *resultString;
  static char *backupString;
  if (!str) {
    str = backupString;
  }
  if (!str) {
    resultString = S21_NULL;
  } else {
    for (; *str && s21_is_delim(*str, delim); str++)
      ;
    resultString = str;
    char *delimiterStart = s21_strpbrk(str, delim),
         *initialDelim = delimiterStart;
    for (;
         delimiterStart && *delimiterStart && *delimiterStart == *initialDelim;
         delimiterStart++)
      *delimiterStart = '\0';
    backupString = delimiterStart;
    if (*str == '\0') resultString = S21_NULL;
  }
  return resultString;
}