#include "shell_head.h"
#include "shell_builtins.h"

int pre_process_comments(char *str)
{
        char *target;
        if((target = first_in_string('#', str)) != NULL) {
	        *target = '\0';
	}
	if(*str == '\0') {
	        return (1);
	} 
	else {
	        return (0);
	}
}

char *first_in_string(char c, char *str)
{
	int i;

	for(i = 0; str[i] != '\0'; i++) {
	  if (str[i] == c) {
	    return &(str[i]);
	  }
	}

	return NULL;
}

int pre_process_variables(int ac, char **cmd, char **env) {
  int i;
  
  for(i = 0; i < c; i++) {
    if(
  }

  return (0);
}


