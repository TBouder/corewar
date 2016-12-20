/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/20 19:25:33 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define IS_GRAPH env->options->flags['g']
#define IS_VERBOSE env->options->flags['v']
#define IS_DUMP env->options->flags['d']

void	ft_verbose(t_vm *env, t_champions *champion, int part)
{
	if (part == 1)
	{
		ft_put("{9}------{0} Champion {14}%d{0} ({14}%s{0}) %s{9}------{0}\n",
		champion->champ_id, champion->name,
		champion->is_fork ? "({11}Forked champion{0}) " : "");
		ft_put("Current cycle : {14}%d{0}\n", env->cycle);
		ft_put("Current PC : {14}%d{0}\n", champion->pc);
	}
	if (part == 2)
	{
		ft_put("New PC : {14}%d{0}\n", champion->pc);
		ft_put("The next cycle : {14}%d{0}\n\n\n", champion->next_cycle);
	}
}

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
	t_champions *champion;
	t_list		*list;
	int			nb_live;

	nb_live = 0;
	list = env->list_champions;
	while (list)
	{
		champion = ((t_champions *)list->content);
		if (champion->exist == TRUE)
		{
			if (champion->is_alive <= 0)
			{
				champion->exist = FALSE; //MORT DU PROGRAMME
				IS_GRAPH ? ft_print_champion_color(champion, env->notif) : 0;
				IS_GRAPH ? wprintw(env->notif, " IS NOW DEAD\n") : 0;
				IS_GRAPH ? ft_reload_windows(env, 3) : 0;
			}
			else
				nb_live += champion->is_alive;
			champion->is_alive = 0;
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
		// ft_print_champion_color(champ, env->notif);
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
	t_champions *champion;
	t_list		*list;

	list = env->list_champions;
	while (list)
	{
		champion = ((t_champions *)list->content);
		if (champion->exist == TRUE)
		{
			// if (champion->is_fork)
				// ft_put("{11}IS FORK : %d / %d{0}\n", env->cycle,champion->next_cycle);
			if (env->cycle == champion->next_cycle)
			{
				// ft_printf("PC = {13}%d{0}\n", champion->pc);
				!IS_GRAPH && IS_VERBOSE ? ft_verbose(env, champion, 1) : 0;
				ft_exec_instruct(env, champion);
				!IS_GRAPH && IS_VERBOSE ? ft_verbose(env, champion, 2) : 0;
			}
		}
		list = list->next;
	}
}

void	ft_fight(t_vm *env)
{
	int v = 0;

	IS_GRAPH ? ft_reload_windows(env, 1) : 0; //CREATION OF THE MAP
	IS_GRAPH ? ft_reload_windows(env, 2) : 0; //CREATION OF THE INFOS

	while (ft_one_isalive(env) && v++ < 1000000)
	{
		if (IS_DUMP && env->cycle == env->dump_cycle)
		{
			ft_dump(env->map, MEM_SIZE);
			break ;
		}

		IS_GRAPH ? ft_reload_windows(env, 2) : 0;

		ft_foreach_champ(env);

		if (env->cpt_to_die == env->cycle_to_die)
		{
			if (ft_which_isalive(env) >= NBR_LIVE)
			{
				// wprintw(env->notif, "HERE\n");
				ft_reload_windows(env, 3);
				env->cycle_to_die -= CYCLE_DELTA;
				env->cycle_check = 0;
			}
			env->cpt_to_die = 0;
			env->cycle_check++;
		}

		if (env->cycle_check == MAX_CHECKS)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			env->cycle_check = 0;
		}
		env->cycle++;
		env->cpt_to_die++;
	}
	ft_print_winner(env);
}
