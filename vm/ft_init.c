/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 13:04:45 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_init_reg(t_champions *new_champ, t_champions *champ)
{
	int		reg_nb;

	reg_nb = 0;
	// while (reg_nb <= REG_NUMBER)
	while (reg_nb <= 99)
	{
		new_champ->reg[reg_nb] = champ ? champ->reg[reg_nb] : 0;
		reg_nb++;
	}
}

void		ft_add_champion(t_vm *env, t_champions *champ, int id, int pc)
{
	t_champions	*new_champ;

	new_champ = (t_champions *)malloc(sizeof(t_champions));
	new_champ->name = champ ? champ->name : NULL;
	new_champ->comment = champ ? champ->comment : NULL;
	new_champ->content = champ ? champ->content : NULL;
	new_champ->magic = champ ? champ->magic : 0;
	new_champ->prog_size = champ ? champ->prog_size : 0;
	new_champ->starting_pos = champ ? champ->starting_pos : 0;
	new_champ->champ_id = id + 1;
	ft_init_reg(new_champ, champ);
	new_champ->reg[1] = champ ? champ->reg[1] : id + 1;
	new_champ->pc = pc;
	new_champ->pc_void = champ ? champ->pc_void : 0;
	new_champ->carry = champ ? champ->carry : FALSE;
	new_champ->is_alive = champ ? champ->is_alive : 1;
	new_champ->exist = champ ? champ->exist : TRUE;
	new_champ->cycle = champ ? champ->cycle : 0;
	new_champ->next_cycle = env->cycle + 1;
	new_champ->is_fork = champ ? 1 : 0;
	new_champ->color = champ ? champ->color : id + 42;
	ft_lststart(&env->list_champions, new_champ, sizeof(t_champions));
	ft_verbose_fork(env, champ, new_champ);
}

static void		ft_init_lst_champions(t_vm *env)
{
	int			i;

	i = 0;
	env->list_champions = NULL;
	while (i < env->nb_champ)
		ft_add_champion(env, NULL, i++, 0);
}

void			ft_init_env(t_vm *env, int part)
{
	if (part == 0)
	{
		env->options = NULL;
		env->nb_champ = 0;
		env->dump_cycle = 0;
		env->usleep = 50000;
		env->nb_notif = 0;
	}
	else
	{
		env->nb_champ = part;
		env->fd = ft_nbrnew(part);
		env->filename = ft_dbstrnew(part);
		env->header = (header_t *)malloc(sizeof(header_t) * part);
		ft_init_lst_champions(env);
		env->total_size = 0;
		env->map = ft_strnew(MEM_SIZE);
		env->map_owner = ft_nbrnew(MEM_SIZE);
		env->winner = NULL;
		env->cycle_to_die = CYCLE_TO_DIE;
		env->cpt_to_die = 0;
		env->cycle_check = 0;
		env->cycle = 0;
		env->arg1 = 0;
		env->arg2 = 0;
		env->arg3 = 0;
		env->buf = 0;
		env->sum_idx = 0;
		env->total_live = env->nb_champ;

		// env->detla = CYCLE_DELTA;
		// env->nbr_live = NBR_LIVE;
	}
}
