/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/15 15:24:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"
#define IS_GRAPH env->options->flags['g']

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	else if (IS_DIR(nbr))
		return (2);
	else if (IS_IND(nbr))
		return (2);
	return (0);
}

void	ft_corewar_zjmp(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (champ->carry == 1 && IS_DIR(nbr[0]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		// ft_printf("{10}CARRY %d{0}\n", champ->carry);
		// ft_printf("env->map[%d]\n", (champ->pc + ft_byte_to_str(&env->map[pc], ft_set_buffer(nbr[0]))) % M);
		champ->pc = (champ->pc + env->arg1) % M; // On dois faire % IDX_MOD ?
	}
	else
		champ->pc += ft_count_to_next(nbr, ZJMP);
	// ft_printf("{10}%d{0}\n", champ->pc);
	IS_GRAPH ? ft_reload_windows(env, 1) : 0;
}
