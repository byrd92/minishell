/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:07:48 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/12 12:08:36 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		ft_iscomma(char *str, int *comma)
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

static void		ft_separate_commands(char ***commands, char **str)
{
	int i;
	int num_commands;
	char *aux;

	num_commands = 1;
	i = 0;
	while ((*str)[i])
	{
		i++;
		if ((*str)[i] == ';')
			num_commands++;
	}
	i = 0;
	(*commands) = (char **)malloc(sizeof(char *) * num_commands + 1);
	while((aux = ft_strchr((*str), ';')))
	{
		*aux = 0;
		(*commands)[i++] = ft_strdup((*str));
		aux = ft_strdup(++aux);
		free((*str));
		(*str) = aux;
		aux = NULL;
	}
	(*commands)[i++] = ft_strdup((*str));
	(*commands)[i] = NULL;
	free((*str));
	(*str) = NULL;
}

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
		ft_printf("minivid > ");
		ret = get_next_line(0, &line);
		if (ret < 0)
			return(1);
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
		ft_separate_commands(commands, &str);
		ft_kill_commands(commands);
		free(line);
	}
	return (0);
}
