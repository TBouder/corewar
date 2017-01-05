/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:32:18 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 19:41:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** For add & sub
*/
int		ft_set_buffer_1(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	return (0);
}

/*
** For and or xor & ld
*/

int		ft_set_buffer_2(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	else if (IS_DIR(nbr))
		return (4);
	else if (IS_IND(nbr))
		return (2);
	return (0);
}

/*
** For zjmp fork & forks
*/

int		ft_set_buffer_3(int nbr)
{
	if (IS_DIR(nbr))
		return (2);
	return (0);
}


/*
** For sti ldi lldi & st
*/

int		ft_set_buffer_4(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	else if (IS_DIR(nbr))
		return (2);
	else if (IS_IND(nbr))
		return (2);
	return (0);
}
