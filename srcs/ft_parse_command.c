/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:00:50 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/19 20:01:56 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../minishell.h"
/*
 static void		ft_printlist(void *content)
{
	char *env;

	env = (char *)content;
	ft_printf("%s\n",env);
}

static int			ft_printlista(t_list **lista)
{
	ft_lstiter(*lista, ft_printlist);
	return (0);
}*/

void	list_commands(t_list **alter, char *command)
{
	char *tmp;
	int i;
	char *value;

	tmp = command;
	i = 0;
	while (*command)
	{
		if (*command == '|')
		{
			*command = 0;
			value = ft_strdup(tmp);
			t_list *new = ft_lstnew((const void *)value);
			ft_lstadd_back(alter, new);
			tmp = command + 1;
		}
		command++;
	}
	value = ft_strdup(tmp);
	t_list *new = ft_lstnew((const void *)value);
	ft_lstadd_back(alter, new);
}

void        ft_parse_commands(char *command, t_list **env)
{
	char *alter;
	t_list *alterlist;

	alter = NULL;
	alterlist = NULL;
	list_commands(&alterlist, command);
	alter = command;
	//ft_printlista(&alterlist);
	if(ft_strncmp(alter, "echo ", 5) == 0)
		ft_echo(env ,&alter[5]);
    else if(ft_strncmp(alter, "export ", 7) == 0)
		ft_export(env, &alter[6]);
	else if(ft_strncmp(alter, "env", 3) == 0)
		ft_env(env);
	else if(ft_strncmp(alter, "unset ", 6) == 0)
	{
		ft_unset(env, &alter[5]);
	}
	else if(ft_strncmp(alter, "pwd", 3) == 0)
	{
		ft_pwd(env);
	}
	else if(ft_strncmp(alter, "cd ", 3) == 0)
	{
		ft_cd(&alter[2]);
	}
	
}