/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:40:55 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/18 17:24:37 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



int			ft_export(t_list **env, char *str)
{
	int		i;
	t_env	*newenv;

	i = 0;
	newenv = (t_env *)malloc(sizeof(t_env) * 1);
	newenv->name = ft_search_word(str);
	while(str[i] != '=')
		i++;
	if (!ft_isalnum(str[i - 1]))
	{
		printf("bash: %s error en el comando\n", ft_strdup(&str[i]));
		return(1);//error

	}
	i++;
	newenv->value = ft_strdup(&str[i]);
	if (ft_lstsearch((*env),ft_search_env,newenv) == 0)
	{
		ft_lstadd_back(env, ft_lstnew(newenv));
	}
	return (0);
}

static void		ft_printenv(void *content)
{
	t_env *env;

	env = (t_env *)content;
	ft_printf("%s=%s\n",env->name,env->value);
}

int			ft_env(t_list **env)
{
	ft_lstiter(*env, ft_printenv);
	return (0);
}