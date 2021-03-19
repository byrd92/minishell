/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:04:56 by lvarela           #+#    #+#             */
/*   Updated: 2019/11/20 18:09:56 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*y;
	size_t			i;

	y = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (y[i] == (unsigned char)c)
			return (&y[i]);
		i++;
	}
	return (NULL);
}
