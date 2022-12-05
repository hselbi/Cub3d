RCAST = $(addprefix raycasting/, ceilling_flooring.c vision_field.c render.c dda_line_bonus.c\
        minimap_bonus.c)

SRC =	$(RCAST) $(addprefix src/, main.c keys_mlx.c rgb.c background_bonus.c init_texture.c\
        mouse_mv_bonus.c) $(addprefix intersection/, check_hor.c check_ver.c shortest.c)

PARSING = 	$(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
			ft_tolower.c ft_toupper.c) get_next_line/get_next_line.c cub3d_pars.c

PARSE = $(addprefix parsing/, $(PARSING))
		
NAME = cub3d

ARCH = minilibx/libmlx.a

OBJ = $(SRC:.c=.o) $(PARSE:.c=.o)

CC = gcc -g -Wall -Wextra -Werror

all: ${NAME}

bonus: ${NAME}

%.o: %.c
	$(CC) -c -g $< -o $@

$(NAME): $(SRC) $(OBJ)
	$(CC) $(OBJ) $(ARCH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all