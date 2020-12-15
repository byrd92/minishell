/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:58:44 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/19 20:02:06 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void        ft_echo2(char **argv ,int flag)
{
	int i;

	i = flag == 1 ? 2 : 1;
	while (argv[i])
	{
		ft_printf("%s ", argv[i]);
		i++;
	}
	flag == 1 ? write(1, "", 1) : write(1, "\n", 1) ;
}

void        ft_echo(t_list **env, char **argv)
{

	if (ft_strncmp(argv[1], "-n", 2) == 0)	
		ft_echo2(argv, 1);
	else
		ft_echo2(argv, 0);
}