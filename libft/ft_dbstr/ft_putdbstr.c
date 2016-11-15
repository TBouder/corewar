/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:37:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 16:54:21 by tbouder          ###   ########.fr       */
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
