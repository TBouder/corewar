/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 23:27:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/13 17:48:38 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_print_hex_mem(char *add, size_t size)
{
	size_t		i;
	char		*hex;

	hex = ft_strinit("0123456789abcdef");
	i = 0;
	while (i < 64)
	{
		if (i < size)
		{
			ft_putchar(hex[(int)((unsigned char)add[i]) / 16]);
			ft_putchar(hex[(int)((unsigned char)add[i]) % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	ft_strdel(&hex);
}

void			ft_dump(const void *addr, size_t size)
{
	int		offset;

	offset = 0;
	while (size > 16)
	{
		ft_print_hex_mem((char *)addr + offset, 64);
		ft_put("\n");
		offset += 64;
		size -= 64;
	}
	ft_print_hex_mem((char *)addr + offset, size);
	ft_put("\n");
}

/*
** The ft_ret_cycle() function takes an opcode as paramater and according to it,
** returns the number of cycle to perform before calling the next instruction
*/
static int	ft_ret_cycle(int op)
{
	if (op == AFF)
		return (2);
	else if (op == LD || op == ST)
		return (5);
	else if (op == AND || op == OR || op == XOR)
		return (6);
	else if (op == LIVE || op == ADD || op == SUB || op == LLD)
		return (10);
	else if (op == ZJMP)
		return (20);
	else if (op == LDI || op == STI)
		return (25);
	else if (op == LLDI)
		return (50);
	else if (op == FORK)
		return (800);
	else if (op == LFORK)
		return (1000);
	return (0);
}

void	ft_print_instruct(int op)
{
	op == LIVE ? ft_put("{10}LIVE{0}") : 0;
	op == LD ? ft_put("{10}LD{0}") : 0;
	op == ST ? ft_put("{10}ST{0}") : 0;
	op == ADD ? ft_put("{10}ADD{0}") : 0;
	op == SUB ? ft_put("{10}SUB{0}") : 0;
	op == AND ? ft_put("{10}AND{0}") : 0;
	op == OR ? ft_put("{10}OR{0}") : 0;
	op == XOR ? ft_put("{10}XOR{0}") : 0;
	op == ZJMP ? ft_put("{10}ZJMP{0}") : 0;
	op == LDI ? ft_put("{10}LDI{0}") : 0;
	op == STI ? ft_put("{10}STI{0}") : 0;
	op == FORK ? ft_put("{10}FORK{0}") : 0;
	op == LLD ? ft_put("{10}LLD{0}") : 0;
	op == LLDI ? ft_put("{10}LLDI{0}") : 0;
	op == LFORK ? ft_put("{10}LFORK{0}") : 0;
	op == AFF ? ft_put("{10}AFF{0}") : 0;
}

int			ft_get_args(t_vm *env, t_champions *champ, int op)
{
	int		*nbr;
	int		count;

	if (op != LIVE && op != FORK)
		nbr = ft_get_size(env, champ); //Va, entre autre, faire +1 au pc si needed
	else
	{
		nbr = ft_nbrnew(3);
		nbr[0] = 10;
	}
	count = ft_count_to_next(nbr, op);

	// ft_put((char)'[');
	// ft_print_instruct(op);
	// ft_put("]\n");
	// ft_put(" [%d] [%d] [%d]\n", nbr[0], nbr[1], nbr[2]);

	op == LIVE ? ft_corewar_live(env, champ, nbr) : 0;
	op == LD ? ft_corewar_ld(env, champ, nbr) : 0;
	op == ST ? ft_corewar_st(env, champ, nbr) : 0;
	op == ADD ? ft_corewar_add(env, champ, nbr) : 0;
	op == SUB ? ft_corewar_sub(env, champ, nbr) : 0;
	op == AND ? ft_corewar_and(env, champ, nbr) : 0;
	op == OR ? ft_corewar_or(env, champ, nbr) : 0;
	op == XOR ? ft_corewar_xor(env, champ, nbr) : 0;
	op == ZJMP ? ft_corewar_zjmp(env, champ, nbr) : 0;
	op == LDI ? ft_corewar_ldi(env, champ, nbr) : 0;
	op == STI ? ft_corewar_sti(env, champ, nbr) : 0;
	op == FORK ? ft_corewar_fork(env, champ, nbr) : 0;
	op == LLD ? ft_corewar_lld(env, champ, nbr) : 0;
	op == LLDI ? ft_corewar_lldi(env, champ, nbr) : 0;
	op == LFORK ? ft_corewar_fork(env, champ, nbr) : 0;
	op == AFF ? ft_corewar_aff(env, champ, nbr) : 0;
	champ->pc += count;

	return (ft_ret_cycle(op));
}
