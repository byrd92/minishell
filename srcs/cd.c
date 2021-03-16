/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:53:38 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 11:52:10 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int			ft_export_cd(t_list **env, char *argv)
{
	int		i;
	t_env	*newenv;
	char	*str;

	str = ft_strdup(argv);
	i = 0;
	if (str == NULL)
		return (0);
	newenv = (t_env *)malloc(sizeof(t_env) * 1);
	newenv->name = ft_search_word(str);
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] != '=')
		return (0);
	i++;
	newenv->value = ft_strdup(&str[i]);
	if (ft_lstsearch((*env), ft_search_export, newenv) == 0)
		ft_lstadd_back(env, ft_lstnew(newenv));
	free(str);
	return (0);
}

static	void		ft_switch_pwd(t_list **env,
					char *oldpwd, char *cwd, char **argv)
{
	if (argv[1] == NULL)
		chdir(ft_find_env("$HOME", env));
	ft_export_cd(env, ft_strjoin("OLDPWD=", oldpwd));
	ft_export_cd(env, ft_strjoin("PWD=", (const char *)getcwd(cwd, 4096)));
}

int					ft_cd(t_list **env, char **argv)
{
	char	cwd[4096];
	char	oldpwd[4096];
	int		i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	if (i > 2)
	{
		ft_printf("bash: cd: too many arguments\n");
		return (1);
	}
	getcwd(oldpwd, 4096);
	if (argv[1] == NULL)
		ft_switch_pwd(env, oldpwd, cwd, argv);
	else if (chdir(argv[1]) == 0)
		ft_switch_pwd(env, oldpwd, cwd, argv);
	else
	{
		ft_printf("bash: cd: %s: No such file or directory\n", argv[1]);
		return (1);
	}
	return (0);
}
