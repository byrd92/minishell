/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:28:51 by lvarela           #+#    #+#             */
/*   Updated: 2019/12/04 15:54:24 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *to_find)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		k = 0;
		while (to_find[k])
		{
			if (s1[i] == to_find[k])
				i++;
			if (s1[i] != to_find[k])
				k++;
		}
		j++;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *to_find)
{
	int		i;
	int		j;
	int		k;
	int		o;

	i = (int)ft_strlen(s1) - 1;
	j = 0;
	o = 0;
	k = 0;
	while (s1[o])
	{
		while (to_find[k])
		{
			if (s1[i - j] == to_find[k])
			{
				j++;
				k = 0;
			}
			if (s1[i - j] != to_find[k])
				k++;
		}
		o++;
	}
	return (j);
}

char		*ft_yeswecan(char const *s1, int start, int end)
{
	int			i;
	int			space;
	char		*str;

	i = 0;
	space = (int)ft_strlen(s1) - start - end + 1;
	if (!(str = (char *)malloc(sizeof(char) * space)))
		return (NULL);
	while (s1[start] && (start <= ((int)ft_strlen(s1) - end - 1)))
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = ft_start(s1, set);
	if (start == (int)ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_end(s1, set);
	return (ft_yeswecan(s1, start, end));
}
