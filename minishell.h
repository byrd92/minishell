/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:53:56 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/11 12:15:19 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "srcs/getnextline/get_next_line.h"
# include "srcs/libft/libft.h"
# include "srcs/printf/libftprintf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
typedef struct  s_comand
{
	char        *type;
	t_list      *flags;
	t_list      *value;
}               t_comand;

void    ft_command_echo(char *line);
char	*ft_search_word(char *str);
int		ft_print_word(char *str);

#endif
