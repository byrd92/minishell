/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:28:14 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/06 15:30:57 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_pipe(int pipes, int ***fd)
{
	int i;

	i = 0;
	(*fd) = (int **)malloc(sizeof(int *) * pipes);
	while (i < pipes)
	{
		(*fd)[i] = (int *)malloc(sizeof(int) * 2);
		pipe((*fd)[i++]);
	}
}
