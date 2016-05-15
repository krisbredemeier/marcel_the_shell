#include "shell_head.h"
#include "shell_builtins.h"

int builtin_exit(int ac, char **cmd, __attribute__((unused)) char **env) {
  int i;
  char *check;

  if (ac == 1) {
    free_str_arr(env);
    free_str_arr(cmd);
    exit(0);
  }
  if (ac > 2) {
    print_string("'exit' takes only one argument\n");
    return (1);
  }
  check = cmd[1];
  for (i = 0; check[i] != '\0'; i++) {
    if (char_is_num(check[i])) {
      print_string("Argument must be a number\n");
      return (1);
    }
  }

  i = string_to_integer(cmd[1]);
  free_str_arr(env);
  free_str_arr(cmd);
  exit(i);  
}

int builtin_cd(int ac, char **cmd, __attribute__((unused)) char **env) {
  print_string("***Still under construction***\n");
  if(ac == 2) {
    print_string(cmd[1]);
  }
  return (0);
}

int builtin_env(int ac,__attribute__((unused)) char **cmd, char **env) {
  int i;

  if(ac > 1) {
    print_string("'env' takes no arguments\n");
    return (1);
  }
  for (i = 0; env[i] != NULL; i++) {
    print_string(env[i]);
    print_char('\n');
  }
  
  return (0);
}

char **builtin_setenv(int ac, char **cmd, char **env) {
  char *new, **target;
  if(ac > 3) {
    print_string("'setenv' takes only two arguments\n");
    return NULL;
  }
  if(ac == 2 || ac == 1) {
    print_string("'setenv' needs two arguments\n");
    return NULL;
  }
  
  if((target = get_variable(cmd[1], env)) == NULL) {
    new = append_insert_replace(cmd[2], cmd[1], '=');
    target = add_to_vector(new, env);
    free_str_arr(env);
    print_string("Run 'env' to see your changes\n");
    return target;
  }
  else {
    new = append_insert_replace(cmd[2], cmd[1], '=');
    free(*target);
    *target = new;
    print_string("Run 'env' to see your changes\n");
    return env;
  }
		       
  return env;
}

char **builtin_unsetenv(int ac, char **cmd, char **env) {
  char **target;
  char **new_env;

  if(ac > 2) {
    print_string("'unsetenv' takes only one argument\n");
    return NULL;
  }
  if(ac == 1) {
    print_string("'unsetenv' needs one argument\n");
    return NULL;
  }
  
  target = get_variable(cmd[1], env);
  new_env = remove_from_vector(target, env);
  free_str_arr(env);
  print_string("Run 'env' to see your changes\n");
  return (new_env);
}
