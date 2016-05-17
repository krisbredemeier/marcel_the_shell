#include "shell_head.h"
#include "shell_builtins.h"

int print_char(char c)
{
        return (write(1, &c, 1));
}

/*
 * prints a number using division and the modulus operator
 * it prins each char one by one
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
