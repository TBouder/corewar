/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ncurse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:26:13 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/27 12:06:31 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			ft_print_champion_color(t_champions *champion, WINDOW *win)
{
	wprintw(win, "Champion ");
	wattron(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, "%d", champion->fake_id);
	wattroff(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, " (");
	wattron(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, "%s", champion->name);
	wattroff(win, COLOR_PAIR(champion->color) | A_BOLD);
	wprintw(win, ")");
}

void			ft_print_infos(t_vm *env)
{
	wattron(env->info, COLOR_PAIR(1) | A_BOLD);
	wprintw(env->info, "%*s\n", ((COLS_INFO - 3) / 2) + 11,
			"-----INFORMATIONS-----");
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
}

void			ft_print_champions_infos(t_vm *env)
{
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
				wprintw(env->info, "\tLive : %d\n",
					env->nb_live[((t_champions *)list->content)->champ_id]);
			}
		}
		list = list->next;
	}
}
