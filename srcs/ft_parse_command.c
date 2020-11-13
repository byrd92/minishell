/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:58:44 by egarcia-          #+#    #+#             */
/*   Updated: 2020/11/13 20:10:33 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void        ft_echo2(char *str ,int flag)
{
    int i;
    int coma;

    coma = 0;
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    flag == 1 ? write(1, "\n", 1) : write(1, "", 1) ;
}

void        ft_echo(char *str)
{
    int flag;

    flag = 0;
    while (ft_isspace(*str))
        str++;
    if (*str == '-' && str[1] == 'n')
    {
        flag = 1;
        str = &str[2];
        while (ft_isspace(*str))
            str++;
    }
    //ft_echo2(str,flag);
}

void        ft_parse_commands(char *command)
{
    char *alter;

    alter = command;
    if (ft_strncmp(alter, "echo ", 6) > 0)
        ft_echo(&alter[5]);
    //ft_printf("%s", command);

}