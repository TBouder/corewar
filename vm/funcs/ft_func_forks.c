/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/16 18:27:32 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

// fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Crée un nouveau processus, qui hérite des di érents états de son père, à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).

static int	ft_set_buffer(int nbr)
{
	if (IS_DIR(nbr))
		return (2);
	return (0);
}

void	ft_corewar_fork(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;

	if (IS_DIR(nbr[0]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);

		// ft_put("arg1 = env->map[{13}%d{0}] -> env->map[{13}0x%x{0}]\n", pc, pc);
		// ft_put("arg1 = {13}%d{0} -> {13}0x%x{0}\n", env->map[pc], env->map[pc]);

		// ft_put("NEXT POS {13}%d{0} + {13}%d{0}\n", champ->pc - 1, env->arg1);

		env->arg1 = (champ->pc + (env->arg1 % I)) % M;

		// ft_put("CURRENT POS : {13}%d{0} || NEXT POS {13}%d{0}\n", champ->pc - 1, env->arg1);
		ft_add_champion(env, champ, champ->champ_id - 1, env->arg1);
		// ft_printf("env->map[%d]\n", env->arg1);
		// ft_print_memory(env->map, 80);
	}
	// ft_DEBUG_display_champions(env);

}

void	ft_corewar_lfork(t_vm *env, t_champions *champ, int *nbr)
{
	if (0)
	{
		env = 0;
		champ = 0;
		nbr = 0;
	}
}
