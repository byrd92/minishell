/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chema <chema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:34:01 by jalcayne          #+#    #+#             */
/*   Updated: 2020/01/03 14:36:55 by chema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	i = 0;
	if (new_dst != NULL || new_src != NULL)
	{
		while (n--)
		{
			new_dst[i] = new_src[i];
			i++;
		}
		return (dst);
	}
	return (NULL);
}
