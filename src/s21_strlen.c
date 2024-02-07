//#include <stdio.h>

size_t s21_strlen(const char *str) {
    size_t length = 0;
    while (*str++) {
        length++;
    }
    return length;
}

//int main() {
//    const char *str = "0123456789";
//    size_t length = s21_strlen(str);
//    printf("Length of the string: %zu\n", length);
//    return 0;
//}
