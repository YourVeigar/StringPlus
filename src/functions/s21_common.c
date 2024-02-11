#include "../headers/s21_common.h"

int s21_is_delim(char ch, const char *delim) {
  int result = 0;
  for (; delim && *delim != '\0'; delim++) {
    if (*delim == ch) {
      result = 1;
    }
  }
  return result;
}