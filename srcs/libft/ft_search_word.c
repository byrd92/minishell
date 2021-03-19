/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:47:48 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/20 11:28:11 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Funcion que busca una palabra con caracteres alphanumericos en una string
*/

char			*ft_search_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (!ft_isalnum(*str))
		str++;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}
