/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:28:14 by jalcayne          #+#    #+#             */
/*   Updated: 2021/03/19 15:24:45 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define READ_END 0
# define WRITE_END 1
# include "srcs/libft/libft.h"
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
# include <sys/wait.h>

# define READ_END 0
# define WRITE_END 1

typedef struct	s_mini
{
	int			newin;
	int			newout;
	int			mainout;
	int			mainin;
	int			in;
	int			out;
	int			dolar;
	char		*strcmd;
	char		**commands;
	t_list		*tokens;
}				t_mini;

typedef struct	s_token
{
	int			type;
	char		**argv;
}				t_token;

typedef struct	s_env
{
	char		*name;
	char		*value;
}				t_env;

typedef struct	s_env_envp
{
	t_list	**env;
	char	**envp;
}				t_env_envp;

/*
** MAIN
*/
void			ft_kill_commands(t_mini *mini);
void			ft_kill_env(void *content);
void			ft_kill_mini(void *content);
void			init_mini(t_mini *mini);

/*
** CD
*/

int				ft_cd(t_list **env, char **argv);

/*
** CHECK PIPE
*/

int				ft_check_pipes(t_list *mini);

/*
** ENV
*/

int				ft_env(t_list **env);
int				ft_search_env(void	*content, void *to_search);
char			*ft_find_env(char *str, t_list **env);
void			ft_environment(t_list **env, char **envp);
/*
** EXIT
*/

void			ft_destroy_mini(t_mini *mini);
int				ft_exit(t_mini *mini, t_list **env, char **content);

/*
** EXPORT
*/

int				ft_search_export(void	*content, void *to_search);
int				ft_export(t_list **env, char **argv);

/*
** FORKER
*/

void			ft_create_pipes(int num_pipes, int ***fd);
int				ft_forker(t_mini *mini, int pipes, t_list **env, char **envp);

/*
** DOLAR
*/

int				ft_dolar(char *comand, t_mini *mini);

/*
** ECHO
*/
int				ft_echo(t_list **env, char **argv);

/*
** IO
*/
void			ft_save_stdio(t_mini *mini);
void			ft_reset_io(t_mini *mini);
void			ft_check_io(t_mini *mini);

/*
** FT_KILL
*/
void			ft_kill_commands(t_mini *mini);
void			ft_kill_env(void *content);
void			ft_kill_mini(void *content);

/*
** PARSER COMMAND
*/
void			ft_new_token(t_mini *mini,char *command);
void			ft_create_token(t_mini *mini, int i);
void			ft_check_env(char **str, t_list **env);
void			ft_parse_commands(t_mini *mini , t_list **env, int i);
int				ft_change_env(char **str, int i, t_list **env);
void			ft_parse_commands(t_mini *mini , t_list **env, int i);

/*
** READ COMMANDS
*/
int				ft_iscomma(char *str, int *comma);
void			sighandler(const int sig);
int				ft_read_commands(t_mini *mini);

/*
** LENS
*/
int				argc_size(char *str);
int				ft_strlen_char(char *str, char c);
int				ft_strlen_arg(char *str);
int				ft_strlen_env(char *str);

/*
** PWD
*/
int				ft_pwd();
int				skip_space(char *str);

/*
** RM TOKEN
*/
void			rm_char(char **str, int j);
int				is_token(char c);
void			rm_backslash(char **arg, int *i);
void			rm_token(char **argv);
int				salir_d;
/*
** SEARCH PATH
*/

char			*search_path(t_list **env, char *program);

/*
** SELECT BUILD FUNCTION
*/
void			child_sig_handler_bash(int sig);
int				ft_select_build_function(t_mini *mini,  t_list **env,
				char **envp);
int				ft_select_build_function_fork(t_list *mini,
				t_list **env, char **envp);

/*
** UNSET
*/
void			ft_lstdelmiddle(t_list **lst, int (*f)(void *, void *),
				void *to_search);
int				ft_unset(t_list **env, char **argv);

/*
** UTILS
*/
char			*ft_strldup(char *str, int size);
char			**ft_split_mini(char *str);
void			*ft_lstsearch_content(t_list *lst, int (*f)(void *, void *), void *to_search);
int				ft_datatype(char *tmp, t_token *data);

void			create_pipe(int pipes, int ***fd);

#endif
