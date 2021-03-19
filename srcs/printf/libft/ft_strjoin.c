/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:51:39 by lvarela           #+#    #+#             */
/*   Updated: 2019/12/13 15:41:17 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*finals;
	unsigned int	ns;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ns = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = -1;
	j = -1;
	if (!(finals = (char *)malloc(sizeof(char) * ns)))
		return (NULL);
	ft_bzero(finals, ns);
	while (s1[++i])
		finals[i] = s1[i];
	while (s2[++j])
		finals[i++] = s2[j];
	finals[i] = '\0';
	return (finals);
}
