/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:24:10 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/20 11:31:48 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	ptr = lst;
	counter = 0;
	while (ptr->next)
	{
		ptr = ptr->next;
		counter++;
	}
	return (counter + 1);
}
