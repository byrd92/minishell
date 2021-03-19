/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:23:56 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/20 11:30:35 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *list;
	t_list *temp;
	t_list *node;

	if (lst)
	{
		temp = lst;
		if (!(list = ft_lstnew(f(temp->content))))
			return (NULL);
		temp = temp->next;
		while (temp)
		{
			if (!(node = ft_lstnew(f(temp->content))))
			{
				ft_lstclear(&list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, node);
			temp = temp->next;
		}
		return (list);
	}
	return (NULL);
}
