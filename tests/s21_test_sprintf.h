#ifndef TEST_HEADER_SPRINTF_
#define TEST_HEADER_SPRINTF_

#include "../src/s21_string.h"
#include "s21_test.h"
#define BUFFEER_SIZE 512

#endif

START_TEST(s21_sprintf_test1) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: %+5d, num2: %+5d\n";
  int value1 = 10;
  int value2 = -10;
  sprintf(origDest, formatString, value1, value2);
  s21_sprintf(testDest, formatString, value1, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test2) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: %5d, num2: %5d";
  int value1 = 10;
  int value2 = -10;
  sprintf(origDest, formatString, value1, value2);
  s21_sprintf(testDest, formatString, value1, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test3) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: %*d, num2: %*d";
  int value1 = 10;
  int value2 = -10;
  int width1 = 5;
  int width2 = 10;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test4) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "num1: % *d, num2: %*d";
  int value1 = 8564;
  int value2 = -101000;
  int width1 = 5;
  int width2 = 10;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test5) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "num1: %*d, num2: %*d";
  int value1 = 0x8564;
  int value2 = -0x101000;
  int width1 = 100;
  int width2 = 100;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test6) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};
  char formatString[] = "num1: %*d, num2: %*d";
  int value1 = 0x8564;
  int value2 = 0x1010;
  int width1 = 25;
  int width2 = 25;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test7) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "num1: %-*d, num2: %-*d";
  int value1 = 5;
  int value2 = -10;
  int width1 = 10;
  int width2 = 10;
  sprintf(origDest, formatString, width1, value1, width2, value2);
  s21_sprintf(testDest, formatString, width1, value1, width2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test8) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  const char *formatString = "%c%c%c%c%c%c%c%c%c%c%c%c";

  sprintf(origDest, formatString, 'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e',
          'r', 'e', '!');
  s21_sprintf(testDest, formatString, 'H', 'e', 'l', 'l', 'o', ' ', 't', 'h',
              'e', 'r', 'e', '!');

  ck_assert_str_eq(origDest, testDest);
}

END_TEST
START_TEST(s21_sprintf_test9) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somechars: %c%c";

  sprintf(origDest, formatString, 'H', 'e');
  s21_sprintf(testDest, formatString, 'H', 'e');

  ck_assert_str_eq(origDest, testDest);
}

END_TEST
START_TEST(s21_sprintf_test10) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "%c %c";

  sprintf(origDest, formatString, 'E', 'E');
  s21_sprintf(testDest, formatString, 'E', 'E');

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test11) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "string: % 100s, string2: %s, string3: %s";
  char string1[] = "Hello there!\n";
  char string2[] = "another Hello there!\n";
  char string3[] = "one more time Hello there!\n";

  sprintf(origDest, formatString, string1, string2, string3);
  s21_sprintf(testDest, formatString, string1, string2, string3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test12) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "%s%s%s";
  char string1[] = "Hello there!\n";
  char string2[] = "another Hello there!\n";
  char string3[] = "one more time Hello there!\n";

  sprintf(origDest, formatString, string1, string2, string3);
  s21_sprintf(testDest, formatString, string1, string2, string3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test13) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %x";
  int num1 = 0x1fffff;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

