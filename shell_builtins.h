/* built-in prototypes for marcel_the_shell shell */
typedef int (*builtin_f)(int, char **, char **);
typedef char **(*builtin_f_env)(int, char **, char **);

int builtin_exit(int, char **, char **);
int builtin_cd(int, char **, char **);
int builtin_env(int, char **, char **);

char **builtin_setenv(int, char **, char **);
char **builtin_unsetenv(int, char **, char **);

int builtin_help(int, char **, char **);
