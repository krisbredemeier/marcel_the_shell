#include "shell_head.h"
#include "shell_builtins.h"

/* creates a built in exit command */
int builtin_exit(int ac, char **cmd, __attribute__((unused)) char **env)
{
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

/* builtin change directory function */
int builtin_cd(int ac, char **cmd, char **env)
{
  char *pre, *post;
        if (ac > 2) {
                print_string("'cd' takes only up to one argument\n");
                return(1);
        }

	/* if (string_compare(cmd[1], "-") == 0) { */
     	/*         chdir(result = search_and_rescue("OLDPWD", env)); */
	/* 	update_dir(result, env); */
	/* 	return (0); */
      
	/* } */
        if (ac == 2) {
                if (chdir(cmd[1]) != 0) {
                        perror("bad cd");
                        return (1);
                }
		pre = append_insert_replace(cmd[1], search_and_rescue("PWD", env), '/');
		post = parse_path(pre);
		free(pre);
		update_dir(post, env);
		free(post);
        }
        else {
                chdir(search_and_rescue("HOME", env));
		update_dir(search_and_rescue("HOME", env), env);
        }
	return (0);
}

char *parse_path(char *str) 
{
  int i, i2;
	char **temp, **scan, *new;

	print_string(str);
	print_char('\n');
	scan = string_split(str, '/');
	for (i = 0; scan[i] != NULL; i++) {
	  if ((string_compare(scan[i], "..")) == 0) {

	    print_char('\n');
	    printf("\nAbout to remove: %s$\n", scan[i]);
	    temp = remove_from_vector(&(scan[i]), scan);
	    free_str_arr(scan);
	    printf("About to remove: %s$\n", temp[i - 1]);
	    scan = remove_from_vector(&(temp[i - 1]), temp);
	    free_str_arr(temp);
	    printf("Results are:\n");
	    fflush(stdout);
	    for(i2 = 0; scan[i2] != '\0'; i2++) {
	      print_string(scan[i2]);
	      print_char('\n');
	    }
	    fflush(stdout);
	    i = -1;
	  }
	  /* else if (string_compare(scan[i], ".") == 0) { */
	  /*   temp = remove_from_vector(&(scan[i]), scan); */
	  /*   free_str_arr(scan); */
	  /*   scan = temp; */
	  /*   i = -1; */
	  /* } */
	}

	new = glue_strings(scan, '/');
	free_str_arr(scan);

	return new;
}

void update_dir(char *str, char **env) {
        char **old, *new;

	new = search_and_rescue("PWD", env);
	old = get_variable("OLDPWD", env);
	free(*old);
	*old = append_insert_replace(new, "OLDPWD", '=');

	new = str;
	old = get_variable("PWD", env);
	free(*old);
 	*old = append_insert_replace(new, "PWD", '=');
}

/* builtin envonmetal veriable function */
int builtin_env(int ac, __attribute__((unused)) char **cmd, char **env)
{
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

/* built in set environmental veriable function */
char **builtin_setenv(int ac, char **cmd, char **env)
{
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

/* built in unset environmental veriable function */
char **builtin_unsetenv(int ac, char **cmd, char **env)
{
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
