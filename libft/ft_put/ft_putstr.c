/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/08 20:51:02 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr() function prints the string str to STDIN.
*/

#include "../libft.h"

void		ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
