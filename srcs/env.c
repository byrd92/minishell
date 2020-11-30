/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:06:52 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/27 20:08:03 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_printenv(void *content)
{
	t_env *env;

	env = (t_env *)content;
	ft_printf("%s=%s\n",env->name,env->value);
}

int			ft_env(t_list **env)
{
	ft_lstiter(*env, ft_printenv);
	return (0);
}