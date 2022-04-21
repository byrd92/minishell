/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:57:17 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/21 16:05:09 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	ft_reset_flags(void)
{
	t_flags flags;

	flags.zero = 0;
	flags.justify = 0;
	flags.precision = -1;
	flags.type = 0;
	return (flags);
}

static int		ft_format(char *str, va_list ap, t_flags flags, int *i)
{
	int		ret;

	ret = 0;
	*i = *i + 1;
	flags = ft_search_flags(ap, str, i);
	ret = ft_search_type(str, i, ap, flags);
	return (ret);
}

static int		ft_special_putchar(char c)
{
	int rtn;

	rtn = 0;
	if (c != '%')
	{
		write(1, &c, 1);
		rtn++;
	}
	return (rtn);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flags		flags;
	int			i;
	int			ret;
	char		*str;

	str = (char *)format;
	i = 0;
	ret = 0;
	va_start(ap, format);
	while (str[i])
	{
		flags = ft_reset_flags();
		ret += ft_special_putchar(str[i]);
		if (str[i] == '%' && str[i + 1])
		{
			flags = ft_reset_flags();
			ret = ret + ft_format(str, ap, flags, &i);
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