START_TEST(s21_sprintf_test14) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10x %10x %10x %10x";
  int num1 = 0x1fffff;
  long int num2 = -0xffffffff;
  long int num3 = 0xffffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test15) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10x %10x %10x %10x";
  int num1 = 100;
  long int num2 = -0xffffffff;
  long int num3 = 0xffffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test16) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10X %10X %10X %10X";
  int num1 = 100;
  long int num2 = -0xfffffff;
  long int num3 = 0xfffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test17) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10x %10x %10X %10X";
  int num1 = 100;
  long int num2 = -0xffffffff;
  long int num3 = 0xffffffff;
  int num4 = -0;

  sprintf(origDest, formatString, num1, num2, num3, num4);
  s21_sprintf(testDest, formatString, num1, num2, num3, num4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test18) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10X";
  int num1 = 100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test19) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10p";
  int num = 100;
  int *pNum = &num;

  sprintf(origDest, formatString, pNum);
  s21_sprintf(testDest, formatString, pNum);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test20) {
  char origDest[100] = {0};
  char testDest[100] = {0};
  char formatString[] = "Somestrings: %10p %10p %10p %10p";
  int num1 = 100;
  int num2 = 100;
  int num3 = 100;
  int num4 = 100;

  int *pNum1 = &num1;
  int *pNum2 = &num2;
  int *pNum3 = &num3;
  int *pNum4 = &num4;
  sprintf(origDest, formatString, pNum1, pNum2, pNum3, pNum4);
  s21_sprintf(testDest, formatString, pNum1, pNum2, pNum3, pNum4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test21) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-25p %25p %-25p %25p";
  int num1 = 100;
  int num2 = 100;
  int num3 = 100;
  int num4 = 100;

  int *pNum1 = &num1;
  int *pNum2 = &num2;
  int *pNum3 = &num3;
  int *pNum4 = &num4;
  sprintf(origDest, formatString, pNum1, pNum2, pNum3, pNum4);
  s21_sprintf(testDest, formatString, pNum1, pNum2, pNum3, pNum4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST
START_TEST(s21_sprintf_test22) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-50p %+-++050p %-25p %25p";
  int num1 = 100;
  int num2 = 100;
  int num3 = 100;
  int num4 = 100;

  int *pNum1 = &num1;
  int *pNum2 = &num2;
  int *pNum3 = &num3;
  int *pNum4 = &num4;
  sprintf(origDest, formatString, pNum1, pNum2, pNum3, pNum4);
  s21_sprintf(testDest, formatString, pNum1, pNum2, pNum3, pNum4);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test23) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  int num1 = 100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test24) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  unsigned int num1 = 100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test25) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  unsigned int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test26) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %u";
  int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test27) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+u %+u %+-u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test28) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-+u %+-u %+-u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test29) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %-0+u %+0-u %+0-u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test30) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0u %0u %0u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test31) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %010u %010u %010u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test32) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %025u %025u %025u";
  int num1 = -100;
  int num2 = 10101001;
  int num3 = 91919191;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test33) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %o";
  int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test34) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %o %o %o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test35) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+o %+o %+o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test36) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+-o %-+o %+-o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test37) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-o %0-+o %0+-o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test38) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-25o %0-+o %0+-25o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test39) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-010o %0-+010o %0+-010o";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test40) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %i";
  int num1 = -100;

  sprintf(origDest, formatString, num1);
  s21_sprintf(testDest, formatString, num1);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test41) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %i %i %i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test42) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+i %+i %+i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test43) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %+-i %-+i %+-i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test44) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-i %0-+i %0+-i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test45) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-25i %0-+i %0+-25i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test46) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char formatString[] = "Somestrings: %0+-010i %0-+010i %0+-010i";
  int num1 = -100;
  int num2 = 01000;
  int num3 = 010010;

  sprintf(origDest, formatString, num1, num2, num3);
  s21_sprintf(testDest, formatString, num1, num2, num3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test47) {
  double array[] = {0.00000002, 1.12,  1.123,  1.1234,  10.5,  1.,
                    -1.,        -1.12, -1.123, -1.1234, -10.5, -10.12345};
  const int countTestNums = sizeof(array) / sizeof(array[0]);
  const int countFormatStrings = 7;
  const char formatStrings[7][50] = {
      "Somestring: %+0000000015E", "Somestring: %+15e",

      "Somestring: %+015e",        "Somestring: %.10e", "Somestring: %000e",
      "Somestring: %000.2e",       "Somestring: %0e",
  };
  for (int i = 0; i < countTestNums; ++i) {
    for (int j = 0; j < countFormatStrings; ++j) {
      char origDest[1000] = {0};
      char testDest[1000] = {0};
      sprintf(origDest, formatStrings[j], array[i]);
      s21_sprintf(testDest, formatStrings[j], array[i]);

      ck_assert_str_eq(origDest, testDest);
    }
  }
}

END_TEST

START_TEST(s21_sprintf_test48) {
  double array[] = {2,  12,   123,  1234,  1.001, 1,
                    -1, 1000, 1123, 11234, -101,  101245};
  int size = sizeof(array) / sizeof(array[0]);
  for (int i = 0; i < size; ++i) {
    char origDest[1000] = {0};
    char testDest[1000] = {0};
    char formatString[] = "Somestrings: %g";
    sprintf(origDest, formatString, array[i]);
    s21_sprintf(testDest, formatString, array[i]);
    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test49) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char *formatString = "somestring: %s%n";

  int origLength = 0;
  int testLength = 0;
  char *string = "123456789";

  sprintf(origDest, formatString, string, &origLength, &origLength);
  s21_sprintf(testDest, formatString, string, &testLength);
  ck_assert_str_eq(origDest, testDest);
  ck_assert_int_eq(origLength, testLength);
}

END_TEST

START_TEST(s21_sprintf_test50) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  char *formatString = "somestring: %s:tring: %s: tring: %s:tring: %s%n";

  int origLength = 0;
  int testLength = 0;
  char *string = "123456789";
  char *string2 = "String a bit longer";

  sprintf(origDest, formatString, string, string2, string, string2,
          &origLength);
  s21_sprintf(testDest, formatString, string, string2, string, string2,
              &testLength);
  ck_assert_str_eq(origDest, testDest);
  ck_assert_int_eq(origLength, testLength);
}

END_TEST

START_TEST(s21_sprintf_test51) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};
  const char *formatString = "num1: %*.*f";
  float value1 = 123.f;
  float value2 = -444.f;
  int width1 = 10;
  int precision1 = 10;
  int width2 = 10;
  int precision2 = 10;

  sprintf(origDest, formatString, width1, precision1, value1, width2,
          precision2, value2);
  s21_sprintf(testDest, formatString, width1, precision1, value1, width2,
              precision2, value2);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test52) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: %f, num2: %f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test53) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % +f, num2: % +10f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test54) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % 0+100.14f, num2: % +100.50f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test55) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % 0+100f, num2: % +.50f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST
START_TEST(s21_sprintf_test56) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  float nums[] = {
      123.123456789f,
      -123.12300011111f,
      -123.123456789f,
      111312323423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342.001000000000010000000000000000000000000010000000000000000001f,
      111312323423423423.001000000000010000000000000000000000000010000000000000000001f,
      1113123234234234234.001000000000010000000000000000000000000010000000000000000001f,
      11131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
      111131232342342342341.001000000000010000000000000000000000000010000000000000000001f,
  };

  char formatString[] = "num1: % 0+100f, num2: % +.50f";
  int count = 10;
  for (int i = 0; i < count; ++i) {
    sprintf(origDest, formatString, nums[i], nums[i]);
    s21_sprintf(testDest, formatString, nums[i], nums[i]);

    ck_assert_str_eq(origDest, testDest);
  }
}

