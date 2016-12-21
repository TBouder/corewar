/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 13:54:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_one_isalive(t_vm *env)
{
	t_champions 	*champion;
	t_list			*list;

	list = env->list_champions;
	while (list)
	{
		champion = ((t_champions *)list->content);
		if (champion->exist == TRUE)
		{
			if (champion->is_alive >= 0)
				return (1);
		}
		list = list->next;
	}
	IS_GRAPH ? wprintw(env->notif, "NO PLAYER?\n") : 0;
	IS_GRAPH ? ft_reload_windows(env, 3) : 0;

	return (0);
}

int		ft_which_isalive(t_vm *env)
{
	t_champions *champ;
	t_list		*list;
	int			nb_live;

	nb_live = 0;
	list = env->list_champions;
	while (list)
	{
		champ = ((t_champions *)list->content);
		if (champ->exist == TRUE)
		{
			if (champ->is_alive <= 0)
			{
				champ->exist = FALSE; //MORT DU PROGRAMME
				ft_verbose_dead(env, champ);
			}
			else
				nb_live += champ->is_alive;
			champ->is_alive = 0;
		}
		list = list->next;
	}
	env->total_live = 0;
	return (nb_live);
}

void	ft_print_winner(t_vm *env)
{
	int		key;

	if (IS_GRAPH)
	{
		wprintw(env->notif, "END OF GAME : WINNER IS ???\n");
		ft_reload_windows(env, 3);
		while ((key = getch()) != 'q')
			;
		ft_clear_ncurse(env);
	}

	// ft_put("Le joueur %d(%s) a gagne\n", env->winner->champ_id, env->winner->name);
	exit(1);
}

void	ft_exec_instruct(t_vm *env, t_champions *champion)
{
	int		champ_pc;

	champ_pc = champion->pc;
	champion->next_cycle = env->cycle;
	champion->next_cycle += ft_get_args(env, champion, (int)env->map[champ_pc]);
}

void	ft_foreach_champ(t_vm *env)
{
	t_champions *champ;
	t_list		*list;

	list = env->list_champions;
	while (list)
	{
		champ = ((t_champions *)list->content);
		if (champ->exist == TRUE)
		{
			if (env->cycle == champ->next_cycle)
			{
				!IS_GRAPH && IS_VERBOSE ? ft_verbose_champ_info(env, champ, 1) : 0;
				ft_exec_instruct(env, champ);
				!IS_GRAPH && IS_VERBOSE ? ft_verbose_champ_info(env, champ, 2) : 0;
			}
		}
		list = list->next;
	}
}

static void		ft_fight_init_graph(t_vm *env)
{
	ft_reload_windows(env, 1);
	ft_reload_windows(env, 2);
	ft_reload_windows(env, 3);
}

static int		ft_enter_loop(t_vm *env)
{
	return (ft_one_isalive(env) &&
		(IS_DUMP && !IS_GRAPH ? env->cycle < env->dump_cycle : 1));
}

static void		ft_perfom_checks(t_vm *env)
{
	if (env->cpt_to_die == env->cycle_to_die)
	{
		if (ft_which_isalive(env) >= NBR_LIVE)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			env->cycle_check = 0;
			ft_reload_windows(env, 3);
		}
		env->cpt_to_die = 0;
		env->cycle_check++;
	}
	if (env->cycle_check == MAX_CHECKS)
	{
		env->cycle_to_die -= CYCLE_DELTA;
		env->cycle_check = 0;
	}
}

void	ft_fight(t_vm *env)
{
	int v = 0;

	IS_GRAPH ? ft_fight_init_graph(env) : 0;

	while (ft_enter_loop(env) && v++ < 3200)
	{
		ft_foreach_champ(env);
		IS_GRAPH ? ft_reload_windows(env, 2) : 0;
		ft_perfom_checks(env);
		env->cycle++;
		env->cpt_to_die++;
	}
	IS_DUMP && !IS_GRAPH ? ft_dump(env->map, MEM_SIZE) : 0;
	ft_print_winner(env);
}
