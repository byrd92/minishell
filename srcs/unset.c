/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:16:46 by jalcayne          #+#    #+#             */
/*   Updated: 2021/03/16 13:37:58 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_lstdelmiddle(t_list **lst,
			int (*f)(void *, void *), void *to_search)
{
	t_list	*ptr;
	t_list	*prevptr;
	t_list	*next;

	ptr = *lst;
	prevptr = NULL;
	if (lst != NULL)
	{
		while (ptr)
		{
			if (f(ptr->content, to_search) > 0)
			{
				next = ptr->next;
				ft_lstdelone(ptr, ft_kill_env);
				prevptr->next = next;
				return ;
			}
			prevptr = ptr;
			ptr = ptr->next;
		}
		return ;
	}
}

int			ft_unset(t_list **env, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
		ft_lstdelmiddle(env, ft_search_env, argv[i++]);
	return (0);
}
