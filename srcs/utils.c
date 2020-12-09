/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:13:09 by egarcia-          #+#    #+#             */
/*   Updated: 2020/12/09 23:15:44 by egarcia-         ###   ########.fr       */
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

	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			quote = str[i] == 34 ?  34 : 39;
			i++;
			while (str[i] != quote && str[i])
				i++;
			words++;
		}
		if (str[i] == c)
			words++;
		i++;
	}
	return (words);
}

char		*ft_strdup_sep(char *str, int c)
{
	char *ret;
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	ret = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (str[i] != c && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_split_mini(char *str, int c)
{
	char **array;
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 34 || str[i] == 39)
	{
		array = ft_split(str, '\"');
	}
	else
		array = ft_split(str, c);
	return (array);
}