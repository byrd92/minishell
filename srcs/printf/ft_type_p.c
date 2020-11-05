/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:25:32 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/21 15:53:49 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_pos_minus(t_flags flags, int len, char *str)
{
	int	ret;

	ret = 0;
	if (flags.justify < 0)
	{
		ret += ft_putstrprint_fd("0x", 1);
		ret += ft_putstrprint_fd(str, 1);
		ret += ft_adjust((flags.justify * -1) - (len + 2), ' ');
	}
	else
	{
		ret += ft_adjust(flags.justify - (len + 2), ' ');
		ret += ft_putstrprint_fd("0x", 1);
		ret += ft_putstrprint_fd(str, 1);
	}
	return (ret);
}

int			ft_type_p(va_list ap, t_flags flags)
{
	char				*str;
	int					len;
	int					ret;
	unsigned long long	num;

	num = va_arg(ap, unsigned long long);
	if (!num)
		str = ft_strdup("0");
	else
		str = ft_ulltoa_base(num, "0123456789abcdef");
	len = ft_strlen(str);
	ret = 0;
	ret += ft_pos_minus(flags, len, str);
	free(str);
	return (ret);
}
