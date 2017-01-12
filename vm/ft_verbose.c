/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:17:02 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/10 14:54:50 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_verbose_fork(t_vm *env, t_champions *champ, t_champions *c)
{
	if (champ)
	{
		if (IS_GRAPH)
		{
			ft_print_champion_color(champ, env->notif);
			wprintw(env->notif, " has been forked\n");
			ft_reload_windows(env, 3);
		}
		else if (!IS_SILENT)
		{
			ft_printf("A new Champion, {14}%d{0} ({14}%s{0}) ",
				c->champ_id, c->name);
			ft_printf("has been forked at {14}map[%d]{0} !\n", c->pc);
		}
	}
}

void		ft_verbose_champ_info(t_vm *env, t_champions *champ, int part)
{
	if (part == 1 && !IS_SILENT)
	{
		ft_printf("{9}------{0} Champion {14}%d{0} (Nb champ : {14}%d{0} ",
			champ->fake_id, champ->champ_id);
		ft_printf("Unique Id : {14}%d{0}) ", champ->id);
		ft_printf("({14}%s{0}) %s{9}------{0}\n", champ->name,
		champ->is_fork ? "({11}Forked Champion{0}) " : "");
		ft_printf("Current cycle : {14}%d{0}\n", env->cycle);
		ft_printf("Current PC : {14}%d{0}\n", champ->pc);
	}
	if (part == 2 && !IS_SILENT)
	{
		ft_printf("Carry : {14}%d{0}\n", champ->carry);
		ft_printf("New PC : {14}%d{0}\n", champ->pc);
		ft_printf("The next cycle : {14}%d{0}\n\n\n", champ->next_cycle);
	}
}

void		ft_verbose_dead(t_vm *env, t_champions *champ)
{
	if (IS_GRAPH)
	{
		ft_print_champion_color(champ, env->notif);
		champ->is_fork ? wprintw(env->notif, " (Forked Champion)") : 0;
		wprintw(env->notif, " is now dead\n");
		ft_reload_windows(env, 3);
	}
	else if (!IS_SILENT)
	{
		ft_printf("[%d] The champion {14}%d{0} ({14}%s{0}) ",
			env->cycle, champ->champ_id, champ->name);
		champ->is_fork ? ft_printf("({11}Forked Champion{0}) ") : 0;
		ft_printf("is now {9}dead{0} !\n");
	}
}

void		ft_verbose_winner(t_vm *env)
{
	int		key;

	if (IS_GRAPH)
	{
		werase(env->notif);
		if (env->winner->name == NULL)
			wprintw(env->notif, "There is no winner this time !\n");
		else
			wprintw(env->notif, "The winner is %d (%s) !\n",
				env->winner->fake_id, env->winner->name);
		wnoutrefresh(env->notif);
		doupdate();
		while ((key = getch()) != 'q')
			;
		ft_clear_ncurse(env);
	}
	else
	{
		if (env->winner->name == NULL)
			ft_printf("There is no winner this time !\n");
		else
			ft_printf("The winner is {14}%d{0} ({14}%s{0}) !\n",
				env->winner->fake_id, env->winner->name);
	}
	ft_success_vm(env, 1);
}
