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
  int i, i2, i3;
  char **new_arr;
  if (str_arr == NULL) {
    return NULL;
  }
  for(i = 0; str_arr[i] != NULL; i++) {}
  if((new_arr = malloc(sizeof(char *) * (i))) == NULL) {
      return NULL;
  }
  for(i = 0, i3 = 0; str_arr[i] != NULL; i++, i3++) {
    if (string_compare(*str, str_arr[i]) == 0) {
      i3--;
    } 
    else {
      for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {}
      if((new_arr[i3] = malloc(sizeof(char) * (i2 + 1))) == NULL) {
	free_str_arr(new_arr);
	return NULL;
      }
      for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {
	new_arr[i3][i2] = str_arr[i][i2]; 
      }
      new_arr[i3][i2] = '\0';
    }
  }
  new_arr[i3] = NULL;
  return new_arr;
}

char **add_to_vector(char *str, char **str_arr)
{
  int i, i2;
  char **new_arr;
  if (str_arr == NULL) {
    return NULL;
  }
  for(i = 0; str_arr[i] != NULL; i++) {}
  if((new_arr = malloc(sizeof(char *) * (i + 2))) == NULL) {
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
  for(i2 = 0; str[i2] != '\0'; i2++) {}
  if((new_arr[i] = malloc(sizeof(char) * (i2 + 1))) == NULL) {
    free_str_arr(new_arr);
    return NULL;
  }
  for(i2 = 0; str[i2] != '\0'; i2++) {
    new_arr[i][i2] = str[i2]; 
  }
  new_arr[i][i2] = '\0';
  i++;
  new_arr[i] = NULL;
  free(str);
  return new_arr;
}
