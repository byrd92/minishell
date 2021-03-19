/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:28:14 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/06 15:30:57 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			init_mini(t_mini *mini)
{
	mini->commands = NULL;
	mini->tokens = NULL;
	mini->in = 0;
	mini->out = 0;
	mini->newin = 0;
	mini->newout = 0;
	mini->strcmd = NULL;
	mini->dolar = 0;
}

static	void	ft_reset(t_mini *mini)
{
	ft_reset_io(mini);
	ft_lstclear(&mini->tokens, ft_kill_mini);
	ft_kill_commands(mini);
	init_mini(mini);
}

void			starter(t_mini *mini, t_list *env, char **envp)
{
	int i;
	int pipes;

	g_salir_d = 0;
	i = 0;
	while (mini->commands[i])
	{
		if (ft_dolar(mini->commands[i], mini))
			i++;
		else
		{
			ft_parse_commands(mini, &env, i);
			ft_check_io(mini);
			pipes = ft_check_pipes(mini->tokens);
			if (pipes)
				mini->dolar = ft_forker(mini, pipes, &env, envp);
			else
				mini->dolar = ft_select_build_function(mini, &env, envp);
			i++;
			ft_lstclear(&mini->tokens, ft_kill_mini);
		}
	}
	ft_reset(mini);
	ft_printf("minivid > ");
}

int				main(int argc, char **argv, char **envp)
{
	t_list	*env;
	t_mini	mini;

	init_mini(&mini);
	env = NULL;
	signal(SIGQUIT, &sighandler);
	ft_environment(&env, envp);
	ft_printf("minivid > ");
	ft_save_stdio(&mini);
	signal(SIGINT, &sighandler);
	while (ft_read_commands(&mini))
		starter(&mini, env, envp);
	ft_destroy_mini(&mini);
	ft_lstclear(&env, ft_kill_env);
	(void)argc;
	(void)argv;
	ft_putstr_fd("exit\n", 1);
	return (0);
}
