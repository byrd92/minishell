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
crl + c = sigint, borra lo que tiene y lanza  nueva linea.
ctrl + d = sigexit, si no hay nada escrito sale, si hay algo escrito no permite
*/
void	sighandler(const int sig)
{
	int		child;
	int		i;

	i = 0;
	child = 0;

	if (sig == SIGINT)
	{
		ft_putstr_fd("\0", 0);
		ft_putstr_fd("\b\b  \b\b", 0);
		while ((child = wait(NULL)) > 0)
			i++;
		if (i)
			ft_putstr_fd("^C\n", 1);
		else
			write(1,"\nminivid > ", 11);
	}
	else if (sig == SIGQUIT)
	{
		while ((child = wait(NULL)) > 0)
			i++;
		if (i)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			return ;
		}
		ft_putstr_fd("\b\b  \b\b", 2);
	}
	
}

int			ft_read_commands(t_mini *mini)
{
	int		ret;
	char	*line;
	char	*str;
	char	*aux;
	int		comma;

	ret = 1;
	str = NULL;
	comma = 0;

	while (1)
	{
		if (str == NULL)
			str = ft_strdup("");
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
		mini->commands = ft_split(str, ';');
		free(line);
		return (ret);
	}
	return (0);
}
