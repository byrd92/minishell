/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:23:28 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/31 10:39:10 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int     ft_dolar(char *comand, t_mini *mini)
{
	int i;

	i = 0;
	while ((ft_isalpha(comand[i] == 0)) && comand[i])
		i++;
	if (ft_strncmp(&comand[i], "echo ", 5))
	{
		while (ft_isalpha(comand[i] != '$') && comand[i])
			i++;
		if (comand[i] && comand[i + 1] == '?')
		{
			ft_printf("%d", mini->dolar);
			return (1);
		}
	}
	return (0);
}