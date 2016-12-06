/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/06 15:20:25 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_test_helper(t_asm *env, int line, int begin)
{
	char		*hex;
	char		*part;

	hex = ft_strnew_hex(1);
	part = ft_strsub(env->opcode_next[line], begin, 2);
	ft_printf("{9}%s{0}\n", env->opcode_next[line]);

	if (!part)
		return ;

	hex[0] += ft_atoi_base(part, 2);

	if (hex[0] == 1)
		ft_printf("{10}1 er arg est un registre{0} : %x\n", hex[0]);
	else if (hex[0] == 2)
		ft_printf("{10}1 er arg est une valeur directe{0} : %x\n", hex[0]);
	else if (hex[0] == 3)
		ft_printf("{10}1 er arg est une valeur indirecte{0} : %x\n", hex[0]);

	ft_strdel(&hex);
	ft_strdel(&part);
}

void			ft_test(t_asm *env, int line)
{
	ft_test_helper(env, line, 0);
	ft_test_helper(env, line, 2);
	ft_test_helper(env, line, 4);
	ft_test_helper(env, line, 6);


	if (ft_atoi_base(env->opcode_next[line], 2) != 0)
		ft_printf("\n");
	else
		ft_printf("{8}Instru vide{0}\n");

}

void		ft_corewar_live(void)
{
	;
}
void		ft_corewar_ld(void)
{
	;
}
void		ft_corewar_st(void)
{
	;
}
void		ft_corewar_add(void)
{
	;
}
void		ft_corewar_sub(void)
{
	;
}
void		ft_corewar_and(void)
{
	;
}
void		ft_corewar_or(void)
{
	;
}
void		ft_corewar_xor(void)
{
	;
}
void		ft_corewar_zjmp(void)
{
	;
}
void		ft_corewar_ldi(void)
{
	;
}
void		ft_corewar_sti(void)
{
	;
}
void		ft_corewar_fork(void)
{
	;
}
void		ft_corewar_lld(void)
{
	;
}
void		ft_corewar_lldi(void)
{
	;
}
void		ft_corewar_lfork(void)
{
	;
}
void		ft_corewar_aff(void)
{
	;
}
