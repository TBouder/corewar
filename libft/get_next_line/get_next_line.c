/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/08/24 15:15:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_return_value(t_gnl *gnl)
{
	if (gnl->i > 0)
	{
		gnl->buff[gnl->i] = '\0';
		if (!(gnl->line = ft_strjoin(gnl->str, gnl->buff)))
			return (-1);
		free(gnl->str);
		gnl->str = gnl->line;
		gnl->tmp = ft_strchr(gnl->str, '\n');
	}
	else if (gnl->i == 0)
	{
		gnl->tmp = ft_strchr(gnl->str, '\0');
		if (ft_strequ((gnl->tmp), gnl->str))
			return (0);
	}
	else if (gnl->i < 0)
		return (-1);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	gnl;

	gnl.buff = ft_strnew(BUFF_SIZE + 1);
	if (!gnl.str && (gnl.str = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	gnl.tmp = ft_strchr(gnl.str, '\n');
	while (gnl.tmp == NULL)
	{
		gnl.i = read(fd, gnl.buff, BUFF_SIZE);
		if ((gnl.y = ft_return_value(&gnl)) < 1)
			return (gnl.y);
	}
	if (!(*line = ft_strsub(gnl.str, 0, gnl.tmp - gnl.str)))
		return (-1);
	gnl.tmp = ft_strdup(gnl.tmp + 1);
	ft_strdel(&gnl.str);
	gnl.str = ft_strinit(gnl.tmp);
	return (1);
}
