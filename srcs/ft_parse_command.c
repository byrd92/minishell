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
/*
 static void		ft_printlist(void *content)
{
	char *env;

	env = (char *)content;
	ft_printf("%s\n",env);
}

static int			ft_printlista(t_list **lista)
{
	ft_lstiter(*lista, ft_printlist);
	return (0);
}*/
/*
void	list_commands(t_list **alter, char *command)
{
	char *tmp;
	char *value;

	tmp = command;
	while (*command)
	{
		if (*command == '|')
		{
			*command = 0;
			value = ft_strdup(tmp);
			t_list *new = ft_lstnew((const void *)value);
			ft_lstadd_back(alter, new);
			tmp = command + 1;
		}
		command++;
	}
	value = ft_strdup(tmp);
	t_list *new = ft_lstnew((const void *)value);
	ft_lstadd_back(alter, new);
}
*/
char		*ft_strdup_word(char *word)
{
	int i;
	int j;
	int k;
	char *str;

	j = 0;
	i = 0;
	while (ft_isspace(word[i]))
		i++;
	k = i;
	while (word[k] && !ft_isspace(word[i]))
	{
		k++;
		j++;
	}
	str = malloc(sizeof(char)* j + 1);
	j = 0;
	while (word[i] && !ft_isspace(word[i]))
	{
		str[j] = word[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

void		ft_create_struct(t_mini *mini, char *command)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mini->in = 0;
	mini->out = 0;

	mini->comand_list = ft_split(command, '|');
	while (mini->comand_list[i])
	{
		
		while (mini->comand_list[i][j])
		{
			if (mini->comand_list[i][j] == '>' && mini->comand_list[i][j + 1] == ' ')
			{
				mini->out = 1;
				mini->output = ft_strdup_word(&mini->comand_list[i][j + 1]);
			}
			if (mini->comand_list[i][j] == '<')
			{
				mini->in = 1;
				mini->input = ft_strdup_word(&mini->comand_list[i][j + 1]);
			}
			if (mini->comand_list[i][j] == '>'  && mini->comand_list[i][j + 1] == '>')
			{
				mini->out = 2;
				mini->output = ft_strdup_word(&mini->comand_list[i][j + 1]);
			}
			j++;
		}
		
	ft_printf("%s\n", mini->output); 
	i++;
	}
}
void        ft_parse_commands(char *command, t_list **env)
{
	char *alter;
	t_mini	mini; 

	ft_create_struct(&mini, command);
	alter = NULL;
	alter = command;
	(void)env;
	/*
	if(ft_strncmp(alter, "echo ", 5) == 0)
		ft_echo(env ,&alter[5]);
    else if(ft_strncmp(alter, "export ", 7) == 0)
		ft_export(env, &alter[6]);
	else if(ft_strncmp(alter, "env", 3) == 0)
		ft_env(env);
	else if(ft_strncmp(alter, "unset ", 6) == 0)
	{
		ft_unset(env, &alter[5]);
	}
	else if(ft_strncmp(alter, "pwd", 3) == 0)
	{
		ft_pwd(env);
	}
	else if(ft_strncmp(alter, "cd ", 3) == 0)
	{
		ft_cd(&alter[2]);
	}
	*/
}