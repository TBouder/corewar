/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/25 13:52:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"
# define BUFF_SIZE	100000

int					get_next_line(int const fd, char **line);

typedef struct		s_gnl
{
	int				i;
	int				y;
	char			*str;
	char			*tmp;
	char			*buff;
	char			*line;
}					t_gnl;

#endif
