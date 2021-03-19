/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:03:02 by llopez-d          #+#    #+#             */
/*   Updated: 2020/10/14 19:03:14 by llopez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		ft_search_type(char *format, int *i, va_list ap, t_flags flags)
{
	int ret;

	ret = 0;
	if (ft_is_type(format[*i]))
	{
		ret = ft_sel_format_type(format[*i], ap, flags);
	}
	return (ret);
}
