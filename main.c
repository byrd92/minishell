/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:18:46 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/16 19:19:27 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

/*
** Funcion barra borrar la variable que guarda los comandos
*/

void		ft_kill_commands(char ***commands)
{
	int i;

	i = 0;

	while ((*commands)[i])
	{
		free((*commands)[i]);
		i++;
	}	
}
/*
** Funcion para guardar las variables de entorno en una variable
*/

static void		ft_environment(char ***env, char **envp)
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


/*
** Funcion inicial del programa
** Se guardan las variables de entorno
** Funcion donde se guardan los comandos de cada linea escrita en la terminal
**		Es donde sigue el programa
*/

int			main(int argc, char **argv, char **envp)
{
	char	**env;
	char	**commands;
	int i = 0;
	ft_environment(&env, envp);
	ft_printf("minivid ");

	while (ft_read_commands(&commands))
	{
		i = 0;
		while (commands[i])
		{
			ft_parse_commands(commands[i]);
			//ft_printf("%s\n", commands[i]);
			i++;
		}
		
		
		//continuar programa
		//siguente funcion()
		ft_kill_commands(&commands);
		ft_printf("minivid ");
	}
	ft_kill_commands(&commands);

	(void)argc;
	(void)argv;
}
