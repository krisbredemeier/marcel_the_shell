/*header files for marcel_the_shell*/ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define TRUE 1
#define FALSE 0

char *read_line(int);
void copy_string(char *, char *, int);

char **string_split(char *, char);
int count_chars(char *, char);
int count_words(char *, char);

int execute_command(char **, char **);
char *append_insert_replace(char *, char *, char);

char *search_and_rescue(char *, char **);
char **get_variable(char *, char **);
char *find_command(char *, char **);
void free_str_arr(char **);

void sig_handle_ctl_c(int);

int string_compare(char *, char *);
int check_builtins(int, char **, char **);
char **check_builtins_env(int, char **, char **);

char **copy_vector(char **);
char **remove_from_vector(char **, char **);
char **add_to_vector(char *, char **);

/* helper functions */
int print_char(char);
void print_string(char *);
int char_is_char(char);
int char_is_num(char);
void cut_string(char*, int, char*);
int make_number(char*, int, int);
int expon(int);
int string_to_integer(char *);
