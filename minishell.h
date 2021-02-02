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
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

# define READ_END 0 //extremo de escritura
# define WRITE_END 1 //extremo de lectura

#include <sys/wait.h>



typedef struct s_mini
{
		int		newin;
		int		newout;
		int		mainout;
		int		mainin;
		int		in;
		int		out;
		int		dolar;
		char	*strcmd;
		char	**commands;
		t_list	*tokens;
}				t_mini;

typedef struct s_token
{
		int		type;
		char	**argv;		
}				t_token;

typedef struct s_env 
{
	char		*name;
	char		*value;
}				t_env;


void		ft_kill_commands(t_mini *mini);
int			ft_read_commands(t_mini *mini);

char		*ft_search_word(char *str);
int			ft_print_word(char *str);
int			ft_strcmp(char *s1, char *s2);
void        ft_parse_commands(t_mini *mini , t_list **env, int i);
int    		ft_select_build_function(t_list *mini,  t_list **env, char **envp);
void	    ft_select_build_function_fork(t_list *mini,  t_list **env, char **envp);
int			ft_iscomma(char *str, int *comma);

int			ft_check_pipes(t_list *mini);

/*
** Utils.c
*/
void		sighandler(const int sig);
char		*ft_strdup_sep(char *str, int c);
char		**ft_split_mini(char *str);
char		*ft_strldup(char *str, int i);
char		*ft_find_env(char *str, t_list **env);
int			ft_search_env(void	*content, void *to_search);
void		*ft_lstsearch_content(t_list *lst, int (*f)(void *, void *), void *to_search);
/*
** lens.c
*/

int			argv_size(char *str, int c);
int		ft_strlen_char(char *str, char c);
int		ft_strlen_tokens(char *str);
int		ft_strlen_token(char *str);
int		ft_strlen_arg(char *str);


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
int			ft_unset(t_list **env, char **argv);

/*
** Command echo
*/
int      	ft_echo(t_list **env, char **argv);

int			ft_pwd();

char		*search_path(t_list **env, char *program);
int         ft_cd(t_list **env,  char **argv);

int     ft_dolar(char *comand, t_mini *mini);

/*
** forks
*/

void		ft_create_pipes(int num_pipes, int ***fd);
int			ft_forker(t_list **mini, int pipes, t_list **env, char **envp);

/*
** ft_io
*/
void	ft_check_io(t_mini *mini);
void     ft_save_stdio(t_mini *mini);
void    ft_reset_io(t_mini *mini);

int		ft_isvalid(char *str);
extern int g_sig;
#endif
