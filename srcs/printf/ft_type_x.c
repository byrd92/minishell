/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:06:51 by llopez-d          #+#    #+#             */
/*   Updated: 2020/10/14 19:07:00 by llopez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_hexa_adjust(t_flags flags, int len)
{
	int	ret;
	int minus;

	ret = 0;
	minus = 0;
	if (flags.justify < 0)
	{
		minus = 1;
		flags.justify = flags.justify * -1;
	}
	if (flags.zero && !minus && flags.precision < 0)
		ret += ft_adjust(flags.justify - len, '0');
	else if (flags.precision >= len)
		ret += ft_adjust(flags.justify - flags.precision, ' ');
	else
		ret += ft_adjust(flags.justify - len, ' ');
	return (ret);
}

static int		ft_hexa_precision(int precision, int len)
{
	int	i;

	i = 0;
	if (precision)
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	return (i);
}

static int		ft_hexa_minus(t_flags flags, int len, char *str)
{
	int	rtn;

	rtn = 0;
	if (flags.justify < 0)
	{
		rtn += ft_hexa_precision(flags.precision, len);
		rtn += ft_putstrprint_fd(str, 1);
		rtn += ft_hexa_adjust(flags, len);
	}
	else
	{
		rtn += ft_hexa_adjust(flags, len);
		rtn += ft_hexa_precision(flags.precision, len);
		rtn += ft_putstrprint_fd(str, 1);
	}
	return (rtn);
}

int				ft_type_x(va_list ap, t_flags flags, char *base)
{
	char			*str;
	int				len;
	int				ret;
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	if (!num)
		str = ft_strdup("0");
	else
		str = ft_ulltoa_base(num, base);
	len = ft_strlen(str);
	ret = 0;
	if (flags.precision == 0 && *str == '0')
	{
		if (flags.justify < 0)
			ret += ft_adjust(flags.justify * -1, ' ');
		else
			ret += ft_adjust(flags.justify, ' ');
		free(str);
		return (ret);
	}
	ret += ft_hexa_minus(flags, len, str);
	free(str);
	return (ret);
}
