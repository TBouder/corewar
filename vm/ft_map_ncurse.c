/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_ncurse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:20:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/13 18:11:14 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_print_hex_mem(t_vm *env, char *add, size_t size)
{
	size_t		i;
	char		*hex;

	hex = ft_strinit("0123456789abcdef");
	i = 0;
	while (i < 64)
	{
		if (i < size)
		{
			wprintw(env->main, "%c", hex[(int)((unsigned char)add[i]) / 16]);
			wprintw(env->main, "%c", hex[(int)((unsigned char)add[i]) % 16]);
		}
		else
		{
			wprintw(env->main, " ");
			wprintw(env->main, " ");
		}
		if (i % 2)
			wprintw(env->main, " ");
		i++;
	}
	ft_strdel(&hex);
}

void			ft_dump_ncurse(t_vm *env, const void *addr, size_t size)
{
	int		offset;

	offset = 0;
	while (size > 64)
	{
		ft_print_hex_mem(env, (char *)addr + offset, 64);
		wprintw(env->main, "\n");
		offset += 64;
		size -= 64;
	}
	ft_print_hex_mem(env, (char *)addr + offset, size);
	wprintw(env->main, "\n");
}

void			ft_init_ncurse(t_vm *env)
{
	initscr();              // NCURSE : Initilisation de la fenetre
	env->main = subwin(stdscr, LINES, 2 * COLS / 3, 0, 0);
	env->info = subwin(stdscr, LINES, COLS / 3, 0, 2 * COLS / 3);

    box(env->main, ACS_VLINE, ACS_HLINE);
    box(env->info, ACS_VLINE, ACS_HLINE);
}

void			ft_clear_ncurse(t_vm *env)
{
	endwin();
	free(env->main);
	free(env->info);
}
