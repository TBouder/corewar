/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ncurse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:26:13 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 09:23:21 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void		ft_print_champion_color(t_champions *champion, WINDOW *win)
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

static void	ft_print_infos_helper(t_vm *env)
{
	wprintw(env->info, "Cycle to die : ");
	wattron(env->info, COLOR_PAIR(1) | A_BOLD);
	wprintw(env->info, "%d / %d\n\n\n\n\n", env->cpt_to_die, env->cycle_to_die);
	wattroff(env->info, COLOR_PAIR(1) | A_BOLD);
}

void		ft_print_infos(t_vm *env)
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
	wprintw(env->info, "Number of process : ");
	wattron(env->info, COLOR_PAIR(1) | A_BOLD);
	wprintw(env->info, "%d\n", env->nb_forks);
	wattroff(env->info, COLOR_PAIR(1) | A_BOLD);
	wprintw(env->info, "Lives : ");
	wattron(env->info, COLOR_PAIR(1) | A_BOLD);
	wprintw(env->info, "%d / %d\n", env->total_live, NBR_LIVE);
	wattroff(env->info, COLOR_PAIR(1) | A_BOLD);
	ft_print_infos_helper(env);
}

void		ft_print_champions_infos(t_vm *env)
{
	t_list		*list;
	t_champions	*champs;

	list = env->list_champions;
	while (list)
	{
		champs = (t_champions *)list->content;
		if (!champs->is_fork)
		{
			ft_print_champion_color(champs, env->info);
			if (champs->alive == 0 && env->nb_live[champs->champ_id] > 0)
				wprintw(env->info, " (ZOMBIE)");
			else if (champs->alive == 0)
				wprintw(env->info, " (DEAD)");
			wprintw(env->info, ": \n");
			wprintw(env->info, "\tLives :\t\t%d\n",
				env->nb_live[champs->champ_id]);
			wprintw(env->info, "\tPC :\t\t%d\n",
				champs->pc);
			wprintw(env->info, "\tNext Cycle :\t%d\n",
				champs->next_cycle);
		}
		list = list->next;
	}
}

void		ft_color_map(t_vm *env, t_champions *champ, int pc, char *sub_reg)
{
	pc %= M;
	env->map[pc] = ft_atoi_base(sub_reg, 16);
	env->map_owner[pc] = champ->color;
	env->map_moves[pc] = champ->color;
}
