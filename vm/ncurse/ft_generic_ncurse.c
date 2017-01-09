/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_ncurse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:20:23 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 09:40:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		ft_init_colors(void)
{
	init_color(42, 498, 866, 298);
	init_color(43, 1000, 863, 274);
	init_color(44, 980, 643, 376);
	init_color(45, 986, 541, 996);
	init_color(52, 298, 666, 98);
	init_color(53, 800, 663, 74);
	init_color(54, 780, 443, 176);
	init_color(55, 786, 341, 796);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(42, 42, COLOR_BLACK);
	init_pair(43, 43, COLOR_BLACK);
	init_pair(44, 44, COLOR_BLACK);
	init_pair(45, 45, COLOR_BLACK);
	init_pair(52, COLOR_BLACK, 7);
	init_pair(53, COLOR_BLACK, 7);
	init_pair(54, COLOR_BLACK, 7);
	init_pair(55, COLOR_BLACK, 7);
	init_pair(62, 52, COLOR_BLACK);
	init_pair(63, 53, COLOR_BLACK);
	init_pair(64, 54, COLOR_BLACK);
	init_pair(65, 55, COLOR_BLACK);
	init_pair(72, COLOR_BLACK, 42);
	init_pair(73, COLOR_BLACK, 43);
	init_pair(74, COLOR_BLACK, 44);
	init_pair(75, COLOR_BLACK, 45);
}

void			ft_init_ncurse(t_vm *env)
{
	initscr();
	env->main_border = subwin(stdscr, LINES, COLS_MAIN, 0, 0);
	env->info_border = subwin(stdscr, LINES_INFO, COLS_INFO, 0, COLS_MAIN);
	env->notif_border = subwin(stdscr, LINES_NOTIF + 1, COLS_INFO, LINES_INFO,
						COLS_MAIN);
	env->main = subwin(stdscr, LINES - 2, COLS_MAIN - 3, 1, 2);
	env->info = subwin(stdscr, LINES_INFO - 2, COLS_INFO - 3, 1, COLS_MAIN + 2);
	env->notif = subwin(stdscr, LINES_NOTIF - 4, COLS_INFO - 3, LINES_INFO + 1,
						COLS_MAIN + 2);
	box(env->main_border, ACS_VLINE, ACS_HLINE);
	box(env->info_border, ACS_VLINE, ACS_HLINE);
	box(env->notif_border, ACS_VLINE, ACS_HLINE);
	start_color();
	init_color(COLOR_BLACK, 224, 248, 299);
	ft_init_colors();
	noecho();
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	refresh();
}

void			ft_clear_ncurse(t_vm *env)
{
	clear();
	delwin(env->main);
	delwin(env->info);
	delwin(env->notif);
	delwin(env->main_border);
	delwin(env->info_border);
	delwin(env->notif_border);
	endwin();
}

static void		ft_key_pause(t_vm *env)
{
	int		key;

	env->n_key = 0;
	while (1)
	{
		key = getch();
		if (key == ' ' || key == 'n')
		{
			key == 'n' ? env->n_key = 1 : 0;
			break ;
		}
		else if (key == 'q')
		{
			ft_error_vm(env, "ASK TO LEAV PROG", 1);
			exit(0);
		}
		else if (key == '+' || key == '-')
		{
			env->usleep += (key == '+' && env->usleep < 250000) ? 1000 : 0;
			env->usleep -= (key == '-' && env->usleep > 1000) ? 1000 : 0;
			IS_GRAPH ? ft_reload_windows(env, 2) : 0;
		}
	}
}

void			ft_get_key(t_vm *env)
{
	int				key;

	if (env->n_key == 0)
	{
		key = getch();
		if (key == ' ')
			ft_key_pause(env);
		else if (key == 'q')
		{
			ft_error_vm(env, "ASK TO LEAV PROG", 1);
			exit(0);
		}
		else if (key == '+' && env->usleep < 250000)
			env->usleep += 1000;
		else if (key == '-' && env->usleep > 0)
			env->usleep -= 1000;
		else if (key == 'n')
			env->n_key = 1;
	}
	else
		ft_key_pause(env);
}
