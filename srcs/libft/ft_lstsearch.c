/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:14:33 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/18 17:14:41 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsearch(t_list *lst, int (*f)(void *, void *), void *to_search)
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
			if (f(ptr->content, to_search) > 0)
				return(1);
			ptr = ptr->next;
		}
		if (f(ptr->content, to_search) > 0)
			return(1);
	}
	return (0);
}
