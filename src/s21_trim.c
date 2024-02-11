#include "s21_trim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t s21_strlen(const char *str) {
  size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}
char *s21_strchr(const char *str, int c) {
  while (*str != '\0') {
    if (*str == (char)c) {
      return (char *)str;
    }
    str++;
  }
  return NULL;
}

void *trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) {
    return NULL;
  }

  size_t src_len = s21_strlen(src);
  size_t start_index = 0;
  size_t end_index = src_len - 1;

  // Находим начальный индекс для обрезки
  while (start_index < src_len &&
         s21_strchr(trim_chars, src[start_index]) != NULL) {
    start_index++;
  }

  // Находим конечный индекс для обрезки
  while (end_index > start_index &&
         s21_strchr(trim_chars, src[end_index]) != NULL) {
    end_index--;
  }

  // Вычисляем длину обрезанной строки
  size_t new_len = end_index - start_index + 1;
  if (new_len == 0) {
    return NULL;
  }

  // Создаем новую строку и копируем обрезанную часть
  char *new_str = (char *)malloc((new_len + 1) * sizeof(char));
  if (new_str == NULL) {
    return NULL;
  }
  for (size_t i = 0; i < new_len; i++) {
    new_str[i] = src[start_index + i];
  }
  new_str[new_len] = '\0';

  return new_str;
}

int main() {
  const char *src = "   Hello, world!   ";
  const char *trim_chars = " ";

  char *trimmed = trim(src, trim_chars);
  if (trimmed != NULL) {
    printf("Trimmed string: \"%s\"\n", trimmed);
    free(trimmed);
  } else {
    printf("Error: Unable to trim\n");
  }

  return 0;
}
