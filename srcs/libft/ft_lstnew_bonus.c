/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:01:28 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/20 11:38:01 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*nodo;

	if (!(nodo = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	nodo->content = (void *)content;
	nodo->next = NULL;
	return (nodo);
}
