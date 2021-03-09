/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:24:18 by jalcayne          #+#    #+#             */
/*   Updated: 2021/03/09 10:16:27 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			ft_kill_commands(t_mini *mini)
{
	int i;

	i = 0;
	while ((mini->commands)[i])
	{
		free((mini->commands)[i]);
		i++;
	}	
}

void			ft_kill_env(void *content)
{
	t_env *env;
	
	env = (t_env *)content;
	free(env->name);
	free(env->value);
	free(env);
}

void			ft_kill_mini(void *content)
{
	t_token *mini;
	int i;

	mini = (t_token *)content;
	i = 0;
	while (mini->argv[i])
	{
		free(mini->argv[i]);
		i++;
	}
	free(mini->argv);
	free(mini);
}

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