NAME = libft.a

PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memset.c ft_memmove.c ft_strlcpy.c \
		ft_hex.c ft_pointer.c ft_printf.c ft_putchar.c \
		ft_putnbr_u.c ft_putnbr.c ft_putstr.c \

PART2 = ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c \
		ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c

SRC = ${PART1} ${PART2}
SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
		 

OBJS = ${SRC:.c=.o}
BONUS_OBJS = ${SRCB:.c=.o}

INCLUDE = -I .
COMP = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
.c.o:
	${COMP} ${FLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
	
$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all:    ${NAME}

bonus:	${OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} rm 

re: fclean all

.PHONY: all bonus clean fclean tclean re