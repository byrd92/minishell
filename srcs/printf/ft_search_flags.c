/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:02:25 by llopez-d          #+#    #+#             */
/*   Updated: 2020/10/14 19:02:38 by llopez-d         ###   ########.fr       */
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

static int		ft_minus(char *format, int *i, va_list ap)
{
	int		ret;

	*i = *i + 1;
	while (format[*i] == '0' && format[*i] != '\0')
		*i = *i + 1;
	if (format[*i] == '*' && format[*i] != '\0')
	{
		ret = va_arg(ap, int);
		if (ret > 0)
			ret = ret * -1;
	}
	else
	{
		ret = ft_atoi(&format[*i]);
		ret = ret * -1;
	}
	while ((format[*i] == '*' || (format[*i] >= '0' && format[*i] <= '9'))
			&& format[*i + 1] != '\0')
		*i = *i + 1;
	return (ret);
}

static int		ft_search_justify(va_list ap, char *format, int *i)
{
	int ret;

	ret = 0;
	while (format[*i] == '0' && format[*i] != '\0')
		*i = *i + 1;
	if (format[*i] == '-')
	{
		ret = ft_minus(format, i, ap);
	}
	else
	{
		if (format[*i] == '*')
			ret = va_arg(ap, int);
		else
			ret = ft_atoi(&format[*i]);
		while ((format[*i] == '*' || (format[*i] >= '0' && format[*i] <= '9'))
				&& format[*i + 1] != '\0')
			*i = *i + 1;
	}
	return (ret);
}

static int		ft_search_precision(va_list ap, char *format, int *i)
{
	int ret;

	ret = -1;
	if (format[*i] == '.')
	{
		*i = *i + 1;
		while (format[*i] == '0')
			*i = *i + 1;
		if (format[*i] == '*')
			ret = va_arg(ap, int);
		else
			ret = ft_atoi(&format[*i]);
		if (ret < 0)
			ret = -1;
		while (format[*i] == '*' || (format[*i] >= '0' && format[*i] <= '9'))
			*i = *i + 1;
	}
	return (ret);
}

t_flags			ft_search_flags(va_list ap, char *format, int *i)
{
	t_flags flags;

	flags = ft_reset_flags();
	if (format[*i] == '0')
	{
		flags.zero = 1;
		*i = *i + 1;
	}
	flags.justify = ft_search_justify(ap, format, i);
	flags.precision = ft_search_precision(ap, format, i);
	return (flags);
}
