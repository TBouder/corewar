/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:23 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/06 10:51:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_fight_init_graph() function initialises the three boxes with Ncurse if
** the graphic mode is enable.
*/

static void		ft_fight_init_graph(t_vm *env)
{
	ft_reload_windows(env, 1);
	ft_reload_windows(env, 2);
	ft_reload_windows(env, 3);
}

/*
** The ft_foreach_champ() function performs all the instructions for each
** champions.
*/

static void		ft_foreach_champ(t_vm *env)
{
	t_champions *champ;
	t_list		*list;
	int			pc;

	list = env->list_champions;
	while (list && list->content)
	{
		champ = (t_champions *)list->content;
		if (champ && env->cycle == champ->next_cycle && champ->alive)
		{
			!IS_GRAPH && IS_VERBOSE ? ft_verbose_champ_info(env, champ, 1) : 0;
			pc = champ->pc;
			champ->next_cycle = env->cycle;
			champ->next_cycle += ft_get_args(env, champ, (int)env->map[pc]);
			IS_GRAPH ? ft_reload_windows(env, 1) : 0;
			!IS_GRAPH && IS_VERBOSE ? ft_verbose_champ_info(env, champ, 2) : 0;
		}
		list = list->next;
	}
}

/*
** The ft_perfom_checks() function performs all the checks related to the cycle
** and to kill a champion, reduce the cycle to die etc.
*/

static int		ft_perfom_checks(t_vm *env)
{
	int		ret;

	if (env->cpt_to_die == env->cycle_to_die)
	{
		if (ft_verif_alives(env) >= NBR_LIVE)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			env->cycle_to_die < 0 ? env->cycle_to_die = 0 : 0;
			env->cycle_check = 0;
			IS_GRAPH ? ft_reload_windows(env, 3) : 0;
		}
		env->cpt_to_die = 0;
		env->cycle_check++;
		env->total_live = 0;
		ret = ft_verif_one_alive(env);
		ft_reset_lives(env, 0);
		return (ret);
	}
	if (env->cycle_check == MAX_CHECKS)
	{
		env->cycle_to_die -= CYCLE_DELTA;
		env->cycle_to_die < 0 ? env->cycle_to_die = 0 : 0;
		env->cycle_check = 0;
	}
	return (1);
}

/*
** The ft_enter_loop() function determines is we can continue the main loop or
** not !
*/

static int		ft_enter_loop(t_vm *env)
{
	return ((IS_DUMP && !IS_GRAPH ? env->cycle < env->dump_cycle : 1)
		&& env->cycle_to_die > 0);
}

/*
** The ft_fight() function is the main part of the vm. It will performs all the
** instructions until all champions die.
*/

void			ft_fight(t_vm *env)
{
	IS_GRAPH ? ft_fight_init_graph(env) : 0;
	while (ft_enter_loop(env))
	{
		ft_foreach_champ(env);
		if (ft_perfom_checks(env) != 1)
			break ;
		env->cycle++;
		env->cpt_to_die++;
		IS_GRAPH ? ft_get_key(env) : 0;
		IS_GRAPH ? ft_reload_windows(env, 1) : 0;
		IS_GRAPH ? ft_reload_windows(env, 2) : 0;
	}
	IS_DUMP && !IS_GRAPH ? ft_dump(env->map, MEM_SIZE) : 0;
	ft_verbose_winner(env);
}
