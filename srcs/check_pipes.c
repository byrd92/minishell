/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:05:51 by jalcayne          #+#    #+#             */
/*   Updated: 2021/03/16 11:52:25 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_check_pipes(t_list *mini)
{
	t_token		*content;
	int			pipe;

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
