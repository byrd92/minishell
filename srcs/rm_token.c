/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:08:08 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 13:08:21 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		rm_char(char **str, int j)
{
	char *start;
	char *aux;

	start = ft_strldup(*str, j);
	aux = ft_strdup(*str + j + 1);
	free(*str);
	*str = ft_strjoin(start, aux);
	free(aux);
	free(start);
}

int			is_token(char c)
{
	if (c == '"' || c == '\\')
		return (1);
	return (0);
}

void		rm_backslash(char **arg, int *i)
{
	while ((*arg)[*i])
	{
		if ((*arg)[*i] == '\\' && is_token((*arg)[*i + 1]))
			rm_char(arg, *i);
		else if ((*arg)[*i] == '"')
			break ;
		(*i)++;
	}
}

void		rm_token(char **argv)
{
	int		i;

	i = 0;
	while ((*argv)[i])
	{
		if ((*argv)[i] == '\'')
		{
			rm_char(argv, i);
			i += ft_strlen_char(*argv + i, '\'');
			rm_char(argv, i);
		}
		else if ((*argv)[i] == '"')
		{
			rm_char(argv, i);
			rm_backslash(argv, &i);
			rm_char(argv, i);
		}
		else if (((*argv)[i] == '\\'))
			rm_char(argv, i++);
		else
			i++;
	}
}
