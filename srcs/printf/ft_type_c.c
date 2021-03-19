/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:04:13 by llopez-d          #+#    #+#             */
/*   Updated: 2020/10/14 19:04:19 by llopez-d         ###   ########.fr       */
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
