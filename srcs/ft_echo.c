/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:58:44 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/19 20:02:06 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int        ft_echo_env(char *str, t_list **env)
{
    int i;
    int size;
    char *variable;

    size = 0;
    i = 0;
    while (!(ft_isspace(str[size])) && str[size] != 0)
        size++;
    variable = malloc(sizeof(char *) * size);
    while (!(ft_isspace(*str)) && *str != 0)
    {
        variable[i] = *str;
        str++;
        i++;
    }
    //variable[i] = 0;
    ft_printf("%s", variable);
    (void)env;
    return 0;
}

void        ft_echo2(char *str ,int flag, t_list **env)
{
	int i;
	int coma_simple;
	int coma_hard;

	coma_simple = 0;
	coma_hard = 0;
	i = 0;
	while (str[i])
	{
		while (coma_simple == 0 && coma_hard == 0 && str[i] == ' ')
			i++;
		if (str[i] == 34)
		{
		   if (coma_hard == 0 && coma_simple == 0)
		   {
			i++;
			coma_hard = 1;          
		   }
		   else if (coma_hard == 1 && coma_simple == 0)
		   {
				coma_hard = 0;
				i++;
		   }

		}
		if (str[i] == 39)
		{
			if (coma_simple == 0 && coma_hard == 0)
			{
				i++;
				coma_simple = 1;
			}
			else if (coma_simple == 1)
			{
				i++;
				coma_simple = 0;
			}      
		}
        if (str[i] == '$')
        {
            if (!(coma_simple == 1 && coma_hard == 0))
            {
                i += ft_echo_env(&str[i], env);
                while (!(ft_isspace(str[i])))
                    i++;
            }
        }
		write(1, &str[i], 1);
		i++;
	}
	flag == 1 ? write(1, "", 1) : write(1, "\n", 1) ;
}

void        ft_echo(t_list **env, char *str)
{
	int flag;

	flag = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' && str[1] == 'n')
	{
		if (str[2] == ' ' )
		{
		    flag = 1;
		    str = &str[2];
		}
		else
			return;     
		while (ft_isspace(*str))
			str++;
	}
	ft_echo2(str,flag,env);
}