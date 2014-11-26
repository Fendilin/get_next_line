/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 19:06:40 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/26 22:50:36 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_line(int const fd, char *buffer, char **saved)
{
	char	*tmp;
	char	*c;
	int		i;

	i = 0;
	while (!(c = ft_strchr(*saved, '\n'))
			&& (i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		tmp = *saved;
		*saved = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	if (i == -1)
		return (-1);
	if (i == 0 && !c)
		return (0);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static	char	*saved = NULL;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	char			*c;
	int				read;

	if (fd < 0 || line == NULL)
		return (-1);
	if (saved == NULL)
		saved = ft_strnew(1);
	read = ft_read_line(fd, buffer, &saved);
	if (read == -1)
		return (-1);
	if (read == 0)
	{
		*line = saved;
		saved = NULL;
		return (0);
	}
	c = ft_strchr(saved, '\n');
	*line = ft_strsub(saved, 0, c - saved);
	tmp = saved;
	saved = ft_strdup(c + 1);
	ft_strdel(&tmp);
	return (1);
}
