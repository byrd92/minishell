/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:00:15 by jalcayne          #+#    #+#             */
/*   Updated: 2021/01/19 12:09:16 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_destroy_mini(t_mini *mini)
{
    ft_reset_io(mini);
    ft_lstclear(&mini->tokens, ft_kill_mini);
    ft_kill_commands(mini);
    free((*mini).commands);
}
int     ft_exit(t_mini *mini, t_list **env)
{
    ft_destroy_mini(mini);
    ft_lstclear(env, ft_kill_env);
    exit(0);
}
