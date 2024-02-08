#include "s21_insert.h"

#include <stdio.h>
#include <stdlib.h>
void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == NULL || str == NULL) {
    return NULL;  // Проверка на ошибки
  }

  // Вычисление длины исходной строки
  size_t src_len = 0;
  while (src[src_len] != '\0') {
    src_len++;
  }

  // Вычисление длины вставляемой строки
  size_t str_len = 0;
  while (str[str_len] != '\0') {
    str_len++;
  }

  // Проверка на корректность start_index
  if (start_index > src_len) {
    return NULL;  // start_index больше длины исходной строки
  }

  // Вычисление длины новой строки
  size_t new_len = src_len + str_len;

  // Выделение памяти для новой строки
  char *new_str = (char *)malloc((new_len + 1) * sizeof(char));
  if (new_str == NULL) {
    return NULL;  // Ошибка выделения памяти
  }

  // Копирование начальной части src до start_index
  for (size_t i = 0; i < start_index; i++) {
    new_str[i] = src[i];
  }

  // Добавление str в новую строку
  for (size_t i = 0; i < str_len; i++) {
    new_str[start_index + i] = str[i];
  }

  // Добавление оставшейся части src после start_index
  for (size_t i = 0; i <= src_len - start_index; i++) {
    new_str[start_index + str_len + i] = src[start_index + i];
  }

  new_str[new_len] = '\0';

  return new_str;
}

int main() {
  const char *src = "Hello, world!";
  const char *str = "beautiful";
  size_t start_index = 6;

  char *result_s21_insert = s21_insert(src, str, start_index);
  if (result_s21_insert != NULL) {
    printf("Result (s21_insert): %s\n", result_s21_insert);
    free(result_s21_insert);
  } else {
    printf("Error: Unable to insert (s21_insert)\n");
  }

  return 0;
}
