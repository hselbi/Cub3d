.PHONY = all clean fclean re


####		mandatory		####

MAN_RCAST = $(addprefix raycasting/, ceilling_flooring.c vision_field.c render.c)

MAN_SRC =	$(RCAST) $(addprefix src/, main.c keys_mlx.c rgb.c background.c init_texture.c)\
		$(addprefix intersection/, check_hor.c check_ver.c shortest.c)

MAN_PARSING = 	$(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
			ft_tolower.c ft_toupper.c) get_next_line/get_next_line.c cub3d_pars.c

MAN_PARSE = $(addprefix parsing/, $(MAN_PARSING))

SRC_MAN = $(addprefix mandatory/, $(MAN_SRC) $(MAN_RCAST) $(MAN_PARSE))

####		bonus		####

BONUS_RCAST = $(addprefix raycasting/, ceilling_flooring.c vision_field.c render.c dda_line_bonus.c\
        minimap_bonus.c)

BONUS_SRC =	$(BONUS_RCAST) $(addprefix src/, main.c keys_mlx.c rgb.c background_bonus.c init_texture.c\
        mouse_mv_bonus.c) $(addprefix intersection/, check_hor.c check_ver.c shortest.c)

BONUS_PARSING = 	$(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
			ft_tolower.c ft_toupper.c) get_next_line/get_next_line.c check_id.c path_rgb.c color.c \
			utils.c utils1.c utils2.c fill_struct.c fill_struct_body.c fill_struct_end.c fill_rgb.c

BONUS_PARSE = $(addprefix parsing/, $(BONUS_PARSING))

MLIBX = bonus/minilibx/libmlx.a

SRC_BONUS = $(addprefix bonus/, $(BONUS_RCAST) $(BONUS_SRC) $(BONUS_PARSE))

####	start		####

NAME = cub3d

NAME_BONUS = cub3d

MAN_OBJ = $(SRC_MAN:.o=.c)

BONUS_OBJ = $(SRC_BONUS:.o=.c)

CC = gcc -Wall -Wextra -Werror

%.o: %.c
	$(CC) -c $< -o $@

all: ${NAME}

${NAME}: $(SRC_MAN) $(MAN_OBJ)
	$(CC) $(MAN_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS): $(SRC_BONUS) $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(MLIBX) -lmlx -framework OpenL -framework Appkit -o $(NAME_BONUS)

clean:
	rm -rf $(MAN_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all