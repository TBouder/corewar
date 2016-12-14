/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_ncurse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:20:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/14 17:17:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define COLS_MAIN	(2 * COLS / 3)// + 1
#define COLS_INFO	(COLS / 3)
#define LINES_INFO	(2 * LINES / 3)// + 1
#define LINES_NOTIF	(LINES / 3)

void			ft_init_ncurse(t_vm *env)
{
	initscr();

	env->main_border = subwin(stdscr, LINES, COLS_MAIN, 0, 0);
	env->info_border = subwin(stdscr, LINES_INFO, COLS_INFO, 0, COLS_MAIN);
	env->notif_border = subwin(stdscr, LINES_NOTIF + 1, COLS_INFO, LINES_INFO, COLS_MAIN);

	env->main = subwin(stdscr, LINES - 2, COLS_MAIN - 3, 1, 2);
	env->info = subwin(stdscr, LINES_INFO - 2, COLS_INFO - 3, 1, COLS_MAIN + 2);
	env->notif = subwin(stdscr, LINES_NOTIF - 4, COLS_INFO - 3, LINES_INFO + 1, COLS_MAIN + 2);

	box(env->main_border, ACS_VLINE, ACS_HLINE);
	box(env->info_border, ACS_VLINE, ACS_HLINE);
	box(env->notif_border, ACS_VLINE, ACS_HLINE);
	noecho();	//N'affiche pas les char tapes
	curs_set(FALSE); //N'affiche pas le curseur
	// cbreak();	//Essaye de catch un char
	nodelay(stdscr, TRUE);	//getch n'est plus bloquant

	start_color();
	init_color(COLOR_BLACK, 224, 248, 299);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);

	// getch(); //TO START
	refresh();

}

void			ft_clear_ncurse(t_vm *env)
{
	endwin();
	free(env->main);
	free(env->info);
}

void			ft_get_key(t_vm *env)
{
	int				key;

	key = getch();
	if (key == 'q')
	{
		clear();
		refresh();
		exit(0);
	}
	else if (key == ' ')
	{
		while ((key = getch()) != ' ')
			;
	}
	else if (key == '+' && env->usleep < 250000)
		env->usleep += 1000;
	else if (key == '-' && env->usleep > 1000)
		env->usleep -= 1000;
}

void			ft_reload_windows(t_vm *env, int part)
{
	ft_get_key(env);
	if (part == 1) //LA MAP
	{
		werase(env->main);
		ft_dump_ncurse(env, env->map, MEM_SIZE);
		wnoutrefresh(env->main);
	}
	else if (part == 2) //LES INFOS
	{
		werase(env->info);
		wattron(env->info, COLOR_PAIR(1) | A_BOLD);
		wprintw(env->info, "%*s\n", ((COLS_INFO - 3) / 2) + 11,"-----INFORMATIONS-----");
		wattroff(env->info, COLOR_PAIR(1) | A_BOLD);

		wprintw(env->info, "Cycle : ");
		wattron(env->info, COLOR_PAIR(1) | A_BOLD);
		wprintw(env->info, "%d\n", env->cycle);
		wattroff(env->info, COLOR_PAIR(1) | A_BOLD);

		wprintw(env->info, "Sleep delay : ", env->usleep);
		wattron(env->info, COLOR_PAIR(1) | A_BOLD);
		wprintw(env->info, "%d\n", env->usleep);
		wattroff(env->info, COLOR_PAIR(1) | A_BOLD);

		wprintw(env->info, "Number of Champion(s) : ");
		wattron(env->info, COLOR_PAIR(1) | A_BOLD);
		wprintw(env->info, "%d\n", env->nb_champ);
		wattroff(env->info, COLOR_PAIR(1) | A_BOLD);

		wnoutrefresh(env->info);
	}
	else if (part == 3) //LES NOTIFS
	{
		if (env->nb_notif == (unsigned int)(LINES / 3) - 4)
		{
			werase(env->notif);
			env->nb_notif = 0;
		}
		wnoutrefresh(env->notif);
		env->nb_notif++;
	}
	doupdate();
	usleep(env->usleep);
}