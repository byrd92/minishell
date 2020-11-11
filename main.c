/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:17:59 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/11 13:02:47 by jalcayne         ###   ########.fr       */
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

int			ft_read_commands(char ***commands)
{
	int		ret;
	char	*line;
	char	*str;
	char	*aux;
	int		comma;

	(*commands) = (char **)malloc(sizeof(char*) * PATH_MAX);

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
					ft_printf("\n%d", comma);

		if (ft_iscomma(line, &comma))
		{
			aux = ft_strjoin(str, "\n");
			free(str);
			str = aux;

			continue;
		}
		ft_printf("frase: %s\n", str);

		free(str);
		str = NULL;
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
