/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:38:34 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/18 11:53:15 by jalcayne         ###   ########.fr       */
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

static void		ft_environment(t_list **env, char **envp)
{
	t_env	*newenv;

	int i;
	int j;

	i = -1;
	j = 0;

	while(envp[++i])
	{
		j = 0;
		newenv = (t_env *)malloc(sizeof(t_env) * 1);
		newenv->name = ft_search_word(envp[i]);
		while(envp[i][j] != '=')
			j++;
		j++;
		newenv->value = ft_strdup(&envp[i][j]);
		t_list *new = ft_lstnew((const void *)newenv);
			write(1,"N", 1);
		ft_lstadd_back(env, new);
	}
}

/*
** Funcion inicial del programa
** Se guardan las variables de entorno
** Funcion donde se guardan los comandos de cada linea escrita en la terminal
**		Es donde sigue el programa
*/

/*static void		ft_environment(char ***env, char **envp)
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
}*/

int			main(int argc, char **argv, char **envp)
{
	t_list	*env;
	char	**commands;
	int i;
	
	env = NULL;
	ft_environment(&env, envp);
	ft_export(&env, "hola=adios");
	ft_env(env);
	ft_printf("minivid ");
	while (ft_read_commands(&commands))
	{
		ft_printf("minivid > ");
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
	(void)argc;
	(void)argv;
}
