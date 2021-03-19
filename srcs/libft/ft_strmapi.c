/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:58:57 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/25 16:11:10 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcpy1(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*changed;
	int			i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(changed = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strcpy1(changed, s);
	i = 0;
	while (changed[i])
	{
		changed[i] = (*f)(i, changed[i]);
		i++;
	}
	return (changed);
}
