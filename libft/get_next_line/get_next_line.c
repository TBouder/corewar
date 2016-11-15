/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/11/09 16:09:55 by quroulon         ###   ########.fr       */
=======
/*   Updated: 2016/11/15 13:05:01 by tbouder          ###   ########.fr       */
>>>>>>> tbouder
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
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
=======
int				ft_free_return(t_gnl *gnl, int value)
{
	ft_strdel(&gnl->buff);
	ft_strdel(&gnl->tmp);
	return (value);
}

int				ft_return_value(t_gnl *gnl)
>>>>>>> tbouder
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
	gnl.y = 0;
	gnl.buff = ft_strnew(BUFF_SIZE + 1);
<<<<<<< HEAD
	if (gnl.str == NULL && (gnl.str = ft_strnew(1)) == NULL)
		return (-1);
=======
	if (!gnl.str && (gnl.str = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (ft_free_return(&gnl, -1));
>>>>>>> tbouder
	gnl.tmp = ft_strchr(gnl.str, '\n');
	if (line == NULL)
		return (-1);
	while (gnl.tmp == NULL)
	{
		gnl.i = read(fd, gnl.buff, BUFF_SIZE);
		if ((gnl.y = ft_return_value(&gnl)) < 1)
<<<<<<< HEAD
		{
			ft_strdel(&gnl.buff);
			ft_strdel(&gnl.str);
			return (gnl.y);
		}
	}
	return (ft_clear(&gnl, line));
=======
			return (ft_free_return(&gnl, gnl.y));
	}
	if (!(*line = ft_strsub(gnl.str, 0, gnl.tmp - gnl.str)))
		return (ft_free_return(&gnl, -1));
	gnl.tmp = ft_strdup(gnl.tmp + 1);
	ft_strdel(&gnl.str);
	gnl.str = ft_strinit(gnl.tmp);
	return (ft_free_return(&gnl, 1));
>>>>>>> tbouder
}
