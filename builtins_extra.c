#include "shell_head.h"
#include "shell_builtins.h"

int builtin_help(int ac, char **cmd, __attribute__((unused)) char **env) {
  print_string("***Still under construction***\n");
  if(ac > 1) {
    print_string(cmd[1]);
  }
  return (0);
}
