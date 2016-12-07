/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 23:44:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/******************************************************************************
void			ft_init_corewar_func(int (*tab[17])(t_vm *env, t_champions *champ, int op))
{
	tab[0] = NULL;
	tab[1] = &ft_corewar_live;
	tab[2] = &ft_corewar_ld_lld;
	tab[3] = &ft_corewar_st_sti;
	tab[4] = &ft_corewar_add_sub;
	tab[5] = &ft_corewar_add_sub;
	tab[6] = &ft_corewar_and_or_xor;
	tab[7] = &ft_corewar_and_or_xor;
	tab[8] = &ft_corewar_and_or_xor;
	tab[9] = &ft_corewar_zjmp;

	tab[10] = &ft_corewar_ldi_lldi;
	tab[14] = &ft_corewar_ldi_lldi;

	tab[11] = &ft_corewar_st_sti;
	tab[12] = &ft_corewar_forks;
	tab[13] = &ft_corewar_ld_lld;

	tab[15] = &ft_corewar_forks;
	tab[16] = &ft_corewar_aff;
}
******************************************************************************/

int		ft_one_isalive(t_vm *env)
{
	int		i;

	i = 0;
	while (i < env->nb_champ)
	{
		if (env->champions[i].exist == TRUE)
		{
			if (env->champions[i].is_alive > 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int		ft_which_isalive(t_vm *env)
{
	int		i;
	int		nb_live;

	i = 0;
	nb_live = 0;
	while (i < env->nb_champ)
	{
		if (env->champions[i].exist == TRUE)
		{
			if (env->champions[i].is_alive <= 0)
				env->champions[i].exist = FALSE; //MORT DU PROGRAMME
			else
				nb_live += env->champions[i].is_alive;
			env->champions[i].is_alive = 0;
		}
		i++;
	}
	return (nb_live);
}

void	ft_print_winner(t_vm *env)
{
	ft_printf("Le joueur %d(%s) a gagne\n", env->winner->champ_id, env->winner->name);
	exit(1);
}

void	ft_exec_instruct(t_vm *env, t_champions *champion)
{
	int		champ_pc;
	// int		(*tab[17])();

	// ft_init_corewar_func(tab);
	champ_pc = champion->pc;
	champion->next_cycle = env->cycle;
	if (champ_pc < (int)champion->prog_size)
	{
		champion->next_cycle += ft_get_args(env, champion, (int)env->map[champ_pc]);

		// champion->next_cycle += tab[(int)env->map[champ_pc]](env, champion, (int)env->map[champ_pc]);
		ft_printf("Next action in {11}%d{0} loops\n\n", champion->next_cycle);
	}

}

void	ft_foreach_champ(t_vm *env)
{
	int			i;
	t_champions *champion;

	i = 0;
	while (i < env->nb_champ)
	{
		champion = &env->champions[i];
		if (champion->exist == TRUE)
		{
			if (env->cycle == champion->next_cycle)
			{
				ft_exec_instruct(env, champion);
			}
		}
		i++;
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
