/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:17:59 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/16 20:32:27 by jalcayne         ###   ########.fr       */
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

char			*ft_search_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (!ft_isalnum(*str))
		str++;
	while (ft_isalnum(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (ft_isalnum(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
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
		ft_lstadd_back(env, ft_lstnew(newenv));
	}
}

/*void		ft_printlst(void *content)
{
	t_env *env;

	env = (t_env *)content;
	ft_printf("%s=%s\n",env->name,env->value);
}*/


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
	int i = 0;
	ft_environment(&env, envp);
	ft_printf("minivid ");
	while (ft_read_commands(&commands))
	{

		i = 0;
		while (commands[i])
		{
			printf("%s\n", commands[i++]);
		}
		//continuar programa
		//siguente funcion()
		ft_kill_commands(&commands);
		ft_printf("minivid ");

	}
	(void)argc;
	(void)argv;
}
