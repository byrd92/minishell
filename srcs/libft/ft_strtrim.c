/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:49:20 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/25 14:59:54 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_start(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	boolean;

	i = -1;
	boolean = 'T';
	while (boolean == 'T')
	{
		boolean = 'F';
		i++;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				boolean = 'T';
			j++;
		}
	}
	return (i);
}

static int		set_end(char const *s1, char const *set, int start)
{
	int		i;
	int		j;
	char	boolean;

	i = 0;
	while (s1[i])
		i++;
	i = i == 0 ? 0 : i - 1;
	boolean = 'T';
	while (start < i && boolean == 'T')
	{
		boolean = 'F';
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i--;
				boolean = 'T';
			}
			j++;
		}
	}
	return (i);
}

static char		*trim(char const *s1, int start, int end)
{
	char	*trimmed;
	int		i;
	int		o;

	if (!(trimmed = malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = start;
	o = 0;
	while (i <= end)
	{
		trimmed[o] = s1[i];
		i++;
		o++;
	}
	trimmed[o] = '\0';
	return (trimmed);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
	{
		if (!(trimmed = malloc(sizeof(char) * 1)))
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	start = set_start(s1, set);
	end = set_end(s1, set, start);
	trimmed = trim(s1, start, end);
	return (trimmed);
}
