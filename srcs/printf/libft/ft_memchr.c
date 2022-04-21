/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:44:17 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/06 13:23:41 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*new_s;

	new_s = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (new_s[i] == (unsigned char)c)
		{
			return (&new_s[i]);
		}
		i++;
	}
	return (NULL);
}
