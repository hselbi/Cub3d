# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
<<<<<<< HEAD
=======
#    By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:50:01 by adbaich           #+#    #+#              #
#    Updated: 2022/12/07 21:13:49 by hselbi           ###   ########.fr        #
=======
>>>>>>> 18069a8180dc2dd9578af720e438b98d10c436eb
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:50:01 by adbaich           #+#    #+#              #
#    Updated: 2022/12/08 12:55:49 by adbaich          ###   ########.fr        #
<<<<<<< HEAD
=======
#    By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:50:01 by adbaich           #+#    #+#              #
#    Updated: 2022/12/07 21:13:49 by hselbi           ###   ########.fr        #
>>>>>>> main
=======
>>>>>>> 3387e81e10c60bd540f066ffffe7d3fb2c92e4be
>>>>>>> 18069a8180dc2dd9578af720e438b98d10c436eb
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

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
<<<<<<< HEAD
<<<<<<< HEAD
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
=======
	@${CC} ${FLAGS} -c ${SRCS}
	@ar rc ${NAME} ${OBJS}
>>>>>>> main
=======
	@${CC} ${FLAGS} -c ${SRCS}
	@ar rc ${NAME} ${OBJS}
=======
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
>>>>>>> 3387e81e10c60bd540f066ffffe7d3fb2c92e4be
>>>>>>> 18069a8180dc2dd9578af720e438b98d10c436eb

clean:
	@${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
