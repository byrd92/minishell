/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:07:46 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/05 11:13:53 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Funcion par buscar la primera palabra dentro de una string
** Quita los espacion que hay antes de la palabra
**	Devuelve ua string con la palabra
*/

char	*ft_search_word(char *str)
{
	int i;
	char *aux;
	char *word;
	i = 0;
	while(ft_isspace(str[i]))
		i++;
	aux = ft_strdup(str);
	while ((ft_isspace(aux[i]) == 0) && aux[i])
		{
			i++;
		}
	aux[i] = 0;
	word = ft_strdup(aux);
	free(aux);
	return (word);
}

/*
** Funcion para buscar e imprimir una palabra directamente
** Devuelve el tamaño de la palabra imprimida
*/

int		ft_print_word(char *str)
{
	char *word;
	int i;

	word = ft_search_word(str);
	ft_printf("%s", word);
	i = ft_strlen(word);
	free(word);
	return (i);
}
/*
** Funcion para comparar dos string, si son identicas en cuanto a valores y a tamaño
**	Devuelve un 0 si no es igual
**	devuelve el tamaño de las palabras
*/

int			ft_strcmp(char *s1, char *s2)
{
	int i;
	
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return(0);
		i++;
	}
	if (s1[i] != s2[i])
		return(0);
	return(i);
	
}

/*
** Funcion para buscar si hay un comando en la terminal y ejecutar la funcion correspondiente
*/

static void	ft_search_command(char *str)
{
	int i;
	
	i = 0;
	while (str[i] == ' ')
		i++;
	if (( i = i + ft_strcmp(ft_search_word(&str[i]), "echo")) > 0)
	{
		//ft_command_echo(&str[i]);
	}
	else
	{
		ft_print_word(&str[i]);
		ft_printf("%s: command not found\n",ft_search_word(&str[i]));
	}
}

int		main(void)
{
	char	*str;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ft_printf("> ");
		ret = get_next_line(0, &str);
		ft_search_command(str);
		free(str);
	}
}