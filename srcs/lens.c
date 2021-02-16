/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:44:13 by egarcia-          #+#    #+#             */
/*   Updated: 2020/12/16 17:36:00 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			argv_size(char *str, int c)
{
	int i;
	int quote;
	int words;

	quote = 0;
	words = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1])
		{
			while (str[i] == c)
				i++;
			if (str[i] == 34 || str[i] == 39)
			{
				quote = str[i] == 34 ?  34 : 39;
				i++;
				while (str[i] != quote)
					i++;
				while (str[i] && str[i] != c)
					i++;
			}
			words++;
		}
		else
			i++;
	}
	return (words);
}

int		ft_strlen_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		ft_strlen_tokens(char *str)
{
	int		i;
	int		quote;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == 34 || str[i] == 39)
			{
				quote = str[i] == 34 ?  34 : 39;
				i++;
				while (str[i] != quote)
					i++;
				while (str[i] && str[i] != ' ')
					i++;
				return (i);
			}
		i++;
	}
	return (i);
}

int		ft_strlen_env(char *str)
{
	int i;

	i = 0;

	if (str[i] == ' ')
		return (0);
	while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != ' ')
		i++;
	return (i); 
}

