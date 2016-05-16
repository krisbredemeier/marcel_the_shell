#include "shell_head.h"
#include "shell_builtins.h"

/*
* check_builtin() recieves a string vector, and checks if the first element matches the
* name of any builtin commands. If found, it will execute the match's
* respective function and return
* the result of that function. If not found, it will return (-1).
*/
int check_builtins(int ac, char **cmd, char **env)
{
        int i;
        builtin_f exec_builtin;

        char *builtins_v[] = {
                "exit",
                "cd",
                "env",
                "help",
                NULL
        };

        builtin_f builtins_f_v[] = {
                &builtin_exit,
                &builtin_cd,
                &builtin_env,
                &builtin_help,
                NULL
        };

        for (i = 0; builtins_v[i] != NULL; i++) {
                if ((string_compare(cmd[0], builtins_v[i])) == 0) {
                        exec_builtin = builtins_f_v[i];
                        return (exec_builtin(ac, cmd, env));
                }
        }

        return (-1);
}

char **check_builtins_env(int ac, char **cmd, char **env)
{
        int i;
        builtin_f_env execute_builtin_env;

        char *builtins_v_env[] = {
                "setenv",
                "unsetenv",
                NULL
        };

        builtin_f_env builtins_f_v_env[] = {
                &builtin_setenv,
                &builtin_unsetenv,
                NULL
        };

        for (i = 0; builtins_v_env[i] != NULL; i++) {
                if ((string_compare(cmd[0], builtins_v_env[i])) == 0) {
                        execute_builtin_env = builtins_f_v_env[i];
                        return (execute_builtin_env(ac, cmd, env));
                }
        }

        return NULL;
}
