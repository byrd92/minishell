/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_build_function_fork.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:22:41 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/17 11:40:48 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		ft_select_build_in_fork(t_token *content, t_list **env)
{
	if (ft_strncmp(content->argv[0], "echo\0", 6) == 0)
		return (ft_echo(env, content->argv));
	else if (ft_strncmp(content->argv[0], "export\0", 7) == 0)
		return (ft_export(env, content->argv));
	else if (ft_strncmp(content->argv[0], "env\0", 4) == 0)
		return (ft_env(env));
	else if (ft_strncmp(content->argv[0], "unset\0", 6) == 0)
		return (ft_unset(env, content->argv));
	else if (ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
		return (ft_pwd(env));
	else if (ft_strncmp(content->argv[0], "cd\0", 3) == 0)
		return (ft_cd(env, content->argv));
	else if (ft_strncmp(content->argv[0], "exit\0", 5) == 0)
		return (1);
	return (1);
}

static void		ft_absolute_path_fork(t_token *content, char **envp)
{
	signal(SIGINT, child_sig_handler_bash);
	if (execve(content->argv[0], content->argv, envp))
	{
		write(2, "bash: ", 6);
		write(2, content->argv[0], ft_strlen(content->argv[0]));
		write(2, ": No such file or directory\n", 29);
	}
	exit(127);
}

static void		ft_relative_path_fork(t_token *content,
				t_list **env, char **envp)
{
	char *path;

	path = search_path(env, content->argv[0]);
	if (ft_strncmp(path, "bash:", 5) != 0)
	{
		execve(ft_strjoin(search_path(env, content->argv[0]),
		ft_strjoin("/", content->argv[0])), content->argv, envp);
	}
	write(2, "bash: ", 6);
	write(2, content->argv[0], ft_strlen(content->argv[0]));
	write(2, ": No such file or directory\n", 29);
	exit(127);
}

int				ft_select_build_function_fork(t_list *mini,
				t_list **env, char **envp)
{
	t_token		*content;
	int			ret;

	content = (t_token *)mini->content;
	if ((ret = ft_select_build_in_fork(content, env) == 0))
		return (0);
	else if (ft_strncmp(content->argv[0], "/", 1) == 0 ||
			ft_strncmp(content->argv[0], "./", 2) == 0 ||
			ft_strncmp(content->argv[0], "../", 3) == 0)
		ft_absolute_path_fork(content, envp);
	else if ((search_path(env, content->argv[0])))
		ft_relative_path_fork(content, env, envp);
	else if (search_path(env, content->argv[0]))
		execve(ft_strjoin(search_path(env, content->argv[0]),
					ft_strjoin("/", content->argv[0])), content->argv, envp);
	else
	{
		write(2, content->argv[0], ft_strlen(content->argv[0]));
		write(2, ": command not found\n", 20);
	}
	exit(0);
}
