/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:40:55 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/17 12:29:04 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			ft_search_env(void	*content, void *to_search)
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

int			ft_lstsearch(t_list *lst, int (*f)(void *, void *), void *to_search)
{
	t_list	*ptr;

	ptr = lst;
	if (lst == NULL)
	{
	}
	else
	{
		while (ptr->next)
		{
			if (f(ptr->content, to_search) > 0)
				return(1);
			ptr = ptr->next;
		}
		if (f(ptr->content, to_search) > 0)
			return(1);
	}
	return (0);
}

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
		printf("bash: %s\n", ft_strdup(&str[i]));
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

int			ft_env(t_list *env)
{
	ft_lstiter(env, ft_printenv);
	return (0);
}