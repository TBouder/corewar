/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:17:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 13:55:35 by tbouder          ###   ########.fr       */
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
		else
		{
			ft_put("A new Champion, {14}%d{0} ({14}%s{0}) ",
				c->champ_id, c->name);
			ft_put("has been forked at {14}map[%d]{0} !\n", c->pc);
		}
	}
}

void		ft_verbose_champ_info(t_vm *env, t_champions *champ, int part)
{
	if (part == 1)
	{
		ft_put("{9}------{0} Champion {14}%d{0} ({14}%s{0}) %s{9}------{0}\n",
		champ->champ_id, champ->name,
		champ->is_fork ? "({11}Forked Champion{0}) " : "");
		ft_put("Current cycle : {14}%d{0}\n", env->cycle);
		ft_put("Current PC : {14}%d{0}\n", champ->pc);
	}
	if (part == 2)
	{
		ft_put("New PC : {14}%d{0}\n", champ->pc);
		ft_put("The next cycle : {14}%d{0}\n\n\n", champ->next_cycle);
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
	else
	{
		ft_put("The champion {14}%d{0} ({14}%s{0}) ",
			champ->champ_id, champ->name);
		champ->is_fork ? ft_put("({11}Forked Champion{0})") : 0;
		ft_put("is now {9}dead{0} !\n");
	}
}
