/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:52:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/24 13:51:40 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_dbstrdel() function desallocs **str
*/

#include "../libft.h"

void		ft_dbstrdel(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}
