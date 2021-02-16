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

void		ft_kill_commands(t_mini *mini)
{
	int i;

	i = 0;

	while ((mini->commands)[i])
	{
		free((mini->commands)[i]);
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
	t_token *mini;

	mini = (t_token *)content;
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

void		init_mini(t_mini *mini)
{
	mini->commands = 0;
	mini->tokens = NULL;
	mini->in = 0;
	mini->out = 0;
	mini->newin = 0;
	mini->newout = 0;
	mini->strcmd = NULL;
	mini->dolar = 0;
}

int			main(int argc, char **argv, char **envp)
{
	t_list	*env;
	t_mini	mini;
	int i;
	int pipes;

	init_mini(&mini);
	env = NULL;

	ft_environment(&env, envp);
	ft_printf("minivid > ");
	ft_save_stdio(&mini);
	signal(SIGINT, (void (*)(int))sighandler);

	while (ft_read_commands(&mini))
	{
		signal(SIGQUIT, (void (*)(int))sighandler);
		i = 0;
		while (mini.commands[i])
		{	
			ft_parse_commands(&mini, &env, i);
			ft_check_io(&mini);
			//mini.out = ft_output(&mini);
			pipes = ft_check_pipes(mini.tokens);
			if (pipes)
			{
				mini.dolar = ft_forker(&mini, pipes, &env, envp);
			}
			else if (ft_dolar(mini.commands[i], &mini))
				;
			else
			{
				mini.dolar = ft_select_build_function(&mini, &env, envp);
			}
			i++;
			ft_lstclear(&mini.tokens, ft_kill_mini);
		}
		ft_reset_io(&mini);
		ft_lstclear(&mini.tokens, ft_kill_mini);
		ft_kill_commands(&mini);
		init_mini(&mini);
		ft_printf("minivid > ");
	}
	ft_lstclear(&env, ft_kill_env);
	(void)argc;
	(void)argv;
}
