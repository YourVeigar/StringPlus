#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) {
    return S21_NULL;  // Проверка на ошибки
  }

  // Вычисление длины исходной строки
  s21_size_t src_len = 0;
  while (src[src_len] != '\0') {
    src_len++;
  }

  // Вычисление длины вставляемой строки
  s21_size_t str_len = 0;
  while (str[str_len] != '\0') {
    str_len++;
  }

  // Проверка на корректность start_index
  if (start_index > src_len) {
    return S21_NULL;  // start_index больше длины исходной строки
  }

  // Вычисление длины новой строки
  s21_size_t new_len = src_len + str_len;

  // Выделение памяти для новой строки
  char *new_str = (char *)malloc((new_len + 1) * sizeof(char));
  if (new_str == S21_NULL) {
    return S21_NULL;  // Ошибка выделения памяти
  }

  // Копирование начальной части src до start_index
  for (s21_size_t i = 0; i < start_index; i++) {
    new_str[i] = src[i];
  }

  // Добавление str в новую строку
  for (s21_size_t i = 0; i < str_len; i++) {
    new_str[start_index + i] = str[i];
  }

  // Добавление оставшейся части src после start_index
  for (s21_size_t i = 0; i <= src_len - start_index; i++) {
    new_str[start_index + str_len + i] = src[start_index + i];
  }

  new_str[new_len] = '\0';

  return new_str;
}