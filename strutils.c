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
    int ch = (int)(str[i]);
    if (ch >= 65 && ch <= 90) {
      str[i] = (char)(ch + 32);
    }
  }
}

/*
 * Modifies passed string by uppercasing it.
 */
void to_upper(char str[]) {
  if (strlen(str) < 1) return;
  for (int i=0;i<strlen(str);i++) {
    int ch = (int)(str[i]);
    if (ch >= 97 && ch <= 122) {
      str[i] = (char)(ch - 32);
    }
  }
}

void replace(char str[], char find, char replace) {
  char *current_pos = strchr(str,find);
  while (current_pos) {
    *current_pos = replace;
    current_pos = strchr(current_pos, find);
  }
}

void remove_char(char str[], char c)
{
  int j, n = strlen(str);
  for (int i = j = 0; i < n; i++)
      if (str[i] != c) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}
