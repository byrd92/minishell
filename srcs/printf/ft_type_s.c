/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:48:29 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/21 16:05:36 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		ft_str_precision(char *str, int len, int precision, int mod)
{
	int	i;

	i = 0;
	if (precision != -1 && len <= precision)
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else if (precision != -1 && len > precision)
		while (i < precision)
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	return (i);
}

static int		str_adjust(int zero, int width)
{
	int rtn;

	rtn = 0;
	if (zero)
		rtn += ft_adjust(width, '0');
	else
		rtn += ft_adjust(width, ' ');
	return (rtn);
}

static char		*str_special(char *str, t_flags flags)
{
	if (!str && flags.precision)
		str = ft_strdup("(null)");
	else if (!str && !flags.precision)
		str = ft_strdup("");
	return (str);
}

static int		ft_minus(t_flags *flags)
{
	int minus;

	minus = 0;
	if (flags->justify < 0)
	{
		minus = 1;
		flags->justify = flags->justify * -1;
	}
	return (minus);
}

int				ft_type_s(va_list ap, t_flags flags)
{
	char	*str;
	int		len;
	int		ret;
	int		how;
	int		minus;

	ret = 0;
	str = va_arg(ap, char *);
	str = str_special(str, flags);
	len = ft_strlen(str);
	how = ft_str_precision(str, len, flags.precision, 0);
	minus = ft_minus(&flags);
	if (minus && flags.justify > how)
	{
		ret += ft_str_precision(str, len, flags.precision, 1);
		ret += str_adjust(flags.zero, (flags.justify - how));
	}
	else if (!minus && flags.justify > how)
	{
		ret += str_adjust(flags.zero, (flags.justify - how));
		ret += ft_str_precision(str, len, flags.precision, 1);
	}
	else
		ret += ft_str_precision(str, len, flags.precision, 1);
	return (ret);
}
