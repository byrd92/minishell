/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:35:37 by lvarela           #+#    #+#             */
/*   Updated: 2019/11/26 21:06:53 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*aux;

	aux = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (aux[i] == (char)c)
			return (&aux[i]);
		i--;
	}
	return (0);
}
