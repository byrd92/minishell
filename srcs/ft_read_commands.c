/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:07:48 by jalcayne          #+#    #+#             */
/*   Updated: 2021/03/16 12:38:24 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		sighandler(const int sig)
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
		salir_d = 1;
		i > 0 ? ft_putstr_fd("^C\n", 1) : write(1, "\nminivid > ", 11);
		ft_putstr_fd("\0", 0);
	}
	else if (sig == SIGQUIT)
	{
		while ((child = wait(NULL)) > 0)
			i++;
		i > 0 ? ft_putstr_fd("Quit: 3\n", 1) : ft_putstr_fd("\b\b  \b\b", 2);
	}
}

static char	*ft_copy_words(char *buf, char *str)
{
	char	*aux;

	aux = str;
	str = ft_strjoin(str, buf);
	free(aux);
	return (str);
}

int			ft_read_commands(t_mini *mini)
{
	int		ret;
	char	*str;
	char	buf[2];

	ret = 1;
	ft_bzero(buf, 2);
	str = ft_calloc(1, sizeof(char));
	while (1)
	{
		salir_d = 0;
		if (str == NULL)
			ft_strdup("");
		while (!salir_d && (ret = read(0, buf, 1)))
		{
			if ((*buf == '\n' || *buf == 0x04))
				break ;
			str = ft_copy_words(buf, str);
		}
		if (ret || (!ret && !ft_strlen(str)))
			break ;
	}
	mini->commands = ft_split(str, ';');
	free(str);
	return (ret);
}
