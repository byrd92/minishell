/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_build_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:07:51 by jalcayne          #+#    #+#             */
/*   Updated: 2021/01/19 12:02:48 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	child_sig_handler_bash(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		exit(0);
	}
}

static int	   ft_built_in_function(t_mini *mini, t_token *content, t_list **env)
{
		if(ft_strncmp(content->argv[0], "echo\0", 6) == 0)
		return (ft_echo(env ,content->argv));
	else if(ft_strncmp(content->argv[0], "export\0", 7) == 0)
		return (ft_export(env, content->argv));
	else if(ft_strncmp(content->argv[0], "env\0", 4) == 0)
		return (ft_env(env));
	else if(ft_strncmp(content->argv[0], "unset\0", 6) == 0)
		return (ft_unset(env, content->argv));
	else if(ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
		return (ft_pwd(env));
	else if(ft_strncmp(content->argv[0], "cd\0", 3) == 0)
		return (ft_cd(env, content->argv));
	else if (ft_strncmp(content->argv[0], "exit\0", 5) == 0)
		ft_exit(mini, env, content->argv);
	return (1);
}

static int		ft_absolute_path(t_mini *mini, t_token *content, char **envp)
{
	if (!fork())
	{
		signal(SIGINT, child_sig_handler_bash);
		if (execve(content->argv[0], content->argv, envp))
			ft_printf("bash: %s: No such file or directory\n", content->argv[0]);
		exit(127);
	}
	else
		wait(&mini->dolar);
	mini->dolar /= 256;
	return (mini->dolar);
}

static int		ft_relative_path(t_mini *mini, t_list **env, t_token *content, char **envp)
{
	char *path;

	path = search_path(env, content->argv[0]);
	if (ft_strncmp(path, "bash:", 5) != 0)
	{
		if (!fork())
			execve(ft_strjoin(search_path(env, content->argv[0]),ft_strjoin("/", content->argv[0])), content->argv, envp);
		else
			wait(&mini->dolar);
		return (mini->dolar);
	}
	ft_printf("bash: %s: No such file or directory\n", content->argv[0]);
	return (127);
}


int		ft_select_build_function(t_mini *mini, t_list **env, char **envp)
{
	t_token *content;
	t_list *aux;
	aux = mini->tokens;
	int ret;

	(void)envp;
	while (aux)
	{
		content = (t_token *)aux->content;
		if ((ret = ft_built_in_function(mini, content, env) == 0))
			return (0);
		else if (ft_strncmp(content->argv[0], "/", 1) == 0 ||
				ft_strncmp(content->argv[0], "./", 2) == 0 ||
				ft_strncmp(content->argv[0], "../", 3) == 0)
			return(ft_absolute_path(mini, content, envp));
		else if (search_path(env, content->argv[0]))
			return (ft_relative_path(mini, env, content, envp));
		else
		{
			ft_printf("%s: command not found\n", content->argv[0]);
			return (127);
		}
		aux = aux->next;
	}
	return (0);
}

int    ft_select_build_function_fork(t_list *mini,  t_list **env, char **envp)
{
   	t_token *content;
	char *path;

	content = (t_token *)mini->content;
	if(ft_strncmp(content->argv[0], "echo\0", 6) == 0)
		return (ft_echo(env ,content->argv));
	else if(ft_strncmp(content->argv[0], "export\0", 7) == 0)
		return (ft_export(env, content->argv));
	else if(ft_strncmp(content->argv[0], "env\0", 4) == 0)
		return (ft_env(env));
	else if(ft_strncmp(content->argv[0], "unset\0", 6) == 0)
		return (ft_unset(env, content->argv));
	else if(ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
		return (ft_pwd(env));
	else if(ft_strncmp(content->argv[0], "cd\0", 3) == 0)
		return (ft_cd(env, content->argv));
	else if (ft_strncmp(content->argv[0], "exit\0", 5) == 0)
		;
	else if (ft_strncmp(content->argv[0], "/", 1) == 0 ||
			ft_strncmp(content->argv[0], "./", 2) == 0 ||
			ft_strncmp(content->argv[0], "../", 3) == 0)
		{
			signal(SIGINT,child_sig_handler_bash);
			if (execve(content->argv[0], content->argv, envp))
			{	
				write(2, "bash: ", 6);
				write(2, content->argv[0], ft_strlen(content->argv[0]));
				write(2, ": No such file or directory\n", 29);
			}
			exit(127);
		}
	else if ((path = search_path(env, content->argv[0])))
		{
			if (ft_strncmp(path, "bash:", 5) != 0)
			{
				execve(ft_strjoin(search_path(env, content->argv[0]),ft_strjoin("/", content->argv[0])), content->argv, envp);
			}
				write(2, "bash: ", 6);
				write(2, content->argv[0], ft_strlen(content->argv[0]));
				write(2, ": No such file or directory\n", 29);
			exit(127);
		}
	else if (search_path(env, content->argv[0]))
		execve(ft_strjoin(search_path(env, content->argv[0]),ft_strjoin("/", content->argv[0])), content->argv, envp);
	else
	{
		write(2, content->argv[0], ft_strlen(content->argv[0]));
		write(2, ": command not found\n", 20);
	}

	exit(0);
}