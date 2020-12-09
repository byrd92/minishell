/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:58:44 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/19 20:02:06 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			ft_search_env2(void	*content, void *to_search)
{
	t_env	*env;
	char	*name_to_search;

	name_to_search = (char *)to_search;
	env = (t_env *)content;

	if (ft_strncmp(env->name,name_to_search, ft_strlen(name_to_search)) == 0)
		return (1);
	return (0);
}
void			*ft_lstsearch_content(t_list *lst, int (*f)(void *, void *), void *to_search)
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
				return(ptr->content);
			ptr = ptr->next;
		}
		if (f(ptr->content, to_search) > 0)
			return(ptr->content);
	}
	return (NULL);
}


int        ft_echo_env(char *str, t_list **env)
{
    int i;
    int size;
    char *variable;
	t_env *tmp;

    size = 0;
    i = 0;
    while (!(ft_isspace(str[size])) && str[size] != 0)
        size++;
    variable = malloc(sizeof(char *) * size);
	str++;
    while (!(ft_isspace(*str)) && *str != 34 && *str != 39 && *str != 0)
    {
        variable[i] = *str;
        str++;
        i++;
    }
	variable[i] = 0;
	tmp = (t_env*)ft_lstsearch_content((*env), ft_search_env2, variable);
    if (tmp)
		ft_printf("%s", tmp->value);
    return (size);
}

void        ft_echo2(char **argv ,int flag, t_list **env)
{
	int i;

	i = flag == 1 ? 2 : 1;
	while (argv[i])
	{
		ft_printf("%s ", argv[i]);
		i++;
	}
	(void)env;
	flag == 1 ? write(1, "", 1) : write(1, "\n", 1) ;
}

void        ft_echo(t_list **env, char **argv)
{

	if (ft_strncmp(argv[1], "-n", 2) == 0)	
		ft_echo2(argv, 1, env);
	else
		ft_echo2(argv, 0, env);
	
	//ft_echo2(str,flag,env);
}