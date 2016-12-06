/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/06 13:21:09 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/******************************************************************************/
void			ft_init_corewar_func(int (*tab[17])(t_vm *env, t_champions *champ))
{
	tab[0] = NULL;
	tab[1] = &ft_corewar_live;
	tab[2] = &ft_corewar_ld;
	tab[3] = &ft_corewar_st;
	tab[4] = &ft_corewar_add;
	tab[5] = &ft_corewar_sub;
	tab[6] = &ft_corewar_and;
	tab[7] = &ft_corewar_or;
	tab[8] = &ft_corewar_xor;
	tab[9] = &ft_corewar_zjmp;
	tab[10] = &ft_corewar_ldi;
	tab[11] = &ft_corewar_sti;
	tab[12] = &ft_corewar_fork;
	tab[13] = &ft_corewar_lld;
	tab[14] = &ft_corewar_lldi;
	tab[15] = &ft_corewar_lfork;
	tab[16] = &ft_corewar_aff;
}
/******************************************************************************/

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
	int		(*tab[17])();

	ft_init_corewar_func(tab);
	champ_pc = champion->pc;
	champion->next_cycle = env->cycle;
	// ft_printf("{10}%d{0}\n", env->cycle);

/*
0370 0100 0102 9000 0000 0403 0100 0000 0102 d000 0102 0ad4 0003 0204 0b74 0400 0202 0454 0203 0209 0001 0854 0404 0409 0003 0000
0370 0100 0102 9000 0000 0403 0100 0000 0102 d000 0102 0ad4 0003 0204 0b74 0400 0202 0454 0203 0209 0001 0854 0404 0409 0000


	ST ->	0370	01			0001
	LD ->	0290	0000 0004	03
	LIVE ->	01		0000		0001
	LD ->	02D0	0001		02
	LDI ->	0AD4	0003		02		04
	STI ->	0B74	04			0002	02
	ADD ->	0454	02			03		02
	ZJMP ->	0900	0001
	XOR ->	0854	04			04		04
	ZJMP ->	09		0000

	ST				  LD							LIVE			  LD
	0370	0100	0102	9000	0000	0403	0100	0000	0102	d000
	0001	0203	0405	0607	0809	1011	1213	1415	1617	1819

			LDI						STI						ADD				  ZJMP
	0102	0ad4	0003	0204	0b74	0400	0202	0454	0203	0209
	2021	2223	2425	2627	2829	3031	3233	3435	3637	3839
	  LIVE
	0001	0854	0404	0409	0000
	4041	4243	4445	4647	4849
*/

	ft_printf("--[%x]--\n", env->map[17]);
	champion->next_cycle += tab[(int)env->map[champ_pc]](env, champion);
	ft_printf("Next action in {11}%d{0} loops\n", champion->next_cycle);
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
	while (ft_one_isalive(env) && v++ < 200)
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