END_TEST

START_TEST(s21_sprintf_test57) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};
  char formatString[] = "string: %s, string2: %s, string3: %s";
  char string1[1000] = "☀☀☀☀☀☀☀⚪⛱️️☀☀☀☀☀☀☀";
  char string2[1000] =
      "☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀☀⚪⛱️🍀"
      "☘"
      "e"
      "☀"
      "☀"
      "☀"
      "☀";
  char string3[1000] =
      "Somessss☀☀☀☀☀☀☀☀☀️🍀☘essss☀☀☀☀☀☀☀"
      "☀"
      "☀"
      "🇺"
      "🇾"
      "☀"
      "️"
      "⚪"
      "⛱"
      "️"
      "🍀"
      "☘"
      "️";
  sprintf(origDest, formatString, string1, string2, string3);
  s21_sprintf(testDest, formatString, string1, string2, string3);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test58) {
  float array[] = {
      0.5f,
      0.555555555555555555555555555555555555333333333555555555f,
      233333333333333333333333333333333.3222222222222222222222222222222222222222222f,
      1242.23521f,
      1111.9939999999999999999999999999999999999999999f,
      1.555555555555555555555555555555555555333333333555555555f,
      0.500009f,
      0.500004f,
      0.500001f,
      0.500000f,
      0.5000006f,
      0.5000004f,
      0.5000044f,
      0.5000048f,
      0.55000000f,
      0.550005f,
      0.550004f,
      0.5500006f,
      5.5500000f,
      200000000000000000.0f,
      210000000000000000.0f,
      239847.2340f,
      0.00000001f,
      1.123456f,
      12.34567124f,
      123.456767f,
      1234.56775f,
      12345.677f,
      123456.76f,
      10000000.000018f,
      0.0000000015015088f,
      10.00000000118811f,
      11231231231231231230.0800000f,
      2351230.000000f,
      1241478888830.000009999999999999999999999999999999999999999999999990f,
      77777.000000f,
      1.0f,
      10.0f,
      100.0f,
      1000.0f,
      10000.0f,
      100000.0f,
      1000000.0f,
      10000000.0f,
      100000000.0f,
      1000000000.0f,
      10000000000.0f,
      100000000000.0f,
      1000000000000.0f,
      10000000000000.0f,
      100000000000000.0f,
      0.001f,
      0.0001f,
      0.00001f,
      0.000001f,
      0.0000001f,
      0.00000001f,
      0.000000001f,
      0.0000000001f,
      0.00000000001f,
      0.000000000001f,
      0.0000000000001f,
      0.0f,
      2,
      12,
      123,
      1234,
      1011,
      1,
      -1,
      1000,
      1123,
      11234,
      -101,
      101245,
      1.12f};

  int numTests = sizeof(array) / sizeof(float);

  const int countFormatStrings = 9;
  const char formatStrings[10][50] = {
      "Somestring: %g",    "Somestring: %g",

      "Somestring: %G",    "Somestring: %G",     "Somestring: %050.6g",
      "Somestring: %g",    "Somestring: %0100g", "Somestring: %100.6g",
      "Somestring: %010g",
  };
  for (int i = 0; i < numTests; ++i) {
    for (int j = 0; j < countFormatStrings; ++j) {
      char origDest[1000] = {0};
      char testDest[1000] = {0};
      sprintf(origDest, formatStrings[j], array[i]);
      s21_sprintf(testDest, formatStrings[j], array[i]);

      ck_assert_str_eq(origDest, testDest);
    }
  }
}

END_TEST

