/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:17:23 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/13 12:47:50 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



int         ft_cd(t_list **env,  char **argv)
{
	int i;
	char *tmp;
	
	tmp = NULL;

	if (argv[1] != NULL)
	{
		ft_export(env, ft_strjoin("OLDPWD=",getcwd(tmp,256)));
		printf("%s\n", getcwd(tmp,256));
		chdir(argv[1]);
		printf("%s\n", getcwd(tmp,256));
		ft_export(env, ft_strjoin("PWD=",(const char *)getcwd(tmp,256)));
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
