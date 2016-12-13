/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_ncurse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:20:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/14 00:16:13 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

void			ft_reload_windows(t_vm *env, int part)
{
	if (part == 1)
	{
		wclear(env->main);
		ft_dump_ncurse(env, env->map, MEM_SIZE);
		usleep(12000);
		wrefresh(env->main);
	}
	else if (part == 2)
	{
		wclear(env->info);
		wprintw(env->info, "Cycle : %d", env->cycle);
		usleep(12000);
		wrefresh(env->info);
	}
}
