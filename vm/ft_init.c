/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 23:30:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_init_lst_champions(t_vm *env)
{
	int			i;

	i = 0;
	env->list_champions = NULL;
	while (i < env->nb_champ)
		ft_add_champion(env, NULL, i++, 0);
}

static void		ft_init_env_helper(t_vm *env, int part)
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
}

void			ft_init_reg(t_champions *new_champ, t_champions *champ)
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

void			ft_init_env(t_vm *env, int part)
{
	if (part == 0)
	{
		env->options = NULL;
		env->nb_champ = 0;
		env->dump_cycle = 0;
		env->usleep = 50000;
		env->nb_notif = 0;
		env->current_id = 0;
	}
	else
		ft_init_env_helper(env, part);
}

void			ft_set_nb_live(t_vm *env, int val)
{
	env->nb_live[0] = 0;
	env->nb_live[1] = val;
	env->nb_live[2] = val;
	env->nb_live[3] = val;
	env->nb_live[4] = val;
}
