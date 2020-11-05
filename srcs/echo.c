/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:52:52 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/05 17:20:17 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"
void	ft_echo(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if ((ft_strcmp(ft_search_word(&str[i]), "-n")))
	{
		n = 1;
		i += 2;
	}
	while (str[i] == ' ')
		i++;
	if (n == 0)
		ft_printf("%s\n", &str[i]);
	else
	{
		ft_printf("%s", &str[i]);
	}
	

}