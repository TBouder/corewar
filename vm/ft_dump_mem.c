/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:15:11 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/30 20:33:17 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_dump() function dumps the memory without NCURSE
*/
static void		ft_print_hex_mem(char *add, size_t size)
{
	size_t		i;
	char		*hex;

	hex = ft_strinit("0123456789abcdef");
	i = 0;
	while (i < 64)
	{
		if (i < size)
		{
			ft_putchar(hex[(int)((unsigned char)add[i]) / 16]);
			ft_putchar(hex[(int)((unsigned char)add[i]) % 16]);
		}
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	ft_strdel(&hex);
}

void			ft_dump(const void *addr, size_t size)
{
	int		offset;

	offset = 0;
	while (size > 16)
	{
		ft_print_hex_mem((char *)addr + offset, 64);
		ft_put("\n");
		offset += 64;
		size -= 64;
	}
	ft_print_hex_mem((char *)addr + offset, size);
	ft_put("\n");
}
