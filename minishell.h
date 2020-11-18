/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:53:56 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/18 16:17:35 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINISHELL_H
# define MINISHELL_H
//# include "srcs/getnextline/get_next_line.h"
# include "srcs/libft/libft.h"
//# include "srcs/printf/libftprintf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
typedef struct  s_comand
{
	char        *type;
	char		*value;
}               t_comand;

typedef struct s_env
{
	char		*name;
	char		*value;
}				t_env;

void		ft_kill_commands(char ***commands);
int			ft_read_commands(char ***commands);
void		ft_echo(char *str);
char		*ft_search_word(char *str);
int			ft_print_word(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_kill_commands(char ***commands);
int			ft_read_commands(char ***commands);
void        ft_parse_commands(char *command, t_list **env);
void        ft_echo(char *str);
void        ft_echo2(char *str ,int flag);
int			ft_iscomma(char *str, int *comma);

/*
**	Command export
*/
int			ft_export(t_list **env, char *str);
/*
**	Command env
*/
int			ft_env(t_list **env);


#endif
