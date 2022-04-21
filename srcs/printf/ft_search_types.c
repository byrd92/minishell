/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:39:34 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/18 12:57:42 by jalcayne         ###   ########.fr       */
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
