/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:38:34 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/19 18:26:21 by egarcia-         ###   ########.fr       */
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

void		ft_kill_env(void *content)
{
	t_env *env;
	
	env = (t_env *)content;
	free(env->name);
	free(env->value);
	free(env);
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
		ft_lstadd_back(env, new);
	}
}

/*
** Funcion inicial del programa
** Se guardan las variables de entorno
** Funcion donde se guardan los comandos de cada linea escrita en la terminal
**		Es donde sigue el programa
*/

int			main(int argc, char **argv, char **envp)
{
	t_list	*env;
	char	**commands;
	int i;
	
	env = NULL;
	ft_environment(&env, envp);
	ft_printf("minivid ");
	while (ft_read_commands(&commands))
	{
		//ft_printf("> ");
		i = 0;
		while (commands[i])
		{
			ft_parse_commands(commands[i], &env);
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
