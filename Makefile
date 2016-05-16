CC = gcc
CFLAGS = -Werror -Wextra -Wall -pedantic
OBJ = shell.c read_line.c string_split.c pre_process.c execute_command.c search_and_rescue.c vector.c check_builtins.c builtins.c builtins_extra.c helper_functions_1.c helper_functions_2.c
DEPS = shell_head.h shell_builtins.h
NAME = marcel_the_shell

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

test: $(OBJ)
	$(CC) -o $(NAME) $^