START_TEST(s21_sprintf_test59) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};

  char formatString[] = "string: %s";
  char string[1000] = "☀☀☀☀☀🇺🇾☀️⚪⛱️🍀☘☀☀☀⚪";
  sprintf(origDest, formatString, string);
  s21_sprintf(testDest, formatString, string);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test60) {
  char origDest[10000] = {0};
  char testDest[10000] = {0};

  char formatString[] = "string: %ls";
  wchar_t string[1000] =
      L"Here's some wide string, one char here is 2 or 4 bytes";
  sprintf(origDest, formatString, string);
  s21_sprintf(testDest, formatString, string);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST

START_TEST(s21_sprintf_test61) {
  char origDest[1000] = {0};
  char testDest[1000] = {0};

  char formatString[] = "string: %s";
  char string[1000] = "Here's some wide string, one char here is 2 or 4 bytes";
  sprintf(origDest, formatString, string);
  s21_sprintf(testDest, formatString, string);

  ck_assert_str_eq(origDest, testDest);
}

END_TEST
START_TEST(s21_sprintf_test62) {
  char testDest[100];

  char formatString[] = "string: %s";
  char string[1000] = "Here's some wide string, one char here is 2 or 4 bytes";
  s21_sprintf(testDest, formatString, string);
}

END_TEST
START_TEST(simplE_int11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "Thyn FEGWGRWG GRWGRWle value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(precisE_int11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(width_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(minus_width_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(plus_width_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(padding_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(star_width_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(star_precision_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(many_flags_many_ints1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(flags_long_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(flags_short_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(flags_another_long_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(zero_precision_zero_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(space_flag_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(unsigned_val1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(unsigned_val1_width) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(unsigned_val1_flags) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-16x";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(unsigned_val1_precision) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(unsigned_val1_many_flags) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(unsigned_val1_short) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(unsigned_val1_long) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(unsigned_val1_many) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(octal1_width1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(octal1_flags1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-16u";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(octal1_precision1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(octal1_many_flags) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(octal1_zero) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(octal1_hash) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(octal1_short) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(octal1_long) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(octal1_many) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "|%lo|, |%o|, |%ho| , |%.5o|, |%5.o|";

  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(octal1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(unsigned_zero1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(hex_width1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(hex_flags1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_precision1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_many1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#-10x %x %X %#x %#X %5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_many1_flags) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_zero1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_huge1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_short1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_long1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(hex_one_longer_width1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(hex_two_longer_width1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(one_char1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(one_precision11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(one_flags11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "% -10c";
  char val = 'a';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(one_width11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(one_many11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(one_many11_flags) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(string1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(string1_precision) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(string1_width) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(string1_flags) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(string1_long) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPlenED TO BE A VERY LONG string1";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(string1_many) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPlenED TO BE A VERY LONG string1";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(ptr1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(ptr1_width) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(ptr1_precision) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(null_ptr1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "%p";
  char *ptr1 = S21_NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr1),
                   sprintf(str2, format, ptr1));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(string1_width_huge) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *val = "kjafdiuhgcyukutkfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(n_specifier1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  int ret = 0;
  int ret1 = 0;
  char *format = "I am not  lemur %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret1));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(ret, ret1);
}

END_TEST
START_TEST(float_precision1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%Lf";
  long double val = 5135.11;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(float_width1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(float_precision1_zero) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(float_precision1_empty) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(float_precision1_huge) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(float_precision1_huge_negative) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(float_huge1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(float_flags1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(float_many1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = (float)5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(e_precision1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "    %Le";
  long double val = 15.325;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(e_precision1_zero) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(e_precision1_empty) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(e_precision1_huge) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(e_precision1_huge_negative) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(e_huge1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(e_flags1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(e_width1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(e_many1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(E_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(all_empty1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(empty_format_and_params1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_char1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_char) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_string1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_string1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_dec1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_dec1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111onE_int1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_int) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_float1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_float1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_unsigned_dec) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_unsigned_dec) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_char1_with_alignment_left) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_char1_with_alignment_right) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_char_with_alignment) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

// START HEX TEST
START_TEST(test_111one_hex_lower) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_upper) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_lower) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_upper) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}

END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(test_111one_hex_lower_with_alignment_left) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_lower_with_alignment_right) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_upper_with_alignment_left) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_upper_with_alignment_right) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_lower_with_alignment) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_upper_with_alignment) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}

END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(test_111one_hex_with_hashtag) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_upper_with_hashtag) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}

END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(test_111one_hex_lower_with_width_star) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_upper_with_width_star) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_upper_with_width_star) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}

END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(test_111one_hex_lower_with_precision) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_upper_with_precision) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_lower_with_precision_and_other) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111many_hex_upper_with_precision_and_other) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}

