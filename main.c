/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:38:34 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/19 18:26:21 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	hace_todo(t_mini *mini, t_list **env, char **envp, int *i)
{
	int	pipes;

	ft_parse_commands(mini, env, *i);
	ft_check_io(mini);
	pipes = ft_check_pipes(mini->tokens);
	if (pipes)
		mini->dolar = ft_forker(mini, pipes, env, envp);
	else
		mini->dolar = ft_select_build_function(mini, env, envp);
	*i = *i + 1;
	ft_lstclear(&mini->tokens, ft_kill_mini);
}

static void	bucle_main(t_mini *mini, t_list **env, char **envp)
{
	int	i;

	i = 0;
	while (ft_read_commands(mini))
	{
		i = 0;
		while (mini->commands[i])
		{
			if (ft_dolar(mini->commands[i], mini))
				i++;
			else
			{	
				hace_todo(mini, env, envp, &i);
			}	
		}
		ft_reset_io(mini);
		ft_lstclear(&mini->tokens, ft_kill_mini);
		ft_kill_commands(mini);
		init_mini(mini);
		ft_printf("minivid > ");
	}
}

static void	ft_environment(t_list **env, char **envp)
{
	t_env	*newenv;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (envp[++i])
	{
		j = 0;
		newenv = (t_env *)malloc(sizeof(t_env) * 1);
		newenv->name = ft_search_word(envp[i]);
		while (envp[i][j] != '=')
			j++;
		j++;
		newenv->value = ft_strdup(&envp[i][j]);
		ft_lstadd_back(env, ft_lstnew((const void *)newenv));
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*env;
	t_mini	mini;

	init_mini(&mini);
	mini.dolar = 0;
	env = NULL;
	signal(SIGQUIT, (void (*)(int))sighandler);
	ft_environment(&env, envp);
	ft_printf("minivid > ");
	ft_save_stdio(&mini);
	signal(SIGINT, (void (*)(int))sighandler);
	bucle_main(&mini, &env, envp);
	ft_lstclear(&env, ft_kill_env);
	(void)argc;
	(void)argv;
}
