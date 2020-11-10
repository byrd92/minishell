/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:17:59 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/10 18:37:54 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_environment(char ***env, char **envp)
{
	int i;

	i = -1;
	while(envp[++i])
		NULL;
	(*env) = (char **)malloc(sizeof(char*) * i);
	i = -1;
	while (envp[++i])
	{
		(*env)[i] = (char *)ft_memalloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*env)[i][j] = envp[i][j];
		(*env)[i][j] = 0;
	}
	(*env)[i] = NULL;
	
}
int			main(int argc, char **argv, char **envp)
{
	char	*str;
	int		ret;
	char	**env;
	int i;

	i = 0;
	ft_environment(&env, envp);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	ret = 1;
	while (ret > 0)
	{
		ft_printf("> ");
		ret = get_next_line(0, &str);
		free(str);
	}
	(void)argc;
	(void)argv;
}
