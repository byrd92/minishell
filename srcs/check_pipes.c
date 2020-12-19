/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:05:51 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/19 16:39:07 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_check_pipes(t_list *mini)
{
   	t_mini *content;
	int cnt;
	int pipe;

	pipe = 0;
	cnt = 0;
	while (mini)
	{
		content = (t_mini *)mini->content;
		if (content->type == 1)
			pipe = 1;
		cnt++;
		mini = mini->next;
	}
	if (pipe == 1)
		return (cnt);
	return (0);
}