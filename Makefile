.PHONY = all clean fclean re

####		mandatory		####

MAN_RCAST = $(addprefix raycasting/, ceilling_flooring.c vision_field.c render.c)

MAN_SRC =	$(addprefix mandatory/, $(MAN_RCAST) $(addprefix src/, main.c keys_mlx.c rgb.c \
		background.c init_texture.c errors.c) $(addprefix intersection/, check_hor.c check_ver.c \
		shortest.c))

MAN_PARSING = 	$(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c) get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
			check_id.c path_rgb.c color.c utils.c utils1.c utils2.c fill_struct.c fill_struct_body.c \
			fill_struct_end.c fill_rgb.c

MAN_PARSE = $(addprefix mandatory/parsing/, $(MAN_PARSING))

NAME = cub3D

OBJ = $(MAN_SRC:.c=.o) $(MAN_PARSE:.c=.o)

####		bonus		####

BONUS_RCAST = $(addprefix raycasting/, ceilling_flooring.c vision_field.c render.c dda_line_bonus.c \
        	minimap_bonus.c)

BONUS_SRC =	$(addprefix bonus/, $(BONUS_RCAST) $(addprefix src/, main.c keys_mlx.c rgb.c \
			background_bonus.c init_texture.c mouse_mv_bonus.c sprite_bonus.c init_bonus.c \
			errors.c) $(addprefix intersection/, check_hor.c check_ver.c shortest.c))

BONUS_PARSING = 	$(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c) get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
			check_id.c path_rgb.c color.c utils.c utils1.c utils2.c fill_struct.c fill_struct_body.c \
			fill_struct_end.c fill_rgb.c

BONUS_PARSE = $(addprefix bonus/parsing/, $(BONUS_PARSING))

NAME_BONUS = cub3D_bonus

OBJ_BONUS = $(BONUS_SRC:.c=.o) $(BONUS_PARSE:.c=.o)

ARCH = minilibx/libmlx.a

####		rules		####

CC = gcc -g -Wall -Wextra -Werror

all: ${NAME}

bonus: ${NAME_BONUS}

%.o: %.c
	@$(CC) -c -g $< -o $@

$(NAME): $(OBJ)
	@echo "\033[0;93mMake $(NAME) ..."
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[1;92m$(NAME) is Done\033[0m"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "\033[0;93mMake $(NAME_BONUS) ..."
	@$(CC) $(OBJ_BONUS) $(ARCH) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "\033[1;92m$(NAME_BONUS) is Done\033[0m"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@echo "\033[1;91mCleaning Objects files is Done\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "\033[1;91mCleaning is Done\033[0m"

re: fclean all