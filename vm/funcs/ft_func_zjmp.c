/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/03 10:49:21 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

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
	// if (champ->carry == 0)
	// 	ft_printf("{10}LE CARRY EST PAS A UN{0}\n");

	if (champ->carry == 1 && IS_DIR(nbr[0]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);

		
		// if (env->arg1 > MAX)
		// {
		// 	// ft_print_memory(env->map, 4096);
		// 	// champ->pc = (champ->pc + ((env->arg1 % I) - I)) % M;
		// 	ft_printf("{9}%d{0}\n", (champ->pc + ((env->arg1 % I) - I)) % M);


		// 	// ft_printf("{9}%d{0}\n", (champ->pc - I + (55000 - MAX)) % M);
		// 	// ft_printf("{9}%d{0}\n", (champ->pc + ((env->arg1 - MAX) % I)) % M);
		// 	// ft_printf("{9}%d{0}\n", (champ->pc + (env->arg1 - MAX) % I) % M);
		// 	// ft_printf("{9}%d{0}\n", ((champ->pc + env->arg1) % I) % M);
		// 	// ft_printf("{9}%d{0}\n", (champ->pc + env->arg1 % I) % M);
		// 	champ->pc = (champ->pc - I + (env->arg1 - MAX)) % M;

		// 	ft_printf("13 %% 2 = {10}%d{0}\n", 13 % 2);
		// 	ft_printf("-13 %% 2 = {10}%d{0}\n", -13 % 2);
		// 	ft_printf("-117 %% 17 = {10}%d{0}\n", -117 % 17);
		// 	ft_printf("13 %% -2 = {10}%d{0}\n", 13 % -2);
		// 	ft_printf("-13 %% -2 = {10}%d{0}\n", -13 % -2);

		// 	//if (champ->pc < 0)
		// 	// 	champ->pc = M + champ->pc;
		// }
		// else
		// {
		// 	// ft_print_memory(env->map, (champ->pc + (env->arg1 % I)) % M + 4);
		// 	champ->pc = (champ->pc + (env->arg1 % I)) % M;
		// }

		if (env->arg1 > 32768)
		{
			// ft_put("{9}%d{0}\n", (champ->pc - I + (env->arg1 - 32768)) % M);
			// ft_put("{9}%d{0}\n", (champ->pc - I + (55000 - 32768)) % M);

			ft_put("{9}%d{0}\n", ft_mod(champ->pc + ((env->arg1 % I) - I), M));
			ft_put("{9}%d{0}\n", ft_mod(champ->pc + ((55000 % I) - I), M));
			champ->pc = ft_mod(champ->pc + ((env->arg1 % I) - I), M);
		}
		else
			champ->pc = ft_mod(champ->pc + (env->arg1 % I), M);
	}
	else
		champ->pc += ft_count_to_next(nbr, ZJMP);
}
