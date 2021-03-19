/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:12:23 by lvarela           #+#    #+#             */
/*   Updated: 2019/11/20 18:16:38 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	unsigned char	same;
	size_t			i;

	x = (unsigned char *)src;
	y = (unsigned char *)dst;
	same = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		y[i] = x[i];
		i++;
		if (x[i - 1] == same)
			return (&y[i]);
	}
	return (NULL);
}
