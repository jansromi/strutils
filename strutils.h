#ifndef STRUTILS_H_
#define STRUTILS_H_

void trim_whitespace(char str[], bool tail);
void reverse(char str[]);
void to_lower(char str[]);
void to_upper(char str[]);
void replace(char str[], char find, char replace);
void remove_char(char str[], char c);
#endif // !STRUTILS_H_
