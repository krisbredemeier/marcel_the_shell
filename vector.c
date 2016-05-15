#include "shell_head.h"
#include "shell_builtins.h"

char **copy_vector(char **str_arr)
{
  int i, i2;
  char **new_arr;
  
  if (str_arr == NULL) {
    return NULL;
  }

  for(i = 0; str_arr[i] != NULL; i++) {}
  if((new_arr = malloc(sizeof(char *) * (i + 1))) == NULL) {
      return NULL;
  }
  
  for(i = 0; str_arr[i] != NULL; i++) {

    for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {}
    if((new_arr[i] = malloc(sizeof(char) * (i2 + 1))) == NULL) {
      free_str_arr(new_arr);
      return NULL;
    }

    for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {
      new_arr[i][i2] = str_arr[i][i2]; 
    }
    new_arr[i][i2] = '\0';
  }

  new_arr[i] = NULL;
  return new_arr;
}
char **remove_from_vector(char **str, char **str_arr)
{
  int i;
  char **new_arr;

  *str = NULL;
  for(i = 0; str_arr[i] != NULL; i++) {} 
  while(str_arr[i + 1] != NULL) {
    str_arr[i + 1] = str_arr[i];
    i++;
  }

  new_arr = copy_vector(str_arr);
  free_str_arr(str_arr);
  return new_arr;
}
/* int replace_in_vector(char *str, char **str_arr) */
/* { */

/* } */
/* int add_to_vector(char *str, char **str_arr) */
/* { */

/* } */
