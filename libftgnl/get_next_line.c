/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:11:17 by msteer            #+#    #+#             */
/*   Updated: 2018/08/17 21:49:30 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(char **str, int fd)
{
	int			r;
	char		*s;
	char		buf[BUFF_SIZE + 1];

	if ((r = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[r] = '\0';
	s = *str;
	*str = ft_strjoin(*str, buf);
	if (*s)
		free(s);
	return (r);
}

static int		ft_get(char **str, char **line, char *s)
{
	int			i;
	char		*j;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	if (i == 0 && ft_strlen(*str) != 0)
	{
		*str = ft_strnew(1);
		return (1);
	}
	else if (i == 0 && !(ft_strlen(*str)))
		return (0);
	j = *str;
	*str = ft_strjoin(s + 1, "");
	free(j);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	int			r;
	char		*s;
	static char *str;

	if (str == 0)
		str = "";
	if (!line || BUFF_SIZE < 1 || fd < 0)
		return (-1);
	r = BUFF_SIZE;
	while (line)
	{
		s = str;
		while (*s || r < BUFF_SIZE)
		{
			if (*s == '\n' || *s == 0 || *s == -1)
				return (ft_get(&str, line, s));
			s++;
		}
		if ((r = ft_read(&str, fd)) == -1)
			return (-1);
	}
	return (0);
}
