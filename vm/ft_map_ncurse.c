/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_ncurse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:20:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/13 18:18:27 by tbouder          ###   ########.fr       */
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

void			ft_reload_windows(t_vm *env)
{
	wclear(env->main);
	wclear(env->info);
	ft_dump_ncurse(env, env->map, MEM_SIZE);
	wprintw(env->info, "Cycle : %d", env->cycle);

	wrefresh(env->main);
	wrefresh(env->info);
	usleep(12000);
	// getch();                // On attend que l'utilisateur appui sur une touche pour quitter
}
