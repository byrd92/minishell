/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:40:55 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/18 18:29:06 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_search_export(void	*content, void *to_search)
{
	t_env	*env;
	t_env	*env_to_search;

	env_to_search = (t_env *)to_search;
	env = (t_env *)content;

	if (ft_strncmp(env->name,env_to_search->name, ft_strlen(env_to_search->name)) == 0)
	{
		env->value = env_to_search->value;
		return (1);
	}
	return (0);
}

int			ft_export(t_list **env, char **argv)
{
	int		i;
	t_env	*newenv;
	char *str;
	int j;

	j = 1;
	while (argv[j])
	{
		str = ft_strdup(argv[j]);

		i = 0;
		if (str == NULL)
			return(0);
		if ((argv[j + 1] != NULL && argv[j + 1][0] == '=') || (str != NULL && str[0] == '='))
		{
			ft_printf("bash: export: `=': not a valid identifier\n");
			return(1);
		}
		newenv = (t_env *)malloc(sizeof(t_env) * 1);
		newenv->name = ft_search_word(str);
		while(str[i] != '=' && str[i])
			i++;
		if (str[i] != '=')
		{
			return (0);
		}
		i++;
		newenv->value = ft_strdup(&str[i]);
		if (ft_lstsearch((*env),ft_search_export,newenv) == 0)
		{
			ft_lstadd_back(env, ft_lstnew(newenv));
		}
		j++;
		free(str);
	}
	return (0);
}