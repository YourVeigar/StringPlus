#include "string.h"
#include <string.h>

#include <stddef.h>


int s21_strncmp(const char *str1, const char *str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        if (str1[i] == '\0' || str2[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

int main() {
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, world!";

    printf("s21_strncmp: %d\n", s21_strncmp(str1, str2, 7));
    printf("strncmp: %d\n", strncmp(str1, str2, 7));

    return 0;
}

