# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 19:08:43 by llopez-d          #+#    #+#              #
#    Updated: 2020/10/14 19:09:32 by llopez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_search_types.c ft_search_flags.c ft_sel_format_type.c functions_flags.c ft_utoa.c ft_ulltoa_base.c ft_type_c.c ft_type_s.c ft_type_di.c ft_type_u.c ft_type_x.c ft_type_p.c ft_type_cent.c 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
		cd libft && $(MAKE)
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)
f:	
	gcc *.c libft/*.c

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./libft
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./libft
re : fclean all

%.o: %.c
	$(CC) $(FLAGS) -I ft_printf.h -c $<  -o $(<:.c=.o)
