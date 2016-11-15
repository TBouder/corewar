/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:37:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 15:27:34 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putdbstr() function print all the cells of the tab [tab]
*/

#include "../libft.h"

void	ft_putdbstr(char **tab, size_t size)
{
	size_t		i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		ft_printf("{42}%s{0}\n", tab[i]);
		i++;
	}
}
