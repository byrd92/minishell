/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_cent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:55:18 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/19 10:16:01 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_type_cent(t_flags flags)
{
	int		ret;

	ret = 0;
	if (flags.justify < 0)
	{
		ft_putchar_fd('%', 1);
		if (flags.zero)
			ret += ft_adjust((flags.justify * -1) - 1, '0');
		else
			ret = ft_adjust((flags.justify * -1) - 1, ' ');
	}
	else
	{
		if (flags.zero)
			ret += ft_adjust(flags.justify - 1, '0');
		else
			ret = ft_adjust(flags.justify - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (ret + 1);
}
