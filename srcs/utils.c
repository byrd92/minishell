/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:13:09 by egarcia-          #+#    #+#             */
/*   Updated: 2020/12/22 15:06:14 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_strldup(char *str, int i)
{
	char *ret;
	int k;
	int j;

	
	j = 0;
	k = 0;
	ret = malloc(sizeof(char *) * i + 1);
	while (j < i)
	{
		ret[j] = str[k];
		j++;
		k++;
	}
	ret[j] = 0;
	return (ret);
}

static int	ft_strlen_arg(char *str)
{
	int i;

	i = 0;
	if (str[i] == '<' || str[i] == '>' || str[i] == '=' || str[i] == '|')
		i = (str[i] == '>' && str[i + 1] == '>') ? 2 : 1;
	else
	{
		while (str[i] && !ft_isspace(str[i]) && str[i] != '<' &&
		str[i] != '>' && str[i] != '=' && str[i] != '|')
		{
			if (str[i] == '\'' || str[i] == '"')
			{
				i++;
				i += ft_strlen_char(str + i, str[i - 1]);
				if (!(str[i]))
					return (i);
			}
			i++;
		}
		if (str[i] == '=')
			i++;
	}
	return (i);
}
char		**ft_split_mini(char *str)
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
		array[i] = ft_strldup(str, len);
		rm_token(&(array[i]));
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
	if (ft_strncmp(env->name,name_to_search, ft_strlen(name_to_search) + 1) == 0)
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
