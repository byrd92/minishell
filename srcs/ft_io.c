/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:57:51 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 12:03:32 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_save_stdio(t_mini *mini)
{
	mini->mainout = dup(1);
	mini->mainin = dup(0);
}

void		ft_reset_io(t_mini *mini)
{
	if (mini->out == 1)
		dup2(mini->mainout, 1);
	if (mini->in == 1)
		dup2(mini->mainin, 0);
	mini->out = 0;
	mini->in = 0;
}

void		define_out(t_mini *mini, t_token *content)
{
	if (content->type == 3)
	{
		mini->newout = open(content->argv[0], O_CREAT | O_TRUNC |
							O_WRONLY, 0644);
		dup2(mini->newout, 1);
	}
	else if (content->type == 4)
	{
		mini->newout = open(content->argv[0], O_CREAT | O_WRONLY |
							O_APPEND, 0644);
		dup2(mini->newout, 1);
	}
	mini->out = 1;
}

void		ft_check_io(t_mini *mini)
{
	t_token	*content;
	t_list	*token;

	token = mini->tokens;
	while (token)
	{
		content = (t_token *)token->content;
		if (content->type == 3 || content->type == 4)
			define_out(mini, content);
		else if (content->type == 2)
		{
			mini->newin = open(content->argv[0], O_RDONLY, 0644);
			dup2(mini->newin, 0);
			mini->in = 1;
		}
		token = token->next;
	}
}
