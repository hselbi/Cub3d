# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:50:01 by adbaich           #+#    #+#              #
#    Updated: 2022/12/07 21:13:49 by hselbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c \
        ft_atoi.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_memchr.c \
        ft_strncmp.c \
        ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isprint.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_strnstr.c \
        ft_memcmp.c  \
        ft_memset.c  \
        ft_bzero.c   \
        ft_memcpy.c \
        ft_memmove.c \
        ft_calloc.c  \
        ft_strdup.c \
        ft_isascii.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

OBJS = ${SRCS:.c=.o}
NAME = libft.a

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} -c ${SRCS}
	@ar rc ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
