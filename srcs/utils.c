/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:13:09 by egarcia-          #+#    #+#             */
/*   Updated: 2020/12/15 20:18:16 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char		*ft_strdup_sep(char *str, int c)
{
	char *ret;
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	ret = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (str[i] != c && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		*ft_strldup(char *str, int i)
{
	char *ret;
	int j;

	j = 0;
	ret = malloc(sizeof(char *) * i + 1);

	while (j < i)
	{
		ret[j] = str[j];
		j++;
	}
	ret[j] = 0;
	return (ret);
}

char		**ft_split_mini(char *str, int c)
{
	char **array;
	int i;
	int size;
	int quote;
	int len;
	
	i = 0;
	len = 0;
	quote = 0;
	size = argv_size(str , ' ');
	array = malloc(sizeof(char *) * size + 1);
	while ( i < size)
	{
		while (*str == ' ')
			str++;
		len = ft_strlen_arg(str);
		quote = (*str == '"' || *str == '\'') ? 1 : 0;
		array[i] = ft_strldup(str + quote, len - quote * 2);
		str += len;
		i++;
	}
	array[i] = 0;
	return (array);
}



int			ft_search_env(void	*content, void *to_search)
{ 
	t_env	*env;
	char	*name_to_search;

	name_to_search = (char *)to_search;
	env = (t_env *)content;

	if (ft_strncmp(env->name,name_to_search, ft_strlen(name_to_search)) == 0)
		return (1);
	return (0);
}

char	*ft_find_env(char *str, t_list **env)
{
	int i;
	t_env *tmp;
	char *token;

	i = 0;
	tmp = NULL;
	while (str[i] != ' ' && str[i])
		i++;
	token = malloc(sizeof(char *) * i + 1);
	ft_strncpy(token, str + 1, i - 1);
	if ((tmp = (t_env *)ft_lstsearch_content((*env), ft_search_env, token)) != NULL)
		return (tmp->value);
	return (NULL);
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
