/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 20:38:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_init_champions(t_vm *env)
{
	int		i;
	int		reg_nb;

	i = 0;
	while (i < env->nb_champ)
	{
		env->champions[i].name = NULL;
		env->champions[i].comment = NULL;
		env->champions[i].magic = 0;
		env->champions[i].prog_size = 0;
		env->champions[i].content = NULL;
		env->champions[i].starting_pos = 0;
		env->champions[i].champ_id = i + 1;
		/*REG_NUMBER registres qui font chacun une taille de REG_SIZE octets*/
		reg_nb = 0;
		while (reg_nb <= REG_NUMBER)
		{
			// env->champions[i].reg[reg_nb] = (char)malloc(REG_SIZE);
			env->champions[i].reg[reg_nb] = 0;
			reg_nb++;
		}
		env->champions[i].reg[1] = i + 1;
		/*Un PC est un registre spécial, qui contient juste l’adresse, dans la mémoire de la machine virtuelle, de la prochaine instruction à décoder et exécuter*/
		env->champions[i].pc = 0;
		env->champions[i].pc_void = 0;
		env->champions[i].carry = FALSE;
		env->champions[i].is_alive = 1;
		env->champions[i].exist = TRUE;
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
		env->champions = (t_champions *)malloc(sizeof(t_champions) * part);
		env->total_size = 0;
		env->map = ft_strnew(MEM_SIZE);
		ft_init_champions(env);
		env->winner = NULL;

		env->cycle_to_die = CYCLE_TO_DIE;
		env->cpt_to_die = 0;
		env->cycle_check = 0;
		env->cycle = 0;
		// env->detla = CYCLE_DELTA;
		// env->nbr_live = NBR_LIVE;
	}
}
