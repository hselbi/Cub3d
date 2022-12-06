# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 20:17:07 by adbaich           #+#    #+#              #
#    Updated: 2022/12/05 20:23:13 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = libft/ft_strlen.c \
        libft/ft_atoi.c \
        libft/ft_strchr.c \
        libft/ft_strrchr.c \
        libft/ft_memchr.c \
        libft/ft_strncmp.c \
        libft/ft_isalpha.c \
        libft/ft_isdigit.c \
        libft/ft_isalnum.c \
        libft/ft_isprint.c \
        libft/ft_toupper.c \
        libft/ft_tolower.c \
        libft/ft_strlcpy.c \
        libft/ft_strlcat.c \
        libft/ft_strnstr.c \
        libft/ft_memcmp.c  \
        libft/ft_memset.c  \
        libft/ft_bzero.c   \
        libft/ft_memcpy.c \
        libft/ft_memmove.c \
        libft/ft_calloc.c  \
        libft/ft_strdup.c \
        libft/ft_isascii.c \
        libft/ft_substr.c \
        libft/ft_strjoin.c \
        libft/ft_strtrim.c \
        libft/ft_split.c \
        libft/ft_itoa.c \
        libft/ft_strmapi.c \
        libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
        get_next_line/get_next_line.c \
        check_id.c \
        path_rgb.c \
        color.c \
        utils.c \
        utils1.c \
        utils2.c \
        fill_struct.c \
        fill_struct_body.c \
        fill_struct_end.c \
        fill_rgb.c \
        

OBJS = ${SRCS:.c=.o}
NAME = parse

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
