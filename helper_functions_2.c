/*these functions are helper functions*/
#include "shell_head.h"
#include "shell_builtins.h"

int string_to_integer(char *s) {
  int size, answer, mod;
  char newString[11];

  answer = 0;
  mod = 0;

  while (*s && (*s < '0' || *s > '9')) {
    if (*s == '-') {
      mod++;
    }
    s++;
  }
  if (mod % 2) {
    mod = -1;
  }
  else {
    mod = 1;
  }

  for (size = 0; s[size] >= '0' && s[size] <= '9'; size++) {
  }

  if (size > 10) {
    return 0;
  }

  cut_string(s, size, newString);
  answer = make_number(newString, size, mod);

  return answer;
}


void cut_string(char *s, int size, char *newString) {
  int ndx;

  for (ndx = 0; ndx < size; ndx++) {
    newString[ndx] = s[ndx];
  }

  newString[ndx] = '\0';
}

int make_number(char *newString, int size, int mod) {
  int number, ndx;

  number = 0;

  size--;

  for (ndx = 0; ndx <= size; ndx++) {
    number += ((newString[size - ndx] - '0') * expon(ndx));
  }

  number *= mod;
  if ((mod == 1 && number > 0) || (mod == -1 && number < 0)) {
    return number;
  }

  return 0;
}

int expon(int n) {
  int x;

  x = 1;

  while (n--) {
    x *= 10;
  }
  return x;
}

int string_compare(char *str1, char *str2) {
  int i;
  for(i = 0; str1[i] == str2[i] && str1[i] && str2[i]; i++) {}
  if (str1[i] == '\0' && str2[i] == '\0') {
    return (0);
  }
  else {
    return (1);
  }
}
