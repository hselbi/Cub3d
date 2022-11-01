.PHONY = all clean fclean re

SRC = main.c

NAME = cub3d

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	$(CC) -c -g $< -o $@

$(NAME): $(SRC) $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -fsanitize=address -framework AppKit -o $(NAME) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all