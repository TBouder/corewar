/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:54:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/29 14:13:46 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strnew_hex() function mallocs a char buffer and init it with \x00 for
** HEX values
*/

#include "../libft.h"

char				*ft_strnew_hex(size_t size)
{
	char	*hex;
	int		i;

	hex = ft_strnew(size);
	i = 0;
	while (i < (int)size)
	{
		hex[i] = '\x00';
		i++;
	}
	return (hex);
}
