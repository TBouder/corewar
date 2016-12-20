/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reload_windows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:08:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/20 23:09:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

#define COLS_MAIN	(2 * COLS / 3)// + 1
#define COLS_INFO	(COLS / 3)
#define LINES_INFO	(2 * LINES / 3)// + 1
#define LINES_NOTIF	(LINES / 3)

static void		ft_reload_main(t_vm *env)
{
	werase(env->main);
	ft_dump_ncurse(env, env->map, MEM_SIZE);
	wnoutrefresh(env->main);
}

static void		ft_reload_info(t_vm *env)
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

	wprintw(env->info, "Lives : ");
	wattron(env->info, COLOR_PAIR(1) | A_BOLD);
	wprintw(env->info, "%d / %d\n", env->total_live, NBR_LIVE);
	wattroff(env->info, COLOR_PAIR(1) | A_BOLD);

	wprintw(env->info, "Cycle to die : ");
	wattron(env->info, COLOR_PAIR(1) | A_BOLD);
	wprintw(env->info, "%d / %d\n\n\n\n\n", env->cpt_to_die, env->cycle_to_die);
	wattroff(env->info, COLOR_PAIR(1) | A_BOLD);

	t_list *list;

	list = env->list_champions;
	while (list)
	{
		if (!((t_champions *)list->content)->is_fork)
		{
			ft_print_champion_color(((t_champions *)list->content), env->info);
			if (!((t_champions *)list->content)->is_fork)
			{
				wprintw(env->info, ": \n");
				wprintw(env->info, "\tLive : %d\n", ((t_champions *)list->content)->is_alive);
			}
		}
		list = list->next;
	}

	wnoutrefresh(env->info);
}

static void		ft_reload_notifs(t_vm *env)
{
	if (env->nb_notif == (unsigned int)(LINES / 3) - 4)
	{
		werase(env->notif);
		env->nb_notif = 0;
	}
	wnoutrefresh(env->notif);
	env->nb_notif++;
}

void			ft_reload_windows(t_vm *env, int part)
{
	ft_get_key(env);
	if (part == 1)
		ft_reload_main(env);
	else if (part == 2)
		ft_reload_info(env);
	else if (part == 3)
		ft_reload_notifs(env);
	doupdate();
	usleep(env->usleep);
}
