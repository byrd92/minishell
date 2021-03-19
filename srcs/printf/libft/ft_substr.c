/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:04:38 by lvarela           #+#    #+#             */
/*   Updated: 2019/12/02 20:15:42 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*x;

	if (s == NULL)
		return (NULL);
	if (!(x = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(x, len + 1);
	if (start <= ft_strlen(s))
		ft_strlcpy(x, s + start, len + 1);
	return (x);
}
