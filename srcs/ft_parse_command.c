/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:00:50 by egarcia-          #+#    #+#             */
/*   Updated: 2021/03/16 17:11:30 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_new_token(t_mini *mini, char *command)
{
	t_token		*token;
	int			i;
	char		*tmp;
	t_list		*new;

	i = 0;
	tmp = ft_strdup(command);
	token = (t_token *)malloc(sizeof(t_token) * 1);
	tmp += ft_datatype(tmp, token);
	while (!(ft_strchr("<|>", tmp[i]) && tmp[i - 1] != '\\') && tmp[i])
		i++;
	tmp[i] = 0;
	token->argv = ft_split_mini(tmp);
	new = ft_lstnew((const void *)token);
	ft_lstadd_back(&mini->tokens, new);
}

void		ft_create_token(t_mini *mini, int i)
{
	int j;

	j = 0;
	ft_new_token(mini, &mini->commands[i][j]);
	while (mini->commands[i][j])
	{
		if (ft_strchr("<|>", mini->commands[i][j]) &&
						mini->commands[i][j - 1] != '\\')
		{
			ft_new_token(mini, &mini->commands[i][j]);
			if (mini->commands[i][j + 1] == '>')
				j++;
		}
		j++;
	}
}

int			ft_change_env(char **str, int i, t_list **env)
{
	char	*start;
	char	*tmp;
	char	*env_result;
	int		len;

	env_result = NULL;
	if ((len = ft_strlen_env(&(*str)[i])) <= 1)
		return (0);
	tmp = ft_strldup(&(*str)[i], len);
	if (!(env_result = ft_find_env(tmp, env)))
		env_result = ft_strdup("");
	free(tmp);
	start = ft_strldup(*str, i);
	tmp = ft_strjoin(start, env_result);
	free(start);
	start = ft_strjoin(tmp, ft_strdup(&(*str)[i + len]));
	free(*str);
	*str = start;
	return (len);
}

void		ft_check_env(char **str, t_list **env)
{
	int		i;
	int		quote;

	quote = 0;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == 34 || (*str)[i] == 39)
			quote = quote == 0 ? (*str)[i] : 0;
		if ((*str)[i] == '$' && quote != 39 && (*str)[i - 1] != '\\')
			i += ft_change_env(str, i, env) - 1;
		i++;
	}
}

void		ft_parse_commands(t_mini *mini, t_list **env, int i)
{
	ft_check_env(&mini->commands[i], env);
	ft_create_token(mini, i);
}
