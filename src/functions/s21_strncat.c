#include <stdio.h>
#include <string.h>

char *s21_strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}


int main() {
    char str1[20] = "Hello, ";
    const char *str2 = "world!";
    char str3[20], str4[20];

    strcpy(str3, str1); // Копируем str1 в str3
    strcpy(str4, str1); // Копируем str1 в str4

    printf("s21_strncat: %s\n", s21_strncat(str3, str2, 3));
    printf("strncat: %s\n", strncat(str4, str2, 3));

    return 0;
}
