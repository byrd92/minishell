/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:47:42 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 11:47:45 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_destroy_mini(t_mini *mini)
{
	ft_reset_io(mini);
	ft_lstclear(&mini->tokens, ft_kill_mini);
	ft_kill_commands(mini);
	free((*mini).commands);
}

int		ft_exit(t_mini *mini, t_list **env, char **content)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (content[i] != NULL)
		i++;
	if (i > 2)
	{
		ft_printf("exit\n bash: exit: too many arguments\n");
		mini->dolar = 1;
	}
	else
	{
		while (i > 1 && ft_isdigit(content[1][j]))
			j++;
		if (i > 1 && content[1][j] && (mini->dolar = 2))
			ft_printf("exit\nbash: exit: : numeric argument required\n");
		j = mini->dolar;
		if (i > 1 && mini->dolar != 2)
			j = ft_atoi(content[1]);
	}
	ft_destroy_mini(mini);
	ft_lstclear(env, ft_kill_env);
	exit(j);
}
