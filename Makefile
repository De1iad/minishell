
NAME	= minishell

SRC		= main.c get_args.c ft_split.c ft_strjoin.c ft_strchr.c ft_strncmp.c \
			extension.c ft_strlen.c ft_isalpha.c quotes.c spaces.c ft_split_or.c \
			ft_strdup.c fin_token.c ft_calloc.c ft_strjoin_slash.c ft_bzero.c \
			echo/echo.c cd/cd.c env/env.c exit/exit.c pwd/pwd.c pipex/pipex.c
OBJ		= $(SRC:.c=.o)

CC		= clang
# CFLAGS	= -Wall -Wextra -Werror -lreadline -fsanitize=address -g
CFLAGS	= -Wall -Wextra -Werror -lreadline -g  # -fsanitize=address


all : $(NAME)

%.o : %.c
	$(CC) -c -g $< -o $@

$(NAME) : $(OBJ) minishell.h Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re