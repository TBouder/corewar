/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reload_ncurse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:08:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/25 23:58:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		ft_reload_main(t_vm *env)
{
	werase(env->main);
	ft_dump_ncurse(env, env->map, MEM_SIZE);
	wnoutrefresh(env->main);
}

static void		ft_reload_info(t_vm *env)
{
	werase(env->info);
	ft_print_infos(env);
	ft_print_champions_infos(env);
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
	if (part == 1)
		ft_reload_main(env);
	else if (part == 2)
		ft_reload_info(env);
	else if (part == 3)
		ft_reload_notifs(env);
	doupdate();
	usleep(env->usleep);
}
