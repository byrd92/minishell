/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:21:48 by lvarela           #+#    #+#             */
/*   Updated: 2019/11/20 18:18:31 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char *)src;
	y = (unsigned char *)dst;
	if (x == 0 && y == 0)
		return (NULL);
	if (x > y)
		while (len-- > 0)
			*y++ = *x++;
	else
		while (len-- > 0)
			y[len] = x[len];
	return (dst);
}
