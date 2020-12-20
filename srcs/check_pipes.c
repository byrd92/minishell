/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:05:51 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/20 17:36:19 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_check_pipes(t_list *mini)
{
   	t_mini *content;
	int pipe;

	pipe = 0;
	while (mini)
	{
		content = (t_mini *)mini->content;
		if (content->type == 1)
			pipe++;
		mini = mini->next;
	}
	if (pipe == 1)
		return (pipe);
	return (0);
}