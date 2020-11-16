/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:58:44 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/16 20:15:21 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void        ft_echo2(char *str ,int flag)
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
        write(1, &str[i], 1);
        i++;
    }
    flag == 1 ? write(1, "", 1) : write(1, "\n", 1) ;
}

void        ft_echo(char *str)
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
        {
            return;
        }       
        while (ft_isspace(*str))
            str++;
    }
    ft_echo2(str,flag);
}

void        ft_parse_commands(char *command)
{
    char *alter;

    alter = command;
    if (ft_strncmp(alter, "echo ", 6) > 0)
        ft_echo(&alter[5]);
    //ft_printf("%s", command);

}