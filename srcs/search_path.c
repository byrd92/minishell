/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:08:43 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 16:11:56 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			ft_search_env_path(void *content, void *to_search)
{
	t_env	*env;
	char	*name_to_search;

	name_to_search = (char *)to_search;
	env = (t_env *)content;
	if (ft_strncmp(env->name, name_to_search, ft_strlen(name_to_search)) == 0)
		return (1);
	return (0);
}

static int			search_in_dir(char *path, char *program)
{
	DIR				*dirp;
	struct dirent	*direntp;

	dirp = opendir(path);
	if (dirp == NULL)
		return (0);
	while ((direntp = readdir(dirp)) != NULL)
	{
		if (direntp->d_type == 8 &&
		!ft_strncmp(direntp->d_name, program, ft_strlen(program) + 1))
			return (1);
	}
	return (0);
	closedir(dirp);
}

char				*search_path(t_list **env, char *program)
{
	t_env	*path;
	char	**path_directs;
	int		i;

	i = 0;
	if ((path = ft_lstsearch_content(*env, ft_search_env_path,
		(void *)"PATH")) != NULL)
	{
		path_directs = ft_split(path->value, ':');
		while (path_directs[i])
		{
			if (search_in_dir(path_directs[i], ft_search_word(program)))
				return (path_directs[i]);
			i++;
		}
		return (NULL);
	}
	return ("bash:");
}
