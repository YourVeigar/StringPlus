#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src) {
    result = calloc(s21_strlen(src) + 1, sizeof(char));
    for (; src && *src && s21_is_delim(*src, trim_chars); src++)
      ;
    s21_strncpy(result, src, s21_strlen(src));
    for (int i = (int)s21_strlen(result) - 1;
         i > 0 && s21_is_delim(result[i], trim_chars); i--)
      result[i] = '\0';
  }
  return result;
}
