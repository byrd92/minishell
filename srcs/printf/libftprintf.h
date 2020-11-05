/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:31:34 by jalcayne          #+#    #+#             */
/*   Updated: 2020/02/19 11:35:30 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	int			justify;
	int			zero;
	int			precision;
	char		type;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_search_type(char *format, int *i, va_list ap, t_flags flags);
t_flags			ft_search_flags(va_list ap, char *format, int *i);
int				ft_sel_format_type(char type, va_list ap, t_flags flags);
char			*ft_utoa(unsigned int n);
char			*ft_ulltoa_base(unsigned long long nbr, char *base);
int				ft_adjust(int width, char c);
int				ft_int_minus(t_flags flags, int len, char *str, int nb);
int				ft_putstrprint_fd(char *str, int fd);
int				ft_is_type(char c);
int				ft_type_c(va_list ap, t_flags flags);
int				ft_type_s(va_list ap, t_flags flags);
int				ft_type_di(va_list va, t_flags flags);
int				ft_type_u(va_list ap, t_flags flags);
int				ft_type_x(va_list ap, t_flags flags, char *base);
int				ft_type_p(va_list ap, t_flags flags);
int				ft_type_cent(t_flags flags);

#endif
