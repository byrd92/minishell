/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:39:42 by lvarela           #+#    #+#             */
/*   Updated: 2019/11/20 18:14:35 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	size_t			i;

	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	i = 0;
	if (!n || src == dst)
		return (dst);
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}
