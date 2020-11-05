/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:41:47 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/25 15:00:25 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static int		size_nextword(char const *s, char c, int i)
{
	int counter;

	while (s[i] == c && s[i])
		i++;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (counter);
		counter++;
		i++;
	}
	return (counter);
}

static int		save_word(char *str, char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			str[j] = '\0';
			return (i);
		}
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (i);
}

static char		**ft_split2(char const *s, char c, int max)
{
	int		j;
	char	**tab;
	int		i;

	i = ft_countwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	max = i;
	i = 0;
	j = 0;
	while (j < max)
	{
		if (!(tab[j] = malloc(sizeof(char) * (size_nextword(s, c, i) + 1))))
			return (NULL);
		i = save_word(tab[j], s, c, i);
		j++;
	}
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	int max;

	if (s == NULL)
		return (NULL);
	max = 0;
	return (ft_split2(s, c, max));
}
