/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:44:01 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/17 12:22:51 by jalcayne         ###   ########.fr       */
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
	while (ft_isalnum(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (ft_isalnum(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}