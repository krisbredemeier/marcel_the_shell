#include "shell_head.h"
#include "shell_builtins.h"

int print_char(char c)
{
  return (write(1, &c, 1));
}

/*
 *[print_number] TAKES AN INT, DIVIDES IT BY 10 AS MANY TIMES AS IT CAN TO
 *DETERMINE HOW MANY DIGITS IT CONTAINS, AND THEN CONVERTS EACH DIGIT TO A SINGLE
 *CHAR BY USING THE MODULUS OPERATOR AND ADDING THIS VALUE TO THE CHAR '0'. FINALLY
 *THIS CHAR IS PASSED TO THE [print_char] FUNCTION.
 */
void print_number(int n) 
{
  int i = 1;
  int temp;
  int mod = 1;
  if (n < 0) {
    print_char('-');
    mod = -1;
  }
  for(temp = n; temp > 9 || temp < -9; temp = temp / 10) {
    i++;
  }
  while(i) {
    int i2 = i--;
    temp = n;
    while(i2-- > 1) {
      temp /= 10;
    }
    print_char(((temp % 10) * mod + '0'));
  }
}

void print_string(char *str) 
{
  while (*str) {
    print_char(*str++);
  }
}

int char_is_char(char c) 
{
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return (0);
  }
  else {
    return (1);
  }
}

int char_is_num(char c) 
{
  if (c >= 48 && c <= 57) {
    return (0);
  }
  else {
    return (1);
  }
}
