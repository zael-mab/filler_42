/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:05:12 by hseffian          #+#    #+#             */
/*   Updated: 2019/05/23 04:58:53 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_checkfile(int fd, char *str)
{
	int		r;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	if (!str)
		str = ft_strnew(0);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char *str[4864];
	int			i;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];

	i = 0;
	if (fd < 0 || read(fd, buff, 0) < 0 || line == NULL
			|| fd > 4864 || BUFF_SIZE < 1)
		return (-1);
	str[fd] = ft_checkfile(fd, str[fd]);
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	if (str[fd][0])
	{
		*line = ft_strsub(str[fd], 0, i);
		i = str[fd][i] == '\n' ? i + 1 : i;
		tmp = str[fd];
		str[fd] = ft_strdup(str[fd] + i);
		free(tmp);
		return (1);
	}
	else
		return (0);
}
