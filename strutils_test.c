#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutils.h"

void test(char s[], const char *expected) {
  const char *status = (strcmp(s, expected) == 0 ? "\033[0;32msuccessful\033[0m" : "\033[0;31mfailed\033[0m");
  printf("Test %s.\n", status);
  printf("Expected: \"%s\"\n", expected);
  printf("Actual: \"%s\"\n", s);
}

void test_to_lower() {
  char s1[] = "AAA";
  const char *expect1 = "aaa";
  to_lower(s1);
  test(s1, expect1);
}

void test_to_upper() {
  char s1[] = "aaa";
  const char *expect1 = "AAA";
  to_upper(s1);
  test(s1, expect1);
}


void test_trim_whitespace() {
  char s1[] = "   foo";
  const char *expect1 = "foo";
  trim_whitespace(s1, false);
  test(s1, expect1);
  
  char s2[] = "";
  const char *expect2 = "";
  trim_whitespace(s2, false);
  test(s2, expect2);
  
  char s3[] = "  21 text";
  const char *expect3 = "21 text";
  trim_whitespace(s3, false);
  test(s3, expect3);
  
  char s4[] = "foo        ";
  const char *expect4 = "foo";
  trim_whitespace(s4, true);
  test(s4, expect4);
  
  char s5[] = "          21 text        ";
  const char *expect5 = "21 text";
  trim_whitespace(s5, true);
  test(s5, expect5);
}

void test_reverse() {
  char s1[] = "abcd";
  const char *expect1 = "dcba";
  reverse(s1);
  test(s1, expect1);
  
  char s2[] = "  a";
  const char *expect2 = "a  ";
  reverse(s2);
  test(s2, expect2);
  
  char s3[] = "";
  const char *expect3 = "";
  reverse(s3);
  test(s3, expect3);

  char s4[] = "a";
  const char *expect4 = "a";
  reverse(s4);
  test(s4, expect4);

}

void test_replace() {
  char s1[] = "AAAA";
  const char *expect1 = "BBBB";
  replace(s1, 'A', 'B');
  test(s1, expect1);
}

void test_remove() {
  char s1[] = "BAAAA";
  const char *expect1 = "AAAA";
  remove_char(s1, 'B');
  test(s1, expect1);
  
  char s2[] = "@";
  const char *expect2 = "";
  remove_char(s2, '@');
  test(s2, expect2);
}

int main(int argc, char *argv[]) {
  test_trim_whitespace();
  test_reverse();
  test_to_lower();
  test_to_upper();
  test_replace();
  test_remove();
  return EXIT_SUCCESS;
}
