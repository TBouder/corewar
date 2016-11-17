/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:54:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/17 15:50:14 by tbouder          ###   ########.fr       */
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
	while (hex[i])
	{
		hex[i] = '\x00';
		i++;
	}
	return (hex);
}
