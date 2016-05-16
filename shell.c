#include "shell_head.h"

/*
* main function of marcel_the_shell -
* reads the user input, checks for builtins,
* checks for builtin environmentals,
* and attempts to execute command
*/
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, char **env)
{
        char **shell_cmd;
        char *input;
        int error;
        int shell_ac;
        char **shell_env;
        char **check;

        shell_env = copy_vector(env);

        signal(SIGINT, sig_handle_ctl_c);

        while(TRUE) {
                input = read_line(0);
                if((error = pre_process_comments(input)) == 1) {
                        free(input);
                        continue;
                }
                shell_ac = count_words(input, ' ');
                shell_cmd = string_split(input, ' ');
                free(input);

                if((error = check_builtins(shell_ac, shell_cmd, shell_env)) != -1) {
                        free_str_arr(shell_cmd);
                        continue;
                }

                if((check = check_builtins_env(shell_ac, shell_cmd, shell_env)) != NULL) {
                        shell_env = check;
                        free_str_arr(shell_cmd);
                        continue;
                }

                if((error = execute_command(shell_cmd, shell_env)) == EXIT_FAILURE) {
                        free_str_arr(shell_env);
                        free_str_arr(shell_cmd);
                        exit(error);
                }
                free_str_arr(shell_cmd);
        }

        exit(0);
}

/*
* this function is a way to handle ctl_c.
* If ctl_c is tryped into the shell
* you are prompted to type 'exit' to quit
*/
void sig_handle_ctl_c(int sign)
{
        char prompt[] = ">>> ";

        signal(sign, SIG_IGN);
        write(1 , "\nPlease type 'exit' to quit.\n", 29);
        write(1, prompt, 4);
        signal(SIGINT, sig_handle_ctl_c);
}
