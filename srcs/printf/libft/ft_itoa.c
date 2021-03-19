/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:28:19 by lvarela           #+#    #+#             */
/*   Updated: 2019/12/17 18:04:31 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

static char		*ft_fulfill(int n, int i)
{
	char	*str;
	long	nbr;

	nbr = n;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (nbr > 9)
	{
		str[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (nbr < 10)
		str[i--] = (nbr % 10) + '0';
	if (n < 0)
		str[i--] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	if (n == -2147483648)
	{
		if (!(ptr = (char *)malloc(sizeof(char) * 12)))
			return (NULL);
		ft_strlcpy(ptr, "-2147483648", 12);
		return (ptr);
	}
	i = ft_getlen(n);
	ptr = ft_fulfill(n, i);
	return (ptr);
}
