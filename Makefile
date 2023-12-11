# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 13:42:48 by alinevieira       #+#    #+#              #
#    Updated: 2023/12/11 19:26:41 by alinevieira      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
NAMELIBFT = libft/libft.a

SRC_C = src/client.c
SRC_S = src/server.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

all:	${NAME}

${NAMELIBFT}:
		${MAKE} ${LIBFT_PATH} all

${NAME}:
		${CC} ${CFLAGS} ${SRC_C} ${INCLUDE} ${NAMELIBFT} -o client
		${CC} ${CFLAGS} ${SRC_S} ${INCLUDE} ${NAMELIBFT} -o server

$(NAMELIBFT): ${OBJS}
		${MAKE} ${LIBFT_PATH} all

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} -rf client server

re: fclean all

.PHONY: all clean fclean re