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

#include "libft.h"
/*
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
}*/

static	unsigned	int		ft_linelen(char *tab)
{
	unsigned int			i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	return (i);
}

static char					*ft_line(char *tab)
{
	if (ft_strchr(tab, '\n'))
	{
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1);
		return (tab);
	}
	if (ft_linelen(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		return (tab);
	}
	return (NULL);
}

int							get_next_line(int const fd, char **line)
{
	char					*tmp;
	char					buff[BUFF_SIZE + 1];
	static	char			*tab[256];
	int						ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(tab[fd], '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strnjoin(tmp, buff, ret);
		free(tmp);
	}
	*line = ft_strsub(tab[fd], 0, ft_linelen(tab[fd]));
	if (ft_line(tab[fd]) == NULL)
		return (0);
	return (1);
}