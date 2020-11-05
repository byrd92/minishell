/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:32:22 by aortega-          #+#    #+#             */
/*   Updated: 2020/02/14 13:20:56 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ullnum_length(unsigned long long n, int b)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= b;
		i++;
	}
	return (i);
}

int			put_ullnbr(unsigned long long nb, char *base, char *str, int l)
{
	int	b;

	b = ft_strlen(base);
	if (l == 0)
	{
		str[l] = base[nb % b];
		return (0);
	}
	else
	{
		str[l] = base[nb % b];
		return (put_ullnbr(nb / b, base, str, --l));
	}
}

char		*ft_ulltoa_base(unsigned long long nbr, char *base)
{
	int		b;
	char	*str;
	int		l;

	if (nbr <= 0)
		return ("0");
	b = ft_strlen(base);
	l = ullnum_length(nbr, b);
	if (!(str = malloc(sizeof(char) * l + 1)))
		return (0);
	str[l] = '\0';
	put_ullnbr(nbr, base, str, l - 1);
	return (str);
}
