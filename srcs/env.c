/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:06:52 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/27 20:08:03 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_printenv(void *content)
{
	t_env *env;

	env = (t_env *)content;
	ft_printf("%s=%s\n", env->name, env->value);
}

int			ft_env(t_list **env)
{
	ft_lstiter(*env, ft_printenv);
	return (0);
}

int			ft_search_env(void	*content, void *to_search)
{ 
	t_env	*env;
	char	*name_to_search;

	name_to_search = (char *)to_search;
	env = (t_env *)content;
	if (ft_strncmp(env->name, name_to_search,
		ft_strlen(name_to_search) + 1) == 0)
		return (1);
	return (0);
}

char	*ft_find_env(char *str, t_list **env)
{
	int		i;
	t_env	*tmp;
	char	*token;

	i = 0;
	tmp = NULL;
	while (str[i] != ' ' && str[i])
		i++;
	token = malloc(sizeof(char *) * i + 1);
	ft_strncpy(token, str + 1, i - 1);
	if ((tmp = (t_env *)ft_lstsearch_content((*env), 
		ft_search_env, token)) != NULL)
		return (tmp->value);
	return (NULL);
}
