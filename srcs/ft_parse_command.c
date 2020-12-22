/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:00:50 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/19 20:01:56 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../minishell.h"


 static void		ft_printlist(void *content)
{
	t_mini *env;
	int i;

	i = 0;
	env = (t_mini *)content;
	ft_printf("%d ",env->type);	
	while (env->argv[i])
	{
		ft_printf("%s x", env->argv[i]);
		i++;
	}
	ft_printf("\n");
}

int	ft_datatype(char *tmp, t_mini *data)
{
	if (*tmp == '|')
		data->type = 1;
	else if (*tmp == '<')
		data->type = 2;
	else if (*tmp == '>' && tmp[1] == ' ')
		data->type = 3;
	else if (*tmp == '>' && tmp[1] == '>')
	{
		data->type = 4;
		return (2);
	}
	else
	{
		data->type = 0;
		return (0);
	}
	return (1);

}

void		ft_new_token(t_list **mini, char *command)
{
	t_mini	*token;
	int i;
	char *tmp;

	i = 0;
	
	tmp = ft_strdup(command);
	token = (t_mini *)malloc(sizeof(t_mini) * 1);
	tmp += ft_datatype(tmp, token);
	while (!(ft_strchr("<|>",tmp[i])) && tmp[i])
		i++;
	tmp[i] = 0;
	token->argv = ft_split_mini(tmp, ' ');
	t_list *new = ft_lstnew((const void *)token);
	ft_lstadd_back(mini, new);
}

void		ft_create_token(t_list **mini, char *command)
{
	int i;

	i = 0;
	ft_new_token(mini, command);
	while (command[i])
	{
		if (ft_strchr("<|>", command[i]))
		{
			if (command[i + 1] == '>')
				i++;
			ft_new_token(mini, &command[i]);
		}
		i++;
	}
	ft_lstiter(*mini,ft_printlist);
}





static	int		ft_change_env(char **str, int i, t_list **env)
{
	char *start;
	char *env_var;
	char *env_result;
	char *aux;
	char *end;
	int len;

	env_result = NULL;
	len = ft_strlen_token(&(*str)[i]);
	if (len == 0)
		return (0);
	env_var = ft_strldup(&(*str)[i], len);
	env_result = ft_find_env(env_var, env);
	if (!env_result)
		return (0);
	start = ft_strldup(*str, i);
	aux = ft_strjoin(start,env_result);
	len = ft_strlen(env_var);
	end = ft_strdup(&(*str)[i  + len]);
	free(start);
	start = ft_strjoin(aux,end);
	free(*str);
	*str = start;
	//ft_printf("->%s\n", str);
	return(len);

}
void	ft_check_env(char **str, t_list **env)
{
	int i;
	int quote;

	quote = 0;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == 34 || (*str)[i] == 39 )
			quote = quote == 0 ? (*str)[i] : 0;
		if ((*str)[i] == '$' && quote != 39)
			i += ft_change_env(str, i ,env);
		i++;
	}
}

void        ft_parse_commands(char *command, t_list **env, t_list **mini)
{
	ft_check_env(&command, env);
	ft_create_token(mini, command);
}
