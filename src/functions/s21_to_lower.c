#include <stdio.h>
#include <stdlib.h>

char *s21_to_lower(const char *str) {
    size_t length = 0;
    while (str[length]) {
        length++;
    }

    char *result = malloc(sizeof(char) * (length + 1));
    if (result == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            result[i] = str[i] + ('a' - 'A');
        } else {
            result[i] = str[i];
        }
    }

    result[length] = '\0';

    return result;
}

//int main() {
//    const char *str = "Hello, world!";
//
//    char *result = s21_to_lower(str);
//
//    if (result != NULL) {
//        printf("%s", result);
//        free(result);
//    } else {
//        printf("Error");
//    }
//
//    return 0;
//}