#include "shell_head.h"

/* string_split() takes a string and places all the
   words into an array of strings. */
char **string_split(char *s, char seperator) {
  int i, i2, i3;
  char **ss;
  char *t;
  i = count_words(s, seperator);
  ss = malloc(sizeof(char *) * (i + 1));
  if (ss == NULL) {
    return NULL;
  }

  i2 = 0;
  i3 = 0;
  while(i2 < i) {
    if (s[i3] != seperator && s[i3] != '\0') {
      /* allocate enough space for entire word */
      ss[i2] = malloc(sizeof(char) * (count_chars(&(s[i3]), seperator) + 1));
      if (ss[i2] == NULL) {
        return NULL;
      }

      t = ss[i2];
      while(s[i3] != seperator && s[i3] != '\0') {
        *t++ = s[i3];
 	i3++;
      }
      *t = '\0';
      while(s[i3] == seperator && s[i3] != '\0') {
        i3++;
      }
      i2++;
    }
    else {
      i3++;
    }
  }

  ss[i] = NULL;
  return ss;
}

/* count_chars() counts how many chars are in a string */
int count_chars(char *s1, char seperator) {
  int i;

  i = 0;
  while(*s1 != seperator && *s1 != '\0') {
    s1++;
    i++;
  }

  return i;
}

/* count_words() counts how many words are in a string. A word must contain
   alphanumerical symbols only. */
int count_words(char *s, char seperator) {
  int i;

  i = 0;
  while(*s != '\0') {
    if (*s != seperator) {
      i++;
    }
    while(*s != seperator && *s != '\0') {
      s++;
    }
    while(*s == seperator && *s != '\0') {
      s++;
    }
  }
  return i;
}
