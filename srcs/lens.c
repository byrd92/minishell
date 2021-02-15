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
	/* words es = 1 porque como minimo hay 1 argv) */
	words = 1;
	i = 0;
	//ft_printf("\n-->%s--<\n", str);
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == c)
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
	ft_printf("%d ", words);
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
	while ( str[i] && str[i] != ' ')
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
int		ft_strlen_arg(char *str)
{
	int		i;
	i = 0;
	//if (str[i] == '"' || str[i] == '\'')
	//	i = ft_strlen_char(str + i + 1, str[i]) + 2;
	i = ft_strlen_tokens(str);
	return (i);
}
