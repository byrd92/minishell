/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:04:19 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/23 18:33:03 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			ft_search_pwd(void	*content, void *to_search)
{
	t_env	*env;
	char	*name_to_search;

	name_to_search = (char *)to_search;
	env = (t_env *)content;

	if (ft_strncmp(env->name,name_to_search, ft_strlen(name_to_search)) == 0)
		return (1);
	return (0);
}

int			ft_pwd(t_list **env)
{
	t_env	*pwd;
	
	pwd = (t_env*)ft_lstsearch_content((*env), ft_search_pwd, "PWD");
	if (pwd)
		ft_printf("%s\n", pwd->value);
	return (0);
}