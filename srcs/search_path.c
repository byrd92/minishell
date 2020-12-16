/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:56:22 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/16 09:42:52 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


static int			ft_search_env_path(void	*content, void *to_search)
{
	t_env	*env;
	char	*name_to_search;

	name_to_search = (char *)to_search;
	env = (t_env *)content;

	if (ft_strncmp(env->name,name_to_search, ft_strlen(name_to_search)) == 0)
		return (1);
	return (0);
}

static int search_in_dir(char *path, char *program)
{
	DIR *dirp;
	struct dirent *direntp;
	
	dirp = opendir(path);
	if (dirp == NULL)
	{
		printf("Error: No se puede abrir el directorio\n");
		return (0);
	}
	//printf("i-nodo\toffset\t\tlong\ttype\tnombre\n");
	while ((direntp = readdir(dirp)) != NULL)
	{
	//	printf("%ld\t%ld\t%d\t%u\t%s\n", direntp->d_ino, direntp->d_off, direntp->d_reclen, direntp->d_type, direntp->d_name);
		if (direntp->d_type == 8 && !ft_strncmp(direntp->d_name, program, ft_strlen(program) + 1))
			return (1);
	}
	return (0);
	closedir(dirp);
}

char     *search_path(t_list **env, char *program)
{
	t_env *path;
	char **path_directs;
	int i;

	i = 0;	
	path = ft_lstsearch_content(*env, ft_search_env_path, (void *)"PATH");
	path_directs = ft_split(path->value, ':');
	while (path_directs[i])
	{
		//printf("path = %s, program %s\n", path_directs[i], program);
		if (search_in_dir(path_directs[i], ft_search_word(program)))
			return(path_directs[i]);
		i++;
	}
	return (NULL);
	
}