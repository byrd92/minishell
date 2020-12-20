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

void		ft_kill_mini(void *content)
{
	t_mini *mini;

	mini = (t_mini *)content;
	int i;

	i = 0;
	while (mini->argv[i])
	{
		free(mini->argv[i]);
		i++;
	}
	free(mini->argv);
	free(mini);
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
	t_list	*mini;
	char	**commands;
	int i;
	int pipes;

	int **fd;

	env = NULL;
	mini = NULL;
	ft_environment(&env, envp);
	ft_printf("minivid ");
	while (ft_read_commands(&commands))
	{
		i = 0;

		while (commands[i])
		{
			ft_parse_commands(commands[i], &env, &mini);

			if ((pipes = ft_check_pipes(mini)))
			{
				printf("hay %d pipes\n", pipes);
				//ft_create_pipes(pipes, &fd);
				//ft_forker(&mini, &fd, &env, envp);
			}
			else
			{
				ft_select_build_function(mini, &env, envp);
			}
			i++;
		}
		ft_lstclear(&mini, ft_kill_mini);
		ft_kill_commands(&commands);
		char *hola[] = {"ls", "-l", NULL};
		ft_printf("minivid ");
	}
	//ft_kill_env;
	(void)argc;
	(void)argv;
}
