/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:11:15 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/17 09:48:46 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	ptr = lst;
	if (lst == NULL)
	{
	}
	else
	{
		while (ptr->next)
		{
			f(ptr->content);
			ptr = ptr->next;
		}
		f(ptr->content);
	}
}
