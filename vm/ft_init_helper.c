/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:10:11 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/04 14:58:47 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_init_champ() function adds a champion in the list, as a copy of
** champ or as a new one.
*/

static void		ft_init_champ_data(t_champions *new_champ, t_champions *champ)
{
	new_champ->name = champ ? ft_strinit(champ->name) : NULL;
	new_champ->comment = champ ? ft_strinit(champ->comment) : NULL;
	new_champ->content = champ ? ft_strinit(champ->content) : NULL;
	new_champ->magic = champ ? champ->magic : 0;
	new_champ->prog_size = champ ? champ->prog_size : 0;
}

static void		ft_init_champ_id(t_vm *env, t_champions *new_champ,
				t_champions *champ, int id)
{
	new_champ->id = env->current_id++;
	new_champ->champ_id = id + 1;
	ft_init_reg(new_champ, champ);

if (env->fake_id[id] == 1)
{
	new_champ->reg[1] = champ ? champ->reg[1] : -4;
	new_champ->fake_id = champ ? champ->fake_id : -4;
}
if (env->fake_id[id] == 2)
{
	new_champ->reg[1] = champ ? champ->reg[1] : -3;
	new_champ->fake_id = champ ? champ->fake_id : -3;
}
if (env->fake_id[id] == 3)
{
	new_champ->reg[1] = champ ? champ->reg[1] : -2;
	new_champ->fake_id = champ ? champ->fake_id : -2;
}
if (env->fake_id[id] == 4)
{
	new_champ->reg[1] = champ ? champ->reg[1] : -1;
	new_champ->fake_id = champ ? champ->fake_id : -1;
}
	// new_champ->reg[1] = champ ? champ->reg[1] : env->fake_id[id];
	// new_champ->fake_id = champ ? champ->fake_id : env->fake_id[id];
}

void			ft_init_champ(t_vm *env, t_champions *champ, int id, int pc)
{
	t_champions	*new_champ;

	new_champ = (t_champions *)malloc(sizeof(t_champions));
	ft_init_champ_data(new_champ, champ);
	ft_init_champ_id(env, new_champ, champ, id);
	new_champ->starting_pos = champ ? champ->starting_pos : 0;
	new_champ->pc = pc;
	new_champ->carry = champ ? champ->carry : FALSE;
	new_champ->cycle = champ ? champ->cycle : 0;
	new_champ->next_cycle = champ ? env->cycle + ft_ret_cycle((int)env->map[pc])
		: env->cycle;
	new_champ->is_fork = champ ? 1 : 0;
	new_champ->color = champ ? champ->color : id + 42;
	ft_lststart(&env->list_champions, new_champ, sizeof(t_champions));
	ft_verbose_fork(env, champ, new_champ);
	free(new_champ);
}
