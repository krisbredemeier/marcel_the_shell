#include "shell_head.h"
#include "shell_builtins.h"

/*
*still under consturtion, once instituted the help built in
*will help direct the user if the need be
*/
int builtin_help(int ac, char **cmd, __attribute__((unused)) char **env)
{
        print_string("***Still under construction***\n");
        if(ac > 1) {
                print_string(cmd[1]);
        }
        return (0);
}
