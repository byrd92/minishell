/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:38:47 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/25 15:38:31 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*s;
	char			*scpy;
	size_t			bytes;
	size_t			i;

	bytes = count * size;
	if (!(s = malloc(bytes)))
		return (NULL);
	scpy = (char *)s;
	i = -1;
	while (++i < bytes)
		scpy[i] = 0;
	return (s);
}
