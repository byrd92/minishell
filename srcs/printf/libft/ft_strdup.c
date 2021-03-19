/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:08:08 by lvarela           #+#    #+#             */
/*   Updated: 2019/11/27 21:20:11 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!(s2 = malloc(ft_strlen(s1) + 1)))
		return (NULL);
	ft_memcpy(s2, s1, ft_strlen(s1));
	s2[ft_strlen(s1)] = '\0';
	return (s2);
}
