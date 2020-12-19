/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:07:48 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/19 18:25:50 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_iscomma(char *str, int *comma)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == 39 && *comma == 0)
			*comma = 1;
		else if (str[i] == 34 && *comma == 0)
			*comma = 2;
		else if((str[i] == 34 || str[i] == 39) && *comma > 0)
			*comma = 0;
		i++;
	}
	return (*comma);
}

/*
**	Funcion que separa los comandos, separados por <;>, de la frase escrita en la terminal
*/

/*
**	Funcion para leer los valores que se encirben en la terminal
**	y separar los comandos 
*/


int			ft_read_commands(char ***commands)
{
	int		ret;
	char	*line;
	char	*str;
	char	*aux;
	int		comma;

	ret = 1;
	str = NULL;
	comma = 0;
	while (ret > 0)
	{
		if (str == NULL)
			str = ft_strdup("");
		ft_printf("> ");
		ret = get_next_line(0, &line);
		if (ret < 0)
			return(-1);
		aux = ft_strjoin(str, line);
		free(str);
		str = aux;
		if (ft_iscomma(line, &comma))
		{
			aux = ft_strjoin(str, "\n");
			free(str);
			str = aux;
			continue;
		}
		*commands = ft_split(str, ';');
		free(line);
		return (ret);
	}
	return (0);
}
