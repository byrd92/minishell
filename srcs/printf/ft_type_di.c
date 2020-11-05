/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:03:52 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/21 16:05:30 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_type_di(va_list ap, t_flags flags)
{
	int		num;
	char	*str;
	int		len;
	int		ret;

	num = va_arg(ap, int);
	str = ft_itoa(num);
	len = ft_strlen(str);
	ret = 0;
	if (flags.zero && ((flags.justify < 0) || (flags.precision >= 0)))
		flags.zero = 0;
	if (flags.precision == 0 && *str == '0')
	{
		if (flags.justify < 0)
			ret += ft_adjust(flags.justify * -1, ' ');
		else
			ret += ft_adjust(flags.justify, ' ');
		return (ret);
	}
	ret += ft_int_minus(flags, len, str, num);
	free(str);
	return (ret);
}
