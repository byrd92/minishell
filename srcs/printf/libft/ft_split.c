/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:12:37 by lvarela           #+#    #+#             */
/*   Updated: 2019/12/17 18:09:21 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_words(char const *s, char c)
{
	static int		i;
	static int		n_words;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		n_words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n_words);
}

static int	ft_size_next_word(char const *s, char c, int i)
{
	int				size;

	while (s[i] == c && s[i])
		i++;
	size = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			return (size);
		size++;
		i++;
	}
	return (size);
}

static int	ft_save_word(char *str, char const *s, char c, int i)
{
	int				j;

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
		i++;
		j++;
	}
	str[j] = '\0';
	return (i);
}

char		**ft_split(char const *s, char c)
{
	int				total;
	int				j;
	int				i;
	char			**tab;

	if (s == NULL)
		return (NULL);
	total = ft_n_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (total + 1))))
		return (NULL);
	tab[total] = NULL;
	i = 0;
	j = 0;
	while (j < total)
	{
		if (!(tab[j] = malloc(sizeof(char) * (ft_size_next_word(s, c, i) + 1))))
			return (NULL);
		i = ft_save_word(tab[j], s, c, i);
		j++;
	}
	return (tab);
}
