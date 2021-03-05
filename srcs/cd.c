/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:17:23 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/31 10:38:11 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			ft_export_cd(t_list **env, char *argv)
{
	int		i;
	t_env	*newenv;
	char *str;

		str = ft_strdup(argv);

		i = 0;
		if (str == NULL)
			return(0);
		newenv = (t_env *)malloc(sizeof(t_env) * 1);
		newenv->name = ft_search_word(str);
		while(str[i] != '=' && str[i])
			i++;
		if (str[i] != '=')
		{
			return (0);
		}
		i++;
		newenv->value = ft_strdup(&str[i]);
		if (ft_lstsearch((*env),ft_search_export,newenv) == 0)
		{
			ft_lstadd_back(env, ft_lstnew(newenv));
		}
		free(str);
	return (0);
}


int         ft_cd(t_list **env,  char **argv)
{
	char cwd[4096];
	char oldpwd[4096];
	int i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	if (i > 2)
	{
		ft_printf("bash: cd: too many arguments\n");
		return (1);
	}
	getcwd(oldpwd, 4096);
	if (chdir(argv[1]) == 0)
	{
		ft_export_cd(env, ft_strjoin("OLDPWD=",oldpwd));
		ft_export_cd(env, ft_strjoin("PWD=",(const char *)getcwd(cwd,256)));
	}
	else
	{
		ft_printf("bash: cd: %s: No such file or directory\n", argv[1]);
		return(1);
	}
	
	return (0);
}

/*#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
 
int main (int argc, char *argv[]){
 
 // Variables 
 DIR *dirp;
 struct dirent *direntp;
 
 // Comprobamos los argumentos 
 if (argc != 2){
 printf("Uso: %s directorio\n", argv[0]);
 exit(1);
 }
 
 // Abrimos el directorio 
 dirp = opendir(argv[1]);
 if (dirp == NULL){
 printf("Error: No se puede abrir el directorio\n");
 exit(2);
 }
 
 // Leemos las entradas del directorio 
 printf("i-nodo\toffset\t\tlong\tnombre\n");
 while ((direntp = readdir(dirp)) != NULL) {
 printf("%d\t%d\t%d\t%s\n", direntp->d_ino, direntp->d_off, direntp->d_reclen, direntp->d_name);
 }
 
 // Cerramos el directorio 
 closedir(dirp);
}*/
