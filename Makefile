##
## EPITECH PROJECT, 2026
## G-PSU-200-LIL-2-1-minshell-4
## File description:
## Makefile
##

CC      =   epiclang

SRC =   src/commands/find_command.c \
		src/commands/handle_command.c \
		src/commands/parse_command.c \
		src/commands/cd_command.c \
		src/commands/print_cd_path.c \
		src/envs/put_env.c \
		src/envs/my_setenv.c \
		src/envs/my_unsetenv.c \
		src/envs/free_env.c \
		src/paths/check_paths.c \
		src/paths/get_path.c \
		src/exec.c \
		src/signals.c \
		bonus/display_bonus.c \
		src/main.c

OBJ =   $(SRC:.c=.o)

NAME    =   mysh

CPPFLAGS =  -I./include
CFLAGS  =   -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	$(MAKE) -C ./lib/my clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./lib/my fclean
	rm -f $(NAME)

clean_tester:
	rm -f tester/$(NAME)
	rm -f tester/tests.txt

clean_tests_add:
	rm -f tester_add/$(NAME)
	rm -f tester_add/tests.txt

re: fclean all

tests: all clean
	@mkdir -p tester/
	@mkdir -p tester_add/
	@cp $(NAME) tester/
	@cp $(NAME) tester_add/

tests_add:
	@cd tester_add && ./tester.sh >> tests.txt

tests_run:
	@cd tester && ./tester.sh >> tests.txt

.PHONY: all test clean fclean re tests_run
