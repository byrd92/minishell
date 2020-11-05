/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:59:21 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/19 11:03:44 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_int_adjust(t_flags flags, int len, int num)
{
	int ret;

	ret = 0;
	if (flags.justify < 0)
		flags.justify = flags.justify * -1;
	if (flags.zero)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			ret++;
		}
		ret += ft_adjust(flags.justify - len, '0');
	}
	else if (flags.precision >= len)
	{
		if (num < 0)
			ret += ft_adjust(flags.justify - flags.precision - 1, ' ');
		else
			ret += ft_adjust(flags.justify - flags.precision, ' ');
	}
	else
		ret += ft_adjust(flags.justify - len, ' ');
	return (ret);
}

int	ft_int_precision(t_flags flags, int len, int num)
{
	int	i;
	int rtn;

	i = 0;
	rtn = 0;
	if (num < 0 && flags.precision < len && !flags.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (flags.precision > 0)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			rtn++;
			i--;
		}
		while (i++ < flags.precision - len)
		{
			write(1, "0", 1);
			rtn++;
		}
	}
	return (rtn);
}

int	ft_int_minus(t_flags flags, int len, char *str, int num)
{
	int	rtn;

	rtn = 0;
	if (num < 0)
		str++;
	if (flags.justify < 0)
	{
		rtn += ft_int_precision(flags, len, num);
		rtn += ft_putstrprint_fd(str, 1);
		rtn += ft_int_adjust(flags, len, num);
	}
	else
	{
		rtn += ft_int_adjust(flags, len, num);
		rtn += ft_int_precision(flags, len, num);
		rtn += ft_putstrprint_fd(str, 1);
	}
	return (rtn);
}

int	ft_putstrprint_fd(char *str, int fd)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		write(fd, &str[i++], 1);
	return (i);
}
