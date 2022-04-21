SRCS		=	*.c

OBJS		=	${SRCS:.c=.o}

NAME		=	libft.a

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -g

$(NAME):	
		${CC} ${CFLAGS} -c ${SRCS}
		ar rc	${NAME}	${OBJS}
		ranlib ${NAME}

all:	$(NAME)

clean:
		${RM} *.o

fclean:		clean
		${RM} ${NAME}

re:		fclean all
