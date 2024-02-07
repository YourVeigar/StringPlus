#include <stdio.h>
#include <string.h>

char *s21_strncpy(char *dest, const char *src, size_t n) {
    char *ptr = dest;
    size_t i;

    // Копируем символы из src в dest с учетом n
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    // Если n больше длины src, заполняем оставшуюся часть dest нулями
    for (; i < n; i++) {
        dest[i] = '\0';
    }

    return ptr;
}

int main() {
    const char *src = "Hello, world!";
    char dest1[20], dest2[20];
    size_t n = 5;

    printf("s21_strncpy: %s\n", s21_strncpy(dest1, src, n));
    printf("strncpy: %s\n", strncpy(dest2, src, n));

    return 0;
}
