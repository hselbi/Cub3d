.PHONY = all clean fclean re

PARSE = $(addprefix parsing/, get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
		check_id.c path_rgb.c color.c utils.c utils1.c utils2.c fill_struct.c fill_struct_body.c \
		fill_struct_end.c fill_rgb.c)

####		mandatory		####

MAN_RCAST = $(addprefix raycasting/, ceilling_flooring.c vision_field.c render.c)

MAN_SRC =	$(addprefix mandatory/, $(MAN_RCAST) $(addprefix src/, main.c keys_mlx.c rgb.c \
		background.c init_texture.c errors.c) $(addprefix intersection/, check_hor.c check_ver.c \
		shortest.c))

NAME = cub3D

LIBFT = parsing/libft/libft.a

OBJ = $(MAN_SRC:.c=.o) $(PARSE:.c=.o)

####		bonus		####

BONUS_RCAST = $(addprefix raycasting/, ceilling_flooring.c vision_field.c render.c dda_line_bonus.c \
        	minimap_bonus.c)

BONUS_SRC =	$(addprefix bonus/, $(BONUS_RCAST) $(addprefix src/, main.c keys_mlx.c rgb.c \
			background_bonus.c init_texture.c mouse_mv_bonus.c sprite_bonus.c init_bonus.c \
			errors.c) $(addprefix intersection/, check_hor.c check_ver.c shortest.c))

NAME_BONUS = cub3D_bonus

LIBFT_BONUS = parsing/libft/libft.a

OBJ_BONUS = $(BONUS_SRC:.c=.o) $(PARSE:.c=.o)

ARCH = minilibx/libmlx.a

####		rules		####

CC = gcc -g -Wall -Wextra -Werror

all: ${NAME}

bonus: ${NAME_BONUS}

%.o: %.c
	@$(CC) -c -g $< -o $@

$(NAME): $(OBJ)
	@echo "\033[0;93mMake $(NAME) ..."
	@$(MAKE) -s -C parsing/libft
	@$(CC) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[1;92m$(NAME) is Done\033[0m"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "\033[0;93mMake $(NAME_BONUS) ..."
	@$(MAKE) -s -C parsing/libft
	@$(MAKE) -s -C minilibx
	@$(CC) $(OBJ_BONUS) $(ARCH) $(LIBFT_BONUS) -fsanitize=address -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "\033[1;92m$(NAME_BONUS) is Done\033[0m"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@$(MAKE) -s -C parsing/libft clean
	@$(MAKE) -s -C minilibx clean
	@echo "\033[1;91mCleaning Objects files is Done\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "\033[1;91mCleaning is Done\033[0m"

re: fclean all