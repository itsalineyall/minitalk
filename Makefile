# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 13:42:48 by alinevieira       #+#    #+#              #
#    Updated: 2023/12/12 14:23:35 by alinevieira      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBFT_PATH = libft
LIBFT = libft/libft.a

all:	${NAME}

${LIBFT}:
		${MAKE} ${LIBFT_PATH} all

${NAME}: ${LIBFT}
		${CC} ${CFLAGS} client.c ${INCLUDE} ${LIBFT} -o client
		${CC} ${CFLAGS} server.c ${INCLUDE} ${LIBFT} -o server

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} client server

re: fclean all

.PHONY: all clean fclean re