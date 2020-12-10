/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:53:56 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/19 20:01:18 by egarcia-         ###   ########.fr       */
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
# include <sys/types.h>
# include <dirent.h>

typedef struct s_mini
{
		int		type;
		char	**argv;
}				t_mini;


typedef struct s_env
{
	char		*name;
	char		*value;
}				t_env;

void		ft_kill_commands(char ***commands);
int			ft_read_commands(char ***commands);

char		*ft_search_word(char *str);
int			ft_print_word(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_kill_commands(char ***commands);
int			ft_read_commands(char ***commands);
void        ft_parse_commands(char *command, t_list **env);

int			ft_iscomma(char *str, int *comma);

void		*ft_lstsearch_content(t_list *lst, int (*f)(void *, void *), void *to_search);

/*
** Utils.c
*/
int			argv_size(char *str, int c);
char		*ft_strdup_sep(char *str, int c);
char		**ft_split_mini(char *str, int c);
char		*ft_strldup(char *str, int i);
char		*ft_find_env(char *str, t_list **env);
int			ft_search_env(void	*content, void *to_search);

void		ft_kill_env(void *content);
/*
**	Command export
*/
int			ft_export(t_list **env, char *str);
/*
**	Command env
*/
int			ft_env(t_list **env);

/*
** Command unset
*/
int			ft_unset(t_list **env, char *str);

/*
** Command echo
*/
void        ft_echo(t_list **env, char **argv);
void        ft_echo2(char **argv ,int flag, t_list **env);

int			ft_pwd();

int         ft_cd(t_list **env, char *str);
#endif
