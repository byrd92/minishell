/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:45:12 by jalcayne          #+#    #+#             */
/*   Updated: 2020/11/12 11:51:29 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*ft_strsub_get(char const *s, unsigned int start, size_t len);
int		ft_strlen_get(const char *str);
char	*ft_strjoin_get(char const *s1, char const *s2);
char	*ft_strnew_get(size_t size);
char	*ft_strdup_get(const char *s1);
char	*ft_strchr_get(const char *s, int c);
int		appendline(int ret, int fd, char **rest, char **line);
#endif
