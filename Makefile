
CC = gcc

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRCS = main.c srcs/getnextline/get_next_line_utils.c srcs/getnextline/get_next_line.c srcs/ft_read_commands.c srcs/ft_parse_command.c srcs/export.c srcs/unset.c srcs/ft_echo.c srcs/pwd.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@cd srcs/libft && $(MAKE)
		@cp srcs/libft/libft.a libft.a
		@cd srcs/printf && $(MAKE)
		@cp srcs/printf/libftprintf.a libftprintf.a
		@#ar -rcs $(NAME) $(OBJS)
		
		gcc $(OBJS) libft.a libftprintf.a $(FLAGS) -o $(NAME)
f:	
	gcc *.c libft/*.c

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./srcs/libft
		$(MAKE) clean -C ./srcs/printf
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		rm -f libftprintf.a
		$(MAKE) fclean -C ./srcs/libft
		$(MAKE) fclean -C ./srcs/printf
re : fclean all

%.o: %.c
	$(CC) $(FLAGS) -I ft_printf.h -c $<  -o $(<:.c=.o)
	