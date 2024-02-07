//#include <stdio.h>
//#include <string.h>

char *s21_strpbrk(const char *str1, const char *str2) {
    while (*str1) {
        const char *ptr = str2;
        while (*ptr) {
            if (*str1 == *ptr) {
                return (char *)str1;
            }
            ptr++;
        }
        str1++;
    }
    return NULL;
}

//int main() {
//    const char *str1 = "Hello, world!";
//    const char *str2 = "aeiou";
//
//    char *result = s21_strpbrk(str1, str2);
//    char *result2 = strpbrk(str1, str2);
//
//    printf("%c\n", *result2);
//    printf("-------------\n");
//    printf("%c\n", *result);
//
//    return 0;
//}