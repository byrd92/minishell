/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:38:34 by jalcayne          #+#    #+#             */
/*   Updated: 2021/03/16 18:52:21 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_kill_commands(t_mini *mini)
{
	int i;

	i = 0;
	while ((mini->commands)[i])
	{
		free((mini->commands)[i]);
		i++;
	}
}

void		ft_kill_env(void *content)
{
	t_env *env;

	env = (t_env *)content;
	free(env->name);
	free(env->value);
	free(env);
}

void		ft_kill_mini(void *content)
{
	t_token	*mini;
	int		i;

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