END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(test_111one_hex_lower_with_length) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111one_hex_upper_with_length) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf2) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf3) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf4) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf6) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf7) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf8) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf9) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf10) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf12) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.16Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf14) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf15) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf16) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf17) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf18) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf19) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf20) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf24) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf25) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf28) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf29) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf30) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf31) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf32) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf33) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf35) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf36) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf37) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf38) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf39) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf40) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf41) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf42) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf43) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(test_111sprintf44) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(g_trailing_zero11) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(g_large1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_small1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_precision1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_precision1_zero) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_precision1_missing) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_many1_zeroes_in_front1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_one_zero1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_zero1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(g_mantiss1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_mantiss1_flags) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(g_short_no_mantiss1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST
START_TEST(LG1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(g_many1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}

END_TEST

START_TEST(width_char1) {
  char str1[BUFFEER_SIZE];
  char str2[BUFFEER_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

START_TEST(s21_sprintf_test_2_percent_option) {
  char a1[BUFFEER_SIZE] = {0};
  char aa1[BUFFEER_SIZE] = {0};
  int a = 10;
  char *format_str1 = "lenitive %%, %d";
  int res1 = s21_sprintf(a1, format_str1, a);
  int res_origin1 = sprintf(aa1, format_str1, a);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a1, aa1);

  char a2[BUFFEER_SIZE] = {0};
  char aa2[BUFFEER_SIZE] = {0};
  int b = -10;
  char *format_str2 = "Negative %%, %d";
  res1 = s21_sprintf(a2, format_str2, b);
  res_origin1 = sprintf(aa2, format_str2, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a2, aa2);

  char a3[BUFFEER_SIZE] = {0};
  char aa3[BUFFEER_SIZE] = {0};
  b = -100000, a = -1234556;
  char *format_str3 = "Negative %%, %d%d";
  res1 = s21_sprintf(a3, format_str3, b, a);
  res_origin1 = sprintf(aa3, format_str3, b, a);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a3, aa3);

  char a4[BUFFEER_SIZE] = {0};
  char aa4[BUFFEER_SIZE] = {0};
  const char *format_str4 = "%%, %d";
  res1 = s21_sprintf(a4, format_str4, a);
  res_origin1 = sprintf(aa4, format_str4, a);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a4, aa4);

  char a5[BUFFEER_SIZE] = {0};
  char aa5[BUFFEER_SIZE] = {0};
  a = 123456;
  b = -123456;
  const char *format_str5 = " *one, %% %+-010.0d % +-010.0d";
  res1 = s21_sprintf(a5, format_str5, a, b);
  res_origin1 = sprintf(aa5, format_str5, a, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a5, aa5);

  char a6[BUFFEER_SIZE] = {0};
  char aa6[BUFFEER_SIZE] = {0};

  const char *format_str6 = " *one %%%%%%%%%%%%%%, %%  %*.*d %*.*d";
  res1 = s21_sprintf(a6, format_str6, 5, 10, a, 7, 10, b);
  res_origin1 = sprintf(aa6, format_str6, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a6, aa6);
  //
  char a7[BUFFEER_SIZE] = {0};
  char aa7[BUFFEER_SIZE] = {0};

  const char *format_str7 = " *one %%%%%%%%%%%%%%, %%  [%*.*d] [%*.*d]";
  res1 = s21_sprintf(a7, format_str7, 5, 10, a, 7, 10, b);
  res_origin1 = sprintf(aa7, format_str7, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a7, aa7);

  char a8[BUFFEER_SIZE] = {0};
  char aa8[BUFFEER_SIZE] = {0};

  const char *format_str8 = " *one %%%%%%%%%%%%%%, %%  [% *.*d] [% *.*d]";
  res1 = s21_sprintf(a8, format_str8, 5, 10, a, 7, 10, b);
  res_origin1 = sprintf(aa8, format_str8, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a8, aa8);

  char a9[BUFFEER_SIZE] = {0};
  char aa9[BUFFEER_SIZE] = {0};

  const char *format_str9 = " *one %%%%%%%%%%%%%%, %%  [%   *.*d ] [%   *.*d]";
  res1 = s21_sprintf(a9, format_str9, 5, 10, a, 7, 10, b);
  res_origin1 = sprintf(aa9, format_str9, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a9, aa9);

  char a10[BUFFEER_SIZE] = {0};
  char aa10[BUFFEER_SIZE] = {0};
  a = 0;
  b = 0;
  const char *format_str10 =
      " *one %%%%%%%%%%%%%%, % %  [%   *.*d ] [%   *.*d] %%";
  res1 = s21_sprintf(a10, format_str10, 5, 10, a, 7, 10, b);
  res_origin1 = sprintf(aa10, format_str10, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a10, aa10);

  char a11[BUFFEER_SIZE] = {0};
  char aa11[BUFFEER_SIZE] = {0};
  a = 11;
  b = -11;
  const char *format_str11 =
      " *one %%%%%%%%%%%%%%, % %  [%   *.*d ] [%   *.*d] asd";
  res1 = s21_sprintf(a11, format_str11, 5, 10, a, 7, 10, b);
  res_origin1 = sprintf(aa11, format_str11, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a11, aa11);

  char a12[BUFFEER_SIZE] = {0};
  char aa12[BUFFEER_SIZE] = {0};
  a = 11123;
  b = -114456;
  const char *format_str12 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]Dota2";
  res1 = s21_sprintf(a12, format_str12, 10, 0, a, 10, 0, b);
  res_origin1 = sprintf(aa12, format_str12, 10, 0, a, 10, 0, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a12, aa12);
  char a13[BUFFEER_SIZE] = {0};
  char aa13[BUFFEER_SIZE] = {0};
  a = 11123;
  b = -114456;
  const char *format_str13 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]Dota2";
  res1 = s21_sprintf(a13, format_str13, 0, 0, a, 0, 0, b);
  res_origin1 = sprintf(aa13, format_str13, 0, 0, a, 0, 0, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a13, aa13);

  char a14[BUFFEER_SIZE] = {0};
  char aa14[BUFFEER_SIZE] = {0};
  a = 123456;
  b = -123456;
  const char *format_str14 = " *one, %% %+-00.0d % +-00.0d";
  res1 = s21_sprintf(a14, format_str14, a, b);
  res_origin1 = sprintf(aa14, format_str14, a, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a14, aa14);

  char a15[BUFFEER_SIZE] = {0};
  char aa15[BUFFEER_SIZE] = {0};
  a = 123456;
  b = -123456;
  const char *format_str15 = " *one, %% %+-00.0d %% % +-00.0d";
  res1 = s21_sprintf(a15, format_str15, a, b);
  res_origin1 = sprintf(aa15, format_str15, a, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a15, aa15);

  char a16[BUFFEER_SIZE] = {0};
  char aa16[BUFFEER_SIZE] = {0};
  a = 12345;
  b = 1234;
  const char *format_str16 = " *one, %% %+d %% %+d";
  res1 = s21_sprintf(a16, format_str16, a, b);
  res_origin1 = sprintf(aa16, format_str16, a, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a16, aa16);

  char a17[BUFFEER_SIZE] = {0};
  char aa17[BUFFEER_SIZE] = {0};
  a = 12345;
  b = 1234;
  const char *format_str17 = " *one, %% %- d %% % -d";
  res1 = s21_sprintf(a17, format_str17, a, b);
  res_origin1 = sprintf(aa17, format_str17, a, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a17, aa17);

  char a18[BUFFEER_SIZE] = {0};
  char aa18[BUFFEER_SIZE] = {0};
  a = -12345;
  b = -1234;
  const char *format_str18 = " *one, %% %- d %% % -d, 12345";
  res1 = s21_sprintf(a18, format_str18, a, b);
  res_origin1 = sprintf(aa18, format_str18, a, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a18, aa18);

  char a19[BUFFEER_SIZE] = {0};
  char aa19[BUFFEER_SIZE] = {0};
  a = 11123;
  b = -114456;
  const char *format_str19 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  res1 = s21_sprintf(a19, format_str19, -11, 12, a, 12, -11, b);
  res_origin1 = sprintf(aa19, format_str19, -11, 12, a, 12, -11, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a19, aa19);

  char a20[BUFFEER_SIZE] = {0};
  char aa20[BUFFEER_SIZE] = {0};
  a = -11123;
  b = 114456;
  const char *format_str20 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  res1 = s21_sprintf(a20, format_str20, -11, 0, a, 0, -11, b);
  res_origin1 = sprintf(aa20, format_str20, -11, 0, a, 0, -11, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a20, aa20);

  char a21[BUFFEER_SIZE] = {0};
  char aa21[BUFFEER_SIZE] = {0};
  a = -11123;
  b = 114456;
  const char *format_str21 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  res1 = s21_sprintf(a21, format_str21, 0, -11, a, -11, 0, b);
  res_origin1 = sprintf(aa21, format_str21, 0, -11, a, -11, 0, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a21, aa21);

  char a22[BUFFEER_SIZE] = {0};
  char aa22[BUFFEER_SIZE] = {0};
  a = -1113;
  b = -4456;
  const char *format_str22 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  res1 = s21_sprintf(a22, format_str22, -11, -11, a, -11, -11, b);
  res_origin1 = sprintf(aa22, format_str22, -11, -11, a, -11, -11, b);
  ck_assert_int_eq(res1, res_origin1);
  ck_assert_str_eq(a22, aa22);
}

