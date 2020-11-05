/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:01:14 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/21 15:54:00 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_type_c(va_list ap, t_flags flags)
{
	if (flags.justify < 0 && flags.justify != 0)
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		ft_adjust((flags.justify * -1) - 1, ' ');
		return (flags.justify * -1);
	}
	else if (flags.justify > 0 && flags.justify != 0)
		ft_adjust(flags.justify - 1, ' ');
	ft_putchar_fd(va_arg(ap, int), 1);
	if (flags.justify > 1)
		return (flags.justify);
	return (1);
}
