/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:48:57 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/20 11:39:35 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *node;

	if (alst != NULL)
	{
		node = *alst;
		if (*alst == NULL)
			*alst = new;
		else
		{
			while (node->next)
				node = node->next;
			node->next = new;
		}
	}
}
