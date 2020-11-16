/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:52:20 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/16 11:20:24 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	Cambiar la funcion ft_environtment la variable env por una lista para usarla aqui toda justa
*/
int     ft_command_export(char **env, t_list **myenv, char *str)
{
	int		i;
	char	*aux;
	t_envar	*var;
	
	i = 0;
	var = (t_envar *)malloc(sizeof(t_envar) * 1);

	while (str[i] && str[i] == ' ')
	{
		i++;
	}
	aux = ft_strchr(&str[i], '=');
	*aux = 0;
	var->name = ft_strdup(&str[i]);
	

	
}