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

void        ft_parse_commands(char *command, t_list **env)
{
	char *alter;

	alter = command;
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