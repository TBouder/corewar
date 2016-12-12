/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/12 20:07:16 by tbouder          ###   ########.fr       */
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
			if (champion->is_alive > 0)
				return (1);
		}
		list = list->next;
	}
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
				champion->exist = FALSE; //MORT DU PROGRAMME
			else
				nb_live += champion->is_alive;
			champion->is_alive = 0;
		}
		list = list->next;
	}
	return (nb_live);
}

void	ft_print_winner(t_vm *env)
{
	ft_put("Le joueur %d(%s) a gagne\n", env->winner->champ_id, env->winner->name);
	exit(1);
}

void	ft_exec_instruct(t_vm *env, t_champions *champion)
{
	int		champ_pc;

	champ_pc = champion->pc;
	champion->next_cycle = env->cycle;
	if (champ_pc < (int)champion->prog_size)
	{
		champion->next_cycle += ft_get_args(env, champion, (int)env->map[champ_pc]);
		ft_put("Next action in {11}%d{0} loops\n\n", champion->next_cycle);
	}

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
			if (env->cycle == champion->next_cycle)
			{
				ft_exec_instruct(env, champion);
			}
		}
		list = list->next;
	}
}

void	ft_fight(t_vm *env)
{
	int v = 0;
	while (ft_one_isalive(env) && v++ < 1000)
	{

		ft_foreach_champ(env);

		if (env->cpt_to_die == env->cycle_to_die)
		{
			if (ft_which_isalive(env) >= NBR_LIVE)
			{
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
	}

	// ft_print_winner(env);
}