END_TEST

Suite *

sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sprintf");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_sprintf_test1);
  tcase_add_test(tc_core, s21_sprintf_test2);
  tcase_add_test(tc_core, s21_sprintf_test3);
  tcase_add_test(tc_core, s21_sprintf_test4);
  tcase_add_test(tc_core, s21_sprintf_test5);
  tcase_add_test(tc_core, s21_sprintf_test6);
  tcase_add_test(tc_core, s21_sprintf_test7);
  tcase_add_test(tc_core, s21_sprintf_test8);
  tcase_add_test(tc_core, s21_sprintf_test9);
  tcase_add_test(tc_core, s21_sprintf_test10);
  tcase_add_test(tc_core, s21_sprintf_test11);
  tcase_add_test(tc_core, s21_sprintf_test12);
  tcase_add_test(tc_core, s21_sprintf_test13);
  tcase_add_test(tc_core, s21_sprintf_test14);
  tcase_add_test(tc_core, s21_sprintf_test15);
  tcase_add_test(tc_core, s21_sprintf_test16);
  tcase_add_test(tc_core, s21_sprintf_test17);
  tcase_add_test(tc_core, s21_sprintf_test18);
  tcase_add_test(tc_core, s21_sprintf_test19);
  tcase_add_test(tc_core, s21_sprintf_test20);
  tcase_add_test(tc_core, s21_sprintf_test21);
  tcase_add_test(tc_core, s21_sprintf_test22);
  tcase_add_test(tc_core, s21_sprintf_test23);
  tcase_add_test(tc_core, s21_sprintf_test24);
  tcase_add_test(tc_core, s21_sprintf_test25);
  tcase_add_test(tc_core, s21_sprintf_test26);
  tcase_add_test(tc_core, s21_sprintf_test27);
  tcase_add_test(tc_core, s21_sprintf_test28);
  tcase_add_test(tc_core, s21_sprintf_test29);
  tcase_add_test(tc_core, s21_sprintf_test30);
  tcase_add_test(tc_core, s21_sprintf_test31);
  tcase_add_test(tc_core, s21_sprintf_test32);
  tcase_add_test(tc_core, s21_sprintf_test33);
  tcase_add_test(tc_core, s21_sprintf_test34);
  tcase_add_test(tc_core, s21_sprintf_test35);
  tcase_add_test(tc_core, s21_sprintf_test36);
  tcase_add_test(tc_core, s21_sprintf_test37);
  tcase_add_test(tc_core, s21_sprintf_test38);
  tcase_add_test(tc_core, s21_sprintf_test39);
  tcase_add_test(tc_core, s21_sprintf_test40);
  tcase_add_test(tc_core, s21_sprintf_test41);
  tcase_add_test(tc_core, s21_sprintf_test42);
  tcase_add_test(tc_core, s21_sprintf_test43);
  tcase_add_test(tc_core, s21_sprintf_test44);
  tcase_add_test(tc_core, s21_sprintf_test45);
  tcase_add_test(tc_core, s21_sprintf_test46);
  tcase_add_test(tc_core, s21_sprintf_test47);
  tcase_add_test(tc_core, s21_sprintf_test48);
  tcase_add_test(tc_core, s21_sprintf_test49);
  tcase_add_test(tc_core, s21_sprintf_test50);
  tcase_add_test(tc_core, s21_sprintf_test51);
  tcase_add_test(tc_core, s21_sprintf_test52);
  tcase_add_test(tc_core, s21_sprintf_test53);
  tcase_add_test(tc_core, s21_sprintf_test54);
  tcase_add_test(tc_core, s21_sprintf_test55);
  tcase_add_test(tc_core, s21_sprintf_test56);
  tcase_add_test(tc_core, s21_sprintf_test57);
  tcase_add_test(tc_core, s21_sprintf_test58);
  tcase_add_test(tc_core, s21_sprintf_test59);
  tcase_add_test(tc_core, s21_sprintf_test60);
  tcase_add_test(tc_core, s21_sprintf_test61);
  tcase_add_test(tc_core, s21_sprintf_test62);

  tcase_add_test(tc_core, simplE_int11);
  tcase_add_test(tc_core, precisE_int11);
  tcase_add_test(tc_core, width_int1);
  tcase_add_test(tc_core, minus_width_int1);
  tcase_add_test(tc_core, plus_width_int1);
  tcase_add_test(tc_core, padding_int1);
  tcase_add_test(tc_core, star_width_int1);
  tcase_add_test(tc_core, star_precision_int1);
  tcase_add_test(tc_core, many_flags_many_ints1);
  tcase_add_test(tc_core, flags_long_int1);
  tcase_add_test(tc_core, flags_short_int1);
  tcase_add_test(tc_core, flags_another_long_int1);
  tcase_add_test(tc_core, zero_precision_zero_int1);
  tcase_add_test(tc_core, space_flag_int1);
  tcase_add_test(tc_core, unsigned_val1);
  tcase_add_test(tc_core, unsigned_val1_width);
  tcase_add_test(tc_core, unsigned_val1_flags);
  tcase_add_test(tc_core, unsigned_val1_precision);
  tcase_add_test(tc_core, unsigned_val1_many_flags);
  tcase_add_test(tc_core, unsigned_val1_short);
  tcase_add_test(tc_core, unsigned_val1_long);
  tcase_add_test(tc_core, unsigned_val1_many);
  tcase_add_test(tc_core, octal1);
  tcase_add_test(tc_core, octal1_width1);
  tcase_add_test(tc_core, octal1_flags1);
  tcase_add_test(tc_core, octal1_precision1);
  tcase_add_test(tc_core, octal1_many_flags);
  tcase_add_test(tc_core, octal1_short);
  tcase_add_test(tc_core, octal1_long);
  tcase_add_test(tc_core, octal1_zero);
  tcase_add_test(tc_core, octal1_hash);
  tcase_add_test(tc_core, unsigned_zero1);
  tcase_add_test(tc_core, hex_width1);
  tcase_add_test(tc_core, hex_flags1);
  tcase_add_test(tc_core, hex_precision1);
  tcase_add_test(tc_core, hex_many1);
  tcase_add_test(tc_core, hex_many1_flags);
  tcase_add_test(tc_core, hex_zero1);
  tcase_add_test(tc_core, hex_huge1);
  tcase_add_test(tc_core, hex_short1);
  tcase_add_test(tc_core, hex_long1);
  tcase_add_test(tc_core, hex_one_longer_width1);
  tcase_add_test(tc_core, hex_two_longer_width1);
  tcase_add_test(tc_core, one_char1);
  tcase_add_test(tc_core, one_precision11);
  tcase_add_test(tc_core, one_flags11);
  tcase_add_test(tc_core, one_width11);
  tcase_add_test(tc_core, one_many11);
  tcase_add_test(tc_core, one_many11_flags);
  tcase_add_test(tc_core, string1);
  tcase_add_test(tc_core, string1_precision);
  tcase_add_test(tc_core, string1_width);
  tcase_add_test(tc_core, string1_flags);
  tcase_add_test(tc_core, string1_long);
  tcase_add_test(tc_core, string1_many);
  tcase_add_test(tc_core, ptr1);
  tcase_add_test(tc_core, ptr1_width);
  tcase_add_test(tc_core, ptr1_precision);
  tcase_add_test(tc_core, null_ptr1);
  tcase_add_test(tc_core, string1_width_huge);
  tcase_add_test(tc_core, float_precision1);
  tcase_add_test(tc_core, float_width1);
  tcase_add_test(tc_core, float_precision1_zero);
  tcase_add_test(tc_core, float_precision1_empty);
  tcase_add_test(tc_core, float_precision1_huge);
  tcase_add_test(tc_core, float_precision1_huge_negative);
  tcase_add_test(tc_core, float_huge1);
  tcase_add_test(tc_core, float_flags1);
  tcase_add_test(tc_core, float_many1);
  tcase_add_test(tc_core, e_precision1);
  tcase_add_test(tc_core, e_precision1_zero);
  tcase_add_test(tc_core, e_precision1_empty);
  tcase_add_test(tc_core, e_precision1_huge);
  tcase_add_test(tc_core, e_precision1_huge_negative);
  tcase_add_test(tc_core, e_huge1);
  tcase_add_test(tc_core, e_many1);
  tcase_add_test(tc_core, e_width1);
  tcase_add_test(tc_core, e_flags1);
  tcase_add_test(tc_core, E_int1);
  tcase_add_test(tc_core, all_empty1);
  tcase_add_test(tc_core, empty_format_and_params1);
  tcase_add_test(tc_core, test_111one_char1);
  tcase_add_test(tc_core, test_111many_char);
  tcase_add_test(tc_core, test_111one_string1);
  tcase_add_test(tc_core, test_111many_string1);
  tcase_add_test(tc_core, test_111one_dec1);
  tcase_add_test(tc_core, test_111many_dec1);
  tcase_add_test(tc_core, test_111onE_int1);
  tcase_add_test(tc_core, test_111many_int);
  tcase_add_test(tc_core, test_111one_float1);
  tcase_add_test(tc_core, test_111many_float1);
  tcase_add_test(tc_core, test_111one_unsigned_dec);
  tcase_add_test(tc_core, test_111many_unsigned_dec);
  tcase_add_test(tc_core, test_111one_char1_with_alignment_left);
  tcase_add_test(tc_core, test_111one_char1_with_alignment_right);
  tcase_add_test(tc_core, test_111many_char_with_alignment);
  tcase_add_test(tc_core, test_111one_hex_lower);
  tcase_add_test(tc_core, test_111one_hex_upper);
  tcase_add_test(tc_core, test_111many_hex_lower);
  tcase_add_test(tc_core, test_111many_hex_upper);
  tcase_add_test(tc_core, test_111one_hex_lower_with_alignment_left);
  tcase_add_test(tc_core, test_111one_hex_lower_with_alignment_right);
  tcase_add_test(tc_core, test_111one_hex_upper_with_alignment_left);
  tcase_add_test(tc_core, test_111one_hex_upper_with_alignment_right);
  tcase_add_test(tc_core, test_111many_hex_lower_with_alignment);
  tcase_add_test(tc_core, test_111many_hex_upper_with_alignment);
  tcase_add_test(tc_core, test_111one_hex_with_hashtag);
  tcase_add_test(tc_core, test_111one_hex_upper_with_hashtag);
  tcase_add_test(tc_core, test_111many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc_core, test_111many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc_core, test_111one_hex_lower_with_width_star);
  tcase_add_test(tc_core, test_111one_hex_upper_with_width_star);
  tcase_add_test(tc_core,
                 test_111many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc_core, test_111many_hex_upper_with_width_star);
  tcase_add_test(tc_core, test_111one_hex_lower_with_precision);
  tcase_add_test(tc_core, test_111one_hex_upper_with_precision);
  tcase_add_test(tc_core, test_111many_hex_lower_with_precision_and_other);
  tcase_add_test(tc_core, test_111many_hex_upper_with_precision_and_other);
  tcase_add_test(tc_core, test_111one_hex_lower_with_length);
  tcase_add_test(tc_core, test_111one_hex_upper_with_length);
  tcase_add_test(tc_core, test_111sprintf1);
  tcase_add_test(tc_core, test_111sprintf2);
  tcase_add_test(tc_core, test_111sprintf3);
  tcase_add_test(tc_core, test_111sprintf4);
  tcase_add_test(tc_core, test_111sprintf6);
  tcase_add_test(tc_core, test_111sprintf7);
  tcase_add_test(tc_core, test_111sprintf8);
  tcase_add_test(tc_core, test_111sprintf9);
  tcase_add_test(tc_core, test_111sprintf10);
  tcase_add_test(tc_core, test_111sprintf11);
  tcase_add_test(tc_core, test_111sprintf12);
  tcase_add_test(tc_core, test_111sprintf14);
  tcase_add_test(tc_core, test_111sprintf15);
  tcase_add_test(tc_core, test_111sprintf16);
  tcase_add_test(tc_core, test_111sprintf17);
  tcase_add_test(tc_core, test_111sprintf18);
  tcase_add_test(tc_core, test_111sprintf19);
  tcase_add_test(tc_core, test_111sprintf20);
  tcase_add_test(tc_core, test_111sprintf24);
  tcase_add_test(tc_core, test_111sprintf25);
  tcase_add_test(tc_core, test_111sprintf28);
  tcase_add_test(tc_core, test_111sprintf29);
  tcase_add_test(tc_core, test_111sprintf30);
  tcase_add_test(tc_core, test_111sprintf31);
  tcase_add_test(tc_core, test_111sprintf32);
  tcase_add_test(tc_core, test_111sprintf33);
  tcase_add_test(tc_core, test_111sprintf35);
  tcase_add_test(tc_core, test_111sprintf36);
  tcase_add_test(tc_core, test_111sprintf37);
  tcase_add_test(tc_core, test_111sprintf38);
  tcase_add_test(tc_core, test_111sprintf39);
  tcase_add_test(tc_core, test_111sprintf40);
  tcase_add_test(tc_core, test_111sprintf41);
  tcase_add_test(tc_core, test_111sprintf42);
  tcase_add_test(tc_core, test_111sprintf43);
  tcase_add_test(tc_core, test_111sprintf44);
  tcase_add_test(tc_core, g_trailing_zero11);
  tcase_add_test(tc_core, g_large1);
  tcase_add_test(tc_core, g_small1);
  tcase_add_test(tc_core, g_precision1);
  tcase_add_test(tc_core, g_precision1_zero);
  tcase_add_test(tc_core, g_precision1_missing);
  tcase_add_test(tc_core, g_many1_zeroes_in_front1);
  tcase_add_test(tc_core, g_one_zero1);
  tcase_add_test(tc_core, g_mantiss1);
  tcase_add_test(tc_core, g_mantiss1_flags);
  tcase_add_test(tc_core, g_short_no_mantiss1);
  tcase_add_test(tc_core, LG1);
  tcase_add_test(tc_core, g_many1);
  tcase_add_test(tc_core, g_zero1);
  tcase_add_test(tc_core, width_char1);
  tcase_add_test(tc_core, octal1_many);
  tcase_add_test(tc_core, s21_sprintf_test_2_percent_option);
  tcase_add_test(tc_core, n_specifier1);
  suite_add_tcase(s, tc_core);
  return s;
}
