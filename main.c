/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:17:59 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/11 14:57:11 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_environment(char ***env, char **envp)
{
	int i;
	int j;
	i = -1;
	while(envp[++i])
		NULL;
	(*env) = (char **)malloc(sizeof(char*) * i);
	i = -1;
	while (envp[++i])
	{
		(*env)[i] = (char *)malloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*env)[i][j] = envp[i][j];
		(*env)[i][j] = 0;
	}
	(*env)[i] = NULL;
}

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

void		ft_separate_commands(char ***commands, char *str)
{
	int i;
	int num_commands;
	char *aux;
	int j;

	
	num_commands = 1;
	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] == ';')
			num_commands++;
	}
	(*commands) = (char **)malloc(sizeof(char *) * num_commands + 1);
	num_commands--;
	i = 0;
	while (num_commands >= 0)
	{
		j = -1;
		if ((aux = ft_strchr(str, ';')))
		{
			aux = 0;
			(*commands)[j] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
			printf("%s\n", str);
			while (str[++j])
				(*commands)[i][j] = str[j];
			(*commands)[i][j] = 0;
			aux = ft_strdup(++aux);
			free(str);
			str = aux;
		}
		else
		{
			(*commands)[j] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
			while (str[++j])
				(*commands)[i][j] = str[j];
			(*commands)[i][j] = 0;
			free(str);
			str = NULL;
		}
		i++;
	}
	(*commands)[j] = NULL;	
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
		//ft_printf("linea: %s\n", str);
		if (ft_iscomma(line, &comma))
		{
			aux = ft_strjoin(str, "\n");
			free(str);
			str = aux;
			continue;
		}
		//ft_printf("frase: %s\n", str);
		ft_separate_commands(commands, str);
		int y;
		y = 0;
		while ((*commands)[y])
		{
			printf("commando: %s\n", (*commands)[y]);
			y++;
			write(1, "y", 1);

		}
		write(1, "x", 1);
		free(line);
	}
	return (0);
}
int			main(int argc, char **argv, char **envp)
{
	char	**env;
	char	**commands;

	ft_environment(&env, envp);
	ft_read_commands(&commands);
	(void)argc;
	(void)argv;
}
