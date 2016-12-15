/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/15 17:28:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#define IS_GRAPH env->options->flags['g']

static void	ft_init_reg(t_champions *new_champion, t_champions *champion)
{
	int		reg_nb;

	reg_nb = 0;
	// while (reg_nb <= REG_NUMBER)
	while (reg_nb <= 99)
	{
		new_champion->reg[reg_nb] = champion ? champion->reg[reg_nb] : 0;
		reg_nb++;
	}
}

void		ft_add_champion(t_vm *env, t_champions *champion, int id, int pc)
{
	t_champions	*new_champion;

	new_champion = (t_champions *)malloc(sizeof(t_champions));
	new_champion->name = champion ? champion->name : NULL;
	new_champion->comment = champion ? champion->comment : NULL;
	new_champion->content = champion ? champion->content : NULL;
	new_champion->magic = champion ? champion->magic : 0;
	new_champion->prog_size = champion ? champion->prog_size : 0;
	new_champion->starting_pos = champion ? champion->starting_pos : 0;
	new_champion->champ_id = id + 1;
	ft_init_reg(new_champion, champion);
	new_champion->reg[1] = champion ? champion->reg[1] : -1;//id + 1;
	new_champion->pc = pc;
	new_champion->pc_void = champion ? champion->pc_void : 0;
	new_champion->carry = champion ? champion->carry : FALSE;
	new_champion->is_alive = champion ? champion->is_alive : 1;
	new_champion->exist = champion ? champion->exist : TRUE;
	new_champion->cycle = champion ? champion->cycle : 0;
	new_champion->next_cycle = champion ? champion->next_cycle : 0;
	new_champion->is_fork = champion ? 1 : 0;
	new_champion->color = champion ? champion->color : id + 42;
	ft_lststart(&env->list_champions, new_champion, sizeof(t_champions));
	if (champion)
	{
		if (IS_GRAPH)
		{
			ft_print_champion_color(champion, env->notif);
			wprintw(env->notif, " has been forked\n");
			ft_reload_windows(env, 3);
		}
		else
		{
			ft_put("A new Champion, {14}%d{0} ({14}%s{0}) has been forked at {14}map[%d]{0} !\n", new_champion->champ_id, new_champion->name, new_champion->pc);
		}
	}
}

void		ft_init_lst_champions(t_vm *env)
{
	int			i;

	i = 0;
	env->list_champions = NULL;
	while (i < env->nb_champ)
	{
		ft_add_champion(env, NULL, i, 0);
		i++;
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

		env->total_live = env->nb_champ;

		// env->detla = CYCLE_DELTA;
		// env->nbr_live = NBR_LIVE;
	}
}
