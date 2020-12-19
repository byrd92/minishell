/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_build_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:07:51 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/19 16:43:33 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_select_build_function(t_list *mini,  t_list **env)
{
   	t_mini *content;

	while (mini)
	{
		content = (t_mini *)mini->content;
		ft_printf("->%s\n" , content->argv[0]);
		if(ft_strncmp(content->argv[0], "echo\0", 6) == 0)
			ft_echo(env ,content->argv);
		else if(ft_strncmp(content->argv[0], "export\0", 7) == 0)
			ft_export(env, content->argv);
		else if(ft_strncmp(content->argv[0], "env\0", 4) == 0)
			ft_env(env);
		else if(ft_strncmp(content->argv[0], "unset\0", 6) == 0)
			ft_unset(env, content->argv);
		else if(ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
			ft_pwd(env);
		else if(ft_strncmp(content->argv[0], "cd\0", 3) == 0)
			ft_cd(env, content->argv);
		else
			printf("%s\n",search_path(env, content->argv[0]));
		mini = mini->next;
	}
}