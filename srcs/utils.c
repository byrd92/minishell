/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:13:09 by egarcia-          #+#    #+#             */
/*   Updated: 2020/12/10 17:55:30 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			argv_size(char *str, int c)
{
	int i;
	int quote;
	int words;

	quote = 0;
	/* words es = 1 porque como minimo hay 1 argv) */
	words = 1;
	i = 0;

	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			quote = str[i] == 34 ?  34 : 39;
			i++;
			while (str[i] != quote && str[i])
				i++;
			words++;
		}
		if (str[i] == c)
			words++;
		i++;
	}
	return (words);
}

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

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 34 || str[i] == 39)
		array = ft_split(str, str[i]);
	else
		array = ft_split(str, c);
	return (array);
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