/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:13:09 by egarcia-          #+#    #+#             */
/*   Updated: 2020/12/22 15:06:14 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_strldup(char *str, int size)
{
	char *ret;
	int i;

	i = -1;
	ret = malloc(sizeof(char *) * size + 1);
	while (++i < size)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}


char		**ft_split_mini(char *str)
{
	char **array;
	int i;
	int size;
	int len;
	
	i = 0;
	size = argc_size(str);
	array = malloc(sizeof(char *) * size + 1);
	while ( i < size)
	{
		str += skip_space(str);
		len = ft_strlen_arg(str);
		array[i] = ft_strldup(str, len);
		rm_token(&(array[i]));
		str += len;
		i++;
	}
	array[i] = 0;
	return (array);
}



void			*ft_lstsearch_content(t_list *lst, int (*f)(void *, void *), void *to_search)
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
				return(ptr->content);
			ptr = ptr->next;
		}
		if (f(ptr->content, to_search) > 0)
			return(ptr->content);
	}
	return (NULL);
}
