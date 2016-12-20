/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_ncurse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:20:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/20 23:12:09 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

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
	init_color(42, 498, 866, 298);
	init_color(43, 1000, 863, 274);
	init_color(44, 980, 643, 376);
	init_color(45, 986, 541, 996);

	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(42, 42, COLOR_BLACK);
	init_pair(43, 43, COLOR_BLACK);
	init_pair(44, 44, COLOR_BLACK);
	init_pair(45, 45, COLOR_BLACK);

	init_pair(52, COLOR_BLACK, 7);
	init_pair(53, COLOR_BLACK, 7);
	init_pair(54, COLOR_BLACK, 7);
	init_pair(55, COLOR_BLACK, 7);
	// getch(); //TO START
	refresh();

}

void			ft_print_champion_color(t_champions *champion, WINDOW *win)
{
	wprintw(win, "Champion ");
	wattron(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, "%d", champion->champ_id);
	wattroff(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, " (");
	wattron(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, "%s", champion->name);
	wattroff(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, ")");
}

void			ft_clear_ncurse(t_vm *env)
{
	endwin();
	free(env->main);
	free(env->info);
	free(env->notif);
	free(env->main_border);
	free(env->info_border);
	free(env->notif_border);
}

void			ft_get_key(t_vm *env)
{
	int				key;

	key = getch();
	if (key == 'q')
	{
		ft_clear_ncurse(env);
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
