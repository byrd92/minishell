/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:05:58 by llopez-d          #+#    #+#             */
/*   Updated: 2020/10/14 19:06:11 by llopez-d         ###   ########.fr       */
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
	char *newstr;

	if (!str && flags.precision)
		newstr = ft_strdup("(null)");
	else if (!str && !flags.precision)
		newstr = ft_strdup("");
	else
	{
		newstr = ft_strdup(str);
	}
	return (newstr);
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
	int		len;
	int		ret;
	int		how;
	int		minus;
	char	*str;

	ret = 0;
	str = str_special(va_arg(ap, char *), flags);
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
	free(str);
	return (ret);
}
