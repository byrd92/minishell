/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:58:44 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 11:56:32 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_echo(t_list **env, char **argv)
{
	int i;
	int flag;

	if (argv[1])
	{
		flag = ft_strncmp(argv[1], "-n", 2) == 0 ? 1 : 0;
		i = flag == 1 ? 2 : 1;
		while (argv[i + 1] != 0)
		{
			ft_printf("%s ", argv[i]);
			i++;
		}
		ft_printf("%s", argv[i]);
		flag == 1 ? write(1, "", 1) : write(1, "\n", 1);
	}
	(void)env;
	return (0);
}
