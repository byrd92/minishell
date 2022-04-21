/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chema <chema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:40:10 by jalcayne          #+#    #+#             */
/*   Updated: 2020/03/25 11:48:57 by chema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strchr_get(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i++])
			return (NULL);
	}
	return ((char *)&s[i]);
}

int		appendline(int ret, int fd, char **rest, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	if (ret < 0)
		return (-1);
	while (rest[fd][len] != '\n' && rest[fd][len] != '\0')
		len++;
	if (rest[fd][len] == '\n')
	{
		*line = ft_strsub_get(rest[fd], 0, len);
		temp = ft_strdup_get(&rest[fd][len + 1]);
		free(rest[fd]);
		rest[fd] = ft_strdup_get(temp);
		free(temp);
		return (1);
	}
	*line = ft_strdup_get(rest[fd]);
	free(rest[fd]);
	rest[fd] = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*rest[4096];
	int			ret;
	char		*temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 ||
	(!(buffer = (char *)malloc(BUFFER_SIZE + 1))))
		return (-1);
	if (rest[fd] == NULL)
		rest[fd] = ft_strdup_get("");
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = ft_strjoin_get(rest[fd], buffer);
		free(rest[fd]);
		rest[fd] = ft_strdup_get(temp);
		free(temp);
		if (ft_strchr_get(rest[fd], '\n'))
			break ;
	}
	free(buffer);
	return (appendline(ret, fd, rest, line));
}
