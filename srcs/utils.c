/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:13:09 by egarcia-          #+#    #+#             */
/*   Updated: 2020/12/11 18:57:09 by egarcia-         ###   ########.fr       */
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
		{	
			words++;
			while (str[i] == c && str[i])
				i++;
		}
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
static int		ft_strlen_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int		ft_strlen_tokens(char *str)
{
	int		len;

	len = 0;
	while (*str && *str != ' ' && *str != '>' && *str != ';' && *str != '|'
	&& *str != '"' && *str != '\'' && *str != '$' && *str != '=')
	{
		len++;
		str++;
	}
	if (*str == '=')
		len++;
	return (len);
}

static int	ft_strlen_arg(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '"' || str[i] == '\'')
		i = ft_strlen_char(str + i + 1, str[i]) + 2;
	else if (ft_strlen_char(str, ':') < ft_strlen_tokens(str))
		i = ft_strlen(str);
	else
		i = ft_strlen_tokens(str);
	return (i);
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