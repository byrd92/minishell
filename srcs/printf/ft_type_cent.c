/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_cent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:04:40 by llopez-d          #+#    #+#             */
/*   Updated: 2020/10/14 19:04:51 by llopez-d         ###   ########.fr       */
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
