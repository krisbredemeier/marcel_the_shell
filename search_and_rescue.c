#include "shell_head.h"

/* search and rescue searches the environment variable vector for a match
   and returns just the value of the requested variable. */
char *search_and_rescue(char *search, char **env) {
  int i, i2;
  if (search == NULL) {
    perror("No search criteria");
    return NULL;
  }

  for(i = 0; env[i] != NULL; i++) {
    for(i2 = 0; env[i][i2] == search[i2] && env[i][i2] != '='; i2++) {}
    if (env[i][i2] == '=') {
      return &(env[i][i2 + 1]);
    }
  }

  return NULL;
}

/*uses search_and_rescue function and string_split funtion to
piece togethter the path and the command to find if the full path
of the command*/
char *find_command(char *exec, char **env) {
  char **dir_arr;
  char *dir_path;
  char *path;
  struct stat stat_strut;
  int i;

  path = search_and_rescue("PATH", env);
  dir_arr = string_split(path, ':');

  for(i = 0; dir_arr[i] != NULL; i++) {
    dir_path = append_insert_replace(exec, dir_arr[i], '/');

    if ((stat(dir_path, &stat_strut)) == 0) {
      free(exec);
      return dir_path;
    }
    free(dir_path);
  }

  free_str_arr(dir_arr);
  return NULL;

}

char *append_insert_replace(char *str, char *dir, char divider) {
  int i, i2, i3, mod;
  char *new;

  if (divider) {
    mod = 1;
  }
  else {
    mod = 0;
  }

  for (i = 0; str[i] != '\0'; i++) {}
  for (i3 = 0; dir[i3] != '\0'; i3++) {}

  new = malloc(sizeof(char) * (i3 + i + 1 + mod));

  for (i = 0; dir[i] != '\0'; i++) {
    new[i] = dir[i];
  }
  if (mod) {
    new[i] = divider;
    i++;
  }

  for (i2 = 0; str[i2] != '\0'; i2++, i++) {
    new[i] = str[i2];
  }

  new[i] = '\0';

  return (new);
}

void free_str_arr(char **str_arr) {
  int i;

  for (i = 0; str_arr[i] != NULL; i++) {
    free(str_arr[i]);
  }

  free(str_arr);
}

char **get_variable(char *search, char **env) {
  int i, i2;
  if (search == NULL) {
    perror("No search criteria");
    return NULL;
  }

  for(i = 0; env[i] != NULL; i++) {
    for(i2 = 0; env[i][i2] == search[i2] && env[i][i2] != '='; i2++) {}
    if (env[i][i2] == '=' && search[i2] == '\0') {
      return &(env[i]);
    }
  }

  return NULL;
}
