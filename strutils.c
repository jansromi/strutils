#include <ctype.h>
#include <stdbool.h>
#include "strutils.h"

void trim_whitespace_lead(char str[], int len) {
    if (len <= 0) return;
    int i = 0;
    int j = 0;
    while (i < len && isspace(str[i])) {
        i++;
    }
    while (i < len && str[i] != '\0') {
        str[j++] = str[i++];
    }
    str[j] = '\0';
}

void trim_whitespace_tail(char str[], int len) {
    if (len <= 0) return;
    int i = len - 1;
    while (i >= 0 && (isspace((unsigned char)str[i]) || str[i] == '\0')) {
        i--;
    }
    str[i + 1] = '\0';
}

/*
 * Modifies passed string by trimming leading whitespaces.
 *
 * If specicied, trims also tailing whitespace.
 */
void trim_whitespace(char str[], int len, bool tail) {
  if (tail) {
    trim_whitespace_tail(str, len);
  }
  trim_whitespace_lead(str, len);
}

/*
 * Modifies passed string by reversing it.
 */
void reverse(char str[], int len) {
  if (len <= 1) return;
  int i = 0;
  int j = len - 1;

  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

