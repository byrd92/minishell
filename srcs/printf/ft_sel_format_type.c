/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sel_format_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:39:54 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/21 16:05:15 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_sel_format_type(char type, va_list ap, t_flags flags)
{
	int ret;

	if (type == 'c')
		ret = ft_type_c(ap, flags);
	else if (type == 's')
		ret = ft_type_s(ap, flags);
	else if (type == 'd' || type == 'i')
		ret = ft_type_di(ap, flags);
	else if (type == 'u')
		ret = ft_type_u(ap, flags);
	else if (type == 'x')
		ret = ft_type_x(ap, flags, "0123456789abcdef");
	else if (type == 'X')
		ret = ft_type_x(ap, flags, "0123456789ABCDEF");
	else if (type == 'p')
		ret = ft_type_p(ap, flags);
	else if (type == '%')
		ret = ft_type_cent(flags);
	else
		ret = 0;
	return (ret);
}

int		ft_adjust(int width, char c)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
