/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:16:46 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/18 19:06:17 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



void		ft_lstdelmiddle(t_list **lst, int (*f)(void *, void *), void *to_search)
{
	t_list	*ptr;
	t_list	*prevptr;
	t_list	*next;
	
	ptr = *lst;
	prevptr = NULL;

	if (lst == NULL)
	{
	}
	else
	{
		while (ptr->next)
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
		if (f(ptr->content, to_search) > 0)
		{
				next = ptr->next;
				ft_lstdelone(ptr, ft_kill_env);
				prevptr->next = next;
				return ;
		}
	}
	return ;
}

int			ft_unset(t_list **env, char *str)
{
	char	*word;

	word = ft_search_word(str);

	ft_lstdelmiddle(env,ft_search_env,word);

	return (0);
}