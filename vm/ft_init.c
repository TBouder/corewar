/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/12 20:17:21 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_init_lst_champions(t_vm *env)
{
	int			i;
	int			reg_nb;
	t_champions	*champion;

	i = 0;
	while (i < env->nb_champ)
	{
		champion = (t_champions *)malloc(sizeof(t_champions));
		champion->name = NULL;
		champion->comment = NULL;
		champion->magic = 0;
		champion->prog_size = 0;
		champion->content = NULL;
		champion->starting_pos = 0;
		champion->champ_id = i + 1;
		reg_nb = 0;
		while (reg_nb <= REG_NUMBER)
		{
			champion->reg[reg_nb] = 0;
			reg_nb++;
		}
		champion->reg[1] = i + 1;
		champion->pc = 0;
		champion->pc_void = 0;
		champion->carry = FALSE;
		champion->is_alive = 1;
		champion->exist = TRUE;
		champion->cycle = 0;
		champion->next_cycle = 0;

		if (i == 0)
			env->list_champions = ft_lstnew(champion, sizeof(t_champions));
		else
			ft_lstend(&env->list_champions, champion, sizeof(t_champions));
		i++;
	}
}

void			ft_init_env(t_vm *env, int part)
{
	if (part == 0)
	{
		env->options = NULL;
		env->nb_champ = 0;
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
		env->winner = NULL;

		env->cycle_to_die = CYCLE_TO_DIE;
		env->cpt_to_die = 0;
		env->cycle_check = 0;
		env->cycle = 0;

		env->arg1 = 0;
		env->arg2 = 0;
		env->arg3 = 0;
		env->buf = 0;

		// env->detla = CYCLE_DELTA;
		// env->nbr_live = NBR_LIVE;
	}
}
