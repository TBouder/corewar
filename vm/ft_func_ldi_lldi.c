/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ldi_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/12 14:44:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define LDI_IND_1		(pc + (sum_idx % IDX_MOD)) //PC sur l'instruction suivante
#define LDI_IND_2		(pc - 1 + (sum_idx % IDX_MOD)) //PC sur le dernier argument
#define LDI_IND_3		((sum_idx % IDX_MOD)) //Position sans prendre en compte le PC
#define LDI_IND_4		(champ->pc + (sum_idx % IDX_MOD)) //Depart du premier arg
#define LDI_IND_5		((champ->pc - 1 + (sum_idx % IDX_MOD)) % MEM_SIZE) //Depart de l'instruction courante

#define LDI_ARG_1		(pc + (arg1 % IDX_MOD)) //PC sur l'instruction suivante
#define LDI_ARG_2		(pc - 1 + (arg1 % IDX_MOD)) //PC sur le dernier argument
#define LDI_ARG_3		((arg1 % IDX_MOD)) //Position sans prendre en compte le PC
#define LDI_ARG_4		(champ->pc + (arg1 % IDX_MOD)) //Depart du premier arg
#define LDI_ARG_5		((champ->pc - 1 + (arg1 % IDX_MOD)) % MEM_SIZE) //Depart de l'instruction courante

#define LLDI_IND_1		(pc + sum_idx) //PC sur l'instruction suivante
#define LLDI_IND_2		(pc - 1 + sum_idx) //PC sur le dernier argument
#define LLDI_IND_3		(sum_idx) //Position sans prendre en compte le PC
#define LLDI_IND_4		(champ->pc + sum_idx) //Depart du premier arg
#define LLDI_IND_5		((champ->pc - 1 + sum_idx) % MEM_SIZE) //Depart de l'instruction courante

#define LLDI_ARG_1		(pc + arg1) //PC sur l'instruction suivante
#define LLDI_ARG_2		(pc - 1 + arg1) //PC sur le dernier argument
#define LLDI_ARG_3		(arg1) //Position sans prendre en compte le PC
#define LLDI_ARG_4		(champ->pc + arg1) //Depart du premier arg
#define LLDI_ARG_5		((champ->pc - 1 + arg1) % MEM_SIZE) //Depart de l'instruction courante

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (2);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

void		ft_corewar_ldi(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----LDI----{0}\n");
	int		pc;
	int		buffer;
	int		arg1;
	int		arg2;
	int		arg3;
	int		sum_idx;

	// ft_put(champ->pc);
	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		buffer = ft_set_buffer(nbr[0]);
		arg1 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;
		buffer = ft_set_buffer(nbr[1]);
		arg2 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;
		arg3 = ft_byte_to_str(&env->map[pc], 1);
		pc++;

		ft_put("{9}%d\n{0}", (arg1 % IDX_MOD)); //POSITION DE L'ADRESSE

		if (IS_IND(nbr[0]))
			arg1 = env->map[LDI_ARG_5];
		if (IS_REG(nbr[0]))
			arg1 = champ->reg[arg1];
		if (IS_REG(nbr[1]))
			arg2 = champ->reg[arg2];

		sum_idx = arg1 + arg2; //SERA UNE ADRESSE DANS LAQUELLE ON VA LIRE UNE VALEUR DE LA TAILLE D'UN REGISTRE QU'ON MET DANS REG[arg3]

		ft_put("\033[104m%d + %d = %d{0} || ", arg1, arg2, sum_idx);
		ft_put("\033[104m0x%x + 0x%x = 0x%x{0}\n", arg1, arg2, sum_idx);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d + %d + %d]{0} || ", arg3, champ->pc - 1, arg1, arg2);
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x + 0x%x + 0x%x]{0}\n", arg3, champ->pc - 1, arg1, arg2);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d + %d]{0} || ", arg3, champ->pc - 1, sum_idx);
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x + 0x%x]{0}\n", arg3, champ->pc - 1, sum_idx);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d]{0} || ", arg3, champ->pc - 1 + sum_idx);
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x]{0}\n", arg3, champ->pc - 1 + sum_idx);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d]{0} || ", arg3, (champ->pc - 1 + sum_idx) % IDX_MOD);
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x]{0}\n", arg3, (champ->pc - 1 + sum_idx) % IDX_MOD);

		ft_put("\033[104mchamp->reg[r%d] = %d{0} || ", arg3, env->map[((champ->pc - 1 + sum_idx) % IDX_MOD) % MEM_SIZE]);
		ft_put("\033[104mchamp->reg[r%d] = %x{0}\n", arg3, env->map[(champ->pc - 1 + sum_idx) % MEM_SIZE]);

		ft_print_memory(env->map, 80);

		champ->reg[arg3] = ft_byte_to_str(&env->map[LDI_IND_5], 1);
		ft_put("\033[104mr%d = 0x%x{0}\n", arg3, champ->reg[arg3]);
	}
}

void		ft_corewar_lldi(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----LLDI----{0}\n");
	int		pc;
	int		buffer;
	int		arg1;
	int		arg2;
	int		arg3;
	int		sum_idx;

	// ft_put(champ->pc);
	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		buffer = ft_set_buffer(nbr[0]);
		arg1 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;
		buffer = ft_set_buffer(nbr[1]);
		arg2 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;
		arg3 = ft_byte_to_str(&env->map[pc], 1);
		pc++;

		if (IS_IND(nbr[0]))
			arg1 = env->map[LLDI_ARG_5 % MEM_SIZE];
		if (IS_REG(nbr[0]))
			arg1 = champ->reg[arg1];
		if (IS_REG(nbr[1]))
			arg2 = champ->reg[arg2];

		sum_idx = arg1 + arg2;

		ft_put("{9}%d{0}\n", env->map[champ->pc]);

		ft_put("\033[104m%d + %d = %d{0} || ", arg1, arg2, sum_idx);
		ft_put("\033[104m0x%x + 0x%x = 0x%x{0}\n", arg1, arg2, sum_idx);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d + %d + %d]{0} || ", arg3, champ->pc - 1, arg1, arg2);
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x + 0x%x + 0x%x]{0}\n", arg3, champ->pc - 1, arg1, arg2);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d + %d]{0} || ", arg3, champ->pc - 1, sum_idx);
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x + 0x%x]{0}\n", arg3, champ->pc - 1, sum_idx);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d]{0} || ", arg3, champ->pc - 1 + sum_idx);
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x]{0}\n", arg3, champ->pc - 1 + sum_idx);

		ft_put("\033[104mchamp->reg[r%d] = env->map[%d]{0} || ", arg3, (champ->pc - 1 + sum_idx));
		ft_put("\033[104mchamp->reg[r%d] = env->map[0x%x]{0}\n", arg3, (champ->pc - 1 + sum_idx));

		ft_put("\033[104mchamp->reg[r%d] = %d{0} || ", arg3, env->map[((champ->pc - 1 + sum_idx)) % MEM_SIZE]);
		ft_put("\033[104mchamp->reg[r%d] = %x{0}\n", arg3, env->map[(champ->pc - 1 + sum_idx) % MEM_SIZE]);

		ft_print_memory(env->map, 80);

		champ->reg[arg3] = ft_byte_to_str(&env->map[LLDI_IND_5], 1);
		//CARRY
		ft_put("\033[104mr%d = 0x%x{0}\n", arg3, champ->reg[arg3]);
	}
}
