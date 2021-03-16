/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:44:13 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 18:01:20 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		end_quote(char *str, int quote)
{
	int i;

	i = 1;
	if (str[i] == 34 || str[i] == 39)
		i++;
	while (str[i] != quote)
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int				argc_size(char *str)
{
	int i;
	int quote;
	int words;

	words = 1;
	i = 0;
	i += skip_space(str);
	while (str[i])
	{
		if (str[i] == ' ' &&  str[i + 1] && str[i + 1] != ' ')
		{
			i += skip_space(&str[i]);
			if (str[i] == 34 || str[i] == 39)
			{
				quote = str[i] == 34 ? 34 : 39;
				i += end_quote(&str[i] , quote);
			}
			words++;
		}
		else
			i++;
	}
	return (words);
}

int				ft_strlen_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int				ft_strlen_arg(char *str)
{
	int i;

	i = 0;
	if (str[i] == '<' || str[i] == '>' || str[i] == '|')
		i = (str[i] == '>' && str[i + 1] == '>') ? 2 : 1;
	else
	{
		while (str[i] && !ft_isspace(str[i]) && str[i] != '<' &&
		str[i] != '>' && str[i] != '|')
		{
			if (str[i] == '\'' || str[i] == '"')
			{
				i++;
				i += ft_strlen_char(str + i, str[i - 1]);
				if (!(str[i]))
					return (i);
			}
			i++;
		}
	}
	return (i);
}

int				ft_strlen_env(char *str)
{
	int i;

	i = 1;
	if (str[i] == ' ')
		return (0);
	while (str[i] && str[i] != '\'' && str[i] != '"' &&
			str[i] != ' ' && str[i] != '$')
		i++;
	return (i);
}
