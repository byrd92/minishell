/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chema <chema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:57:09 by jalcayne          #+#    #+#             */
/*   Updated: 2020/03/25 11:50:18 by chema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strsub_get(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (s == NULL)
		return (NULL);
	subs = ft_strnew_get(len);
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	return (subs);
}

int		ft_strlen_get(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_get(char const *s1, char const *s2)
{
	char	*conc;
	int		conclen;
	int		i;
	int		o;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	conclen = ft_strlen_get(s1) + ft_strlen_get(s2) + 1;
	if (!(conc = malloc(sizeof(char) * conclen)))
		return (NULL);
	i = -1;
	while (s1[++i])
		conc[i] = s1[i];
	o = -1;
	while (s2[++o])
		conc[i++] = s2[o];
	conc[i] = '\0';
	return (conc);
}

char	*ft_strnew_get(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strdup_get(const char *s1)
{
	char	*ptr;
	int		i;
	int		len;

	len = ft_strlen_get((char *)s1);
	if (!(ptr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i += 1;
	}
	ptr[i] = '\0';
	return (ptr);
}
