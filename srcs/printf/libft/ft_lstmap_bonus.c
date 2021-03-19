/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:30:39 by lvarela           #+#    #+#             */
/*   Updated: 2019/12/17 18:06:01 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*now;
	t_list	*after;

	if (lst)
	{
		now = lst;
		if (!(map = ft_lstnew(f(now->content))))
			return (NULL);
		now = now->next;
		while (now)
		{
			if (!(after = ft_lstnew(f(now->content))))
			{
				ft_lstclear(&map, del);
				return (NULL);
			}
			ft_lstadd_back(&map, after);
			now = now->next;
		}
		return (map);
	}
	return (NULL);
}
