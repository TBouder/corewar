/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/09 16:04:19 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_clear(t_gnl *gnl, char **line)
{
	ft_strdel(&gnl->buff);
	if (!(*line = ft_strsub(gnl->str, 0, gnl->tmp - gnl->str)))
		return (-1);
	if (gnl->tmp[0] != '\0')
	{
		gnl->tmp = ft_strsub(gnl->tmp, 1, ft_strlen(gnl->tmp));
		ft_strdel(&gnl->str);
		gnl->str = ft_strnew(ft_strlen(gnl->tmp));
		gnl->str = ft_strcpy(gnl->str, gnl->tmp);
		ft_strdel(&gnl->tmp);
	}
	else
		ft_strdel(&gnl->str);
	return (1);
}

static int			ft_return_value(t_gnl *gnl)
{
	if (gnl->i > 0)
	{
		gnl->buff[gnl->i] = '\0';
		gnl->line = ft_strjoin(gnl->str, gnl->buff);
		ft_strdel(&gnl->str);
		gnl->str = gnl->line;
		gnl->tmp = ft_strchr(gnl->str, '\n');
	}
	else if (gnl->i == 0)
	{
		gnl->tmp = ft_strchr(gnl->str, '\0');
		if (ft_strequ(gnl->tmp, gnl->str))
			return (0);
	}
	else
		return (-1);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_gnl	gnl;

	gnl.i = 0;
	gnl.j = 0;
	gnl.buff = ft_strnew(BUFF_SIZE + 1);
	if (gnl.str == NULL && (gnl.str = ft_strnew(1)) == NULL)
		return (-1);
	gnl.tmp = ft_strchr(gnl.str, '\n');
	if (line == NULL)
		return (-1);
	while (gnl.tmp == NULL)
	{
		gnl.i = read(fd, gnl.buff, BUFF_SIZE);
		if ((gnl.j = ft_return_value(&gnl)) < 1)
		{
			ft_strdel(&gnl.buff);
			ft_strdel(&gnl.str);
			return (gnl.j);
		}
	}
	return (ft_clear(&gnl, line));
}
