/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_ncurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 20:32:37 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 09:18:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** The ft_dump_ncurse() function dumps the memory with NCURSE
*/

static void			ft_print_hex_mem_ncurse(t_vm *env, char *add, size_t size,
				int *col)
{
	size_t		i;
	char		*hex;

	hex = ft_strinit((char *)"0123456789abcdef");
	i = 0;
	while (i < 64)
	{
		if (i < size)
		{
			ft_get_ncurse_color(env, col, 1);
			wprintw(env->main, "%c", hex[(int)((unsigned char)add[i]) / 16]);
			wprintw(env->main, "%c", hex[(int)((unsigned char)add[i]) % 16]);
			ft_get_ncurse_color(env, col, 0);
		}
		if (i % 2)
			wprintw(env->main, " ");
		i++;
		*col += 1;
	}
	ft_strdel(&hex);
}

void				ft_dump_ncurse(t_vm *env, const void *addr, size_t size)
{
	int		offset;
	int		owner;

	offset = 0;
	owner = 0;
	while (size > 64)
	{
		ft_print_hex_mem_ncurse(env, (char *)addr + offset, 64, &owner);
		wprintw(env->main, "\n");
		offset += 64;
		size -= 64;
	}
	ft_print_hex_mem_ncurse(env, (char *)addr + offset, size, &owner);
	wprintw(env->main, "\n");
}
