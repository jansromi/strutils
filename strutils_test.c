#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutils.h"

void test(char s[], char expected[]) {
  const char *status = (strcmp(s, expected) == 0 ? "\033[0;32msuccessful\033[0m" : "\033[0;31mfailed\033[0m");
  printf("Test %s.\n", status);
  printf("Expected: \"%s\"\n", expected);
  printf("Actual: \"%s\"\n", s);
}

void test_trim_whitespace() {
  char s1[] = "   foo";
  char expect1[] = "foo";
  trim_whitespace(s1, strlen(s1), false);
  test(s1, expect1);
  
  char s2[] = "";
  char expect2[] = "";
  trim_whitespace(s2, strlen(s2), false);
  test(s2, expect2);
  
  char s3[] = "  21 text";
  char expect3[] = "21 text";
  trim_whitespace(s3, strlen(s3), false);
  test(s3, expect3);
  
  char s4[] = "foo        ";
  char expect4[] = "foo";
  trim_whitespace(s4, strlen(s4), true);
  test(s4, expect4);
  
  char s5[] = "          21 text        ";
  char expect5[] = "21 text";
  trim_whitespace(s5, strlen(s5), true);
  test(s5, expect5);
}

void test_reverse() {
  char s1[] = "abcd";
  char expect1[] = "dcba";
  reverse(s1, strlen(s1));
  test(s1, expect1);
  
  char s2[] = "  a";
  char expect2[] = "a  ";
  reverse(s2, strlen(s2));
  test(s2, expect2);
  
  char s3[] = "";
  char expect3[] = "";
  reverse(s3, strlen(s3));
  test(s3, expect3);

  char s4[] = "a";
  char expect4[] = "a";
  reverse(s4, strlen(s4));
  test(s4, expect4);

}



int main(int argc, char *argv[]) {
  test_trim_whitespace();
  test_reverse();
  return EXIT_SUCCESS;
}
