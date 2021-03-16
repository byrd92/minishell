/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:23:28 by jalcayne          #+#    #+#             */
/*   Updated: 2021/03/16 11:55:37 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_dolar(char *comand, t_mini *mini)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while ((ft_isalpha(comand[i] == 0)) && comand[i])
		i++;
	if ((ft_strncmp(&comand[i], "echo ", 5) == 0))
	{
		while ((comand[i] != '$') && comand[i])
		{
			if (comand[i] == '-' && comand[i + 1] == 'n')
				flag = 1;
			i++;
		}
		if (comand[i] && comand[i + 1] == '?')
		{
			if (flag)
				ft_printf("%d", mini->dolar);
			else
				ft_printf("%d\n", mini->dolar);
			return (1);
		}
	}
	return (0);
}
