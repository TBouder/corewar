/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:28 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/03 15:05:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_init_lst_champions(t_vm *env)
{
	int			i;

	i = 0;
	env->list_champions = NULL;
	while (i < env->nb_champ)
		ft_init_champ(env, NULL, i++, 0);

}

static void		ft_init_env_helper(t_vm *env, int part)
{
	env->nb_champ = part;
	ft_verif_fake_id(env);
	env->fd = ft_nbrnew(part);
	env->filename = ft_dbstrnew(part);
	env->header = (header_t *)malloc(sizeof(header_t) * part);
	ft_init_lst_champions(env);
	env->total_size = 0;
	env->map = ft_strnew(MEM_SIZE);
	env->map_owner = ft_nbrnew(MEM_SIZE);
	env->map_moves = ft_nbrnew(MEM_SIZE);
	env->map_moves_buff = ft_nbrnew(MEM_SIZE);
	env->winner = (t_champions *)malloc(sizeof(t_champions));
	env->winner->name = NULL;
	env->winner->champ_id = 0;
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

void			ft_init_env(t_vm *env, int part)
{
	if (part == 0)
	{
		env->options = NULL;
		env->nb_champ = 0;
		env->dump_cycle = 0;
		// env->usleep = 50000;
		env->usleep = 0;
		env->nb_notif = 0;
		env->current_id = 0;
		env->n_key = 0;
		env->fake_id = ft_nbrnew(4);
		ft_init_fake_id(env);
		env->champs = NULL;
	}
	else
		ft_init_env_helper(env, part);
}

void			ft_init_reg(t_champions *new_champ, t_champions *champ)
{
	int		reg_nb;

	reg_nb = 0;
	while (reg_nb <= 99)
	{
		new_champ->reg[reg_nb] = champ ? champ->reg[reg_nb] : 0;
		reg_nb++;
	}
}

void			ft_init_fake_id(t_vm *env)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		env->fake_id[i] = i + 1;
		i++;
	}
}
