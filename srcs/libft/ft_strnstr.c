/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:19:56 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/25 15:37:50 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_substr(const char *h, const char *n, size_t len, int i)
{
	int j;

	j = 0;
	while ((h[i] == n[j] || n[j] == '\0') && len != 0)
	{
		if (n[j] == '\0')
			return (1);
		j++;
		i++;
		len--;
	}
	if (n[j] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ret;
	int			i;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] && len != 0)
	{
		if (haystack[i] == needle[0])
		{
			ret = &haystack[i];
			if (check_substr(haystack, needle, len, i))
				return ((char *)ret);
		}
		len--;
	}
	return (0);
}
