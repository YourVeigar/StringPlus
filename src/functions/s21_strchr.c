#include "string.h"
#include <string.h>
#include <stdio.h>


char *s21_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}
int main() {
    const char *str = "Hello, world!";
    int ch = 'w';

    char *result_s21 = s21_strchr(str, ch);
    char *result_str = strchr(str, ch);

    printf("s21_strchr: %s\n", result_s21);
    printf("strchr: %s\n", result_str);

    return 0;
}