/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:05:51 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/28 11:41:14 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_check_pipes(t_list *mini)
{
   	t_token *content;
	int pipe;

	pipe = 0;
	while (mini)
	{
		content = (t_token *)mini->content;
		if (content->type == 1)
			pipe++;
		mini = mini->next;
	}
	if (pipe >= 1)
		return (pipe);
	return (0);
}