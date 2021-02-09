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
		if (str[i] == 34 || str[i] == 39)
		{
			quote = str[i] == 34 ?  34 : 39;
			i++;
			while (str[i] != quote)
				i++;
			ft_printf("\n->%c-<\n", str[i]);
			words++;
			if (str[i] != ' ' && str[i])
				words--;
			i++;
		}
		else if (str[i] == c)
		{	
			words++;
			while (str[i] == c)
				i++;
		}
		else
			i++;
	}
	ft_printf("%d", words);
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
	int		len;

	len = 0;
	while (*str && *str != ' ')
	{
		if (*str == '\\' && *(str + 1) != '\\')
			len--;
		len++;
		str++;
	}
	if (*str == '=')
		len++;
	return (len);
}

int		ft_strlen_token(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
			i++;
	if (str[i] == '=')
		i++;
	return (i);
}

int	ft_strlen_arg(char *str)
{
	int		i;
	i = 0;
	//if (str[i] == '"' || str[i] == '\'')
	//	i = ft_strlen_char(str + i + 1, str[i]) + 2;
	if (ft_strlen_char(str, ':') < ft_strlen_tokens(str))
		i = ft_strlen(str);
	else
		i = ft_strlen_tokens(str);
	return (i);
}
