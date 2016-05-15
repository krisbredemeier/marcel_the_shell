#include "shell_head.h"

#define PROMPT_SIZE 4
#define BUFF_SIZE 5

char *read_line(int fd) {
  char *bf, *temp;
  int size, i;
 
  char prompt[] = ">>> ";
  write(1, prompt, PROMPT_SIZE);

  bf = malloc(sizeof(char) * (BUFF_SIZE));
 
  i = 0;
  while (1) {
    size = read(fd, &(bf[i]), BUFF_SIZE);
    if (size == -1) {
      free(bf);
      perror("read bad");
      return NULL;
    }

    if (bf[i + size - 1] == '\n') {
      bf[i + size - 1] = '\0';
      
      return (bf);
    }

    i += size;
    temp = malloc(sizeof(char) * (i));
    copy_string(bf, temp, i);
    
    free(bf);
    bf = malloc(sizeof(char) * (i + BUFF_SIZE + 1));
    copy_string(temp, bf, i); 
    free(temp);
  }
  
}

void copy_string(char *source, char *dest, int n) {
  int i;
  for (i = 0; i < n; i++){
    dest[i] = source[i];
  }
}

