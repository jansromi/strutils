#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "strutils.h"

void trim_whitespace_lead(char str[]) {
    if (strlen(str) < 1) return;
    int i = 0;
    int j = 0;
    while (i < strlen(str) && isspace(str[i])) {
        i++;
    }
    while (i < strlen(str) && str[i] != '\0') {
        str[j++] = str[i++];
    }
    str[j] = '\0';
}

void trim_whitespace_tail(char str[]) {
    if (strlen(str) < 1) return;
    int i = strlen(str) - 1;
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
void trim_whitespace(char str[], bool tail) {
  if (tail) {
    trim_whitespace_tail(str);
  }
  trim_whitespace_lead(str);
}

/*
 * Modifies passed string by reversing it.
 */
void reverse(char str[]) {
  if (strlen(str) < 2) return;
  int i = 0;
  int j = strlen(str) - 1;

  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

/*
 * Modifies passed string by lowercasing it.
 */
void to_lower(char str[]) {
  if (strlen(str) < 1) return;
  for (int i=0;i<strlen(str);i++) {
    int temp = (int)(str[i]);
    if (temp >= 65 && temp <= 90) {
      str[i] = (char)(temp + 32);
    }
  }
}

/*
 * TODO
 */
void to_upper() {

}
