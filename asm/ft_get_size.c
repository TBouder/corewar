/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:19:07 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/01 13:45:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_get_opcode(char *opname)
{
	int		opcode;

	opcode = 0;
	opcode == 0 && EQU(opname, "live") ? opcode = 1 : 0;
	opcode == 0 && EQU(opname, "ld") ? opcode = 2 : 0;
	opcode == 0 && EQU(opname, "st") ? opcode = 3 : 0;
	opcode == 0 && EQU(opname, "add") ? opcode = 4 : 0;
	opcode == 0 && EQU(opname, "sub") ? opcode = 5 : 0;
	opcode == 0 && EQU(opname, "and") ? opcode = 6 : 0;
	opcode == 0 && EQU(opname, "or") ? opcode = 7 : 0;
	opcode == 0 && EQU(opname, "xor") ? opcode = 8 : 0;
	opcode == 0 && EQU(opname, "zjmp") ? opcode = 9 : 0;
	opcode == 0 && EQU(opname, "ldi") ? opcode = 10 : 0;
	opcode == 0 && EQU(opname, "sti") ? opcode = 11 : 0;
	opcode == 0 && EQU(opname, "fork") ? opcode = 12 : 0;
	opcode == 0 && EQU(opname, "lld") ? opcode = 13 : 0;
	opcode == 0 && EQU(opname, "lldi") ? opcode = 14 : 0;
	opcode == 0 && EQU(opname, "lfork") ? opcode = 15 : 0;
	opcode == 0 && EQU(opname, "aff") ? opcode = 16 : 0;
	return (opcode);
}

void			ft_get_opweight_helper(t_asm *env, int opcode)
{
	opcode == 1 ? env->instruct_weight[env->line_nb] += 1 : 0;
	opcode == 2 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 3 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 4 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 5 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 6 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 7 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 8 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 9 ? env->instruct_weight[env->line_nb] += 1 : 0;
	opcode == 10 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 11 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 12 ? env->instruct_weight[env->line_nb] += 1 : 0;
	opcode == 13 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 14 ? env->instruct_weight[env->line_nb] += 2 : 0;
	opcode == 15 ? env->instruct_weight[env->line_nb] += 1 : 0;
	opcode == 16 ? env->instruct_weight[env->line_nb] += 2 : 0;
}

void			ft_get_opweight(t_asm *env, int opcode)
{
	ft_get_opweight_helper(env, opcode);
	opcode == 1 ? env->arg_weight[env->line_nb][0] += 1 : 0;
	opcode == 2 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 3 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 4 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 5 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 6 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 7 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 8 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 9 ? env->arg_weight[env->line_nb][0] += 1 : 0;
	opcode == 10 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 11 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 12 ? env->arg_weight[env->line_nb][0] += 1 : 0;
	opcode == 13 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 14 ? env->arg_weight[env->line_nb][0] += 2 : 0;
	opcode == 15 ? env->arg_weight[env->line_nb][0] += 1 : 0;
	opcode == 16 ? env->arg_weight[env->line_nb][0] += 2 : 0;
}

char			**ft_get_args(t_asm *env, int i)
{
	char		**args;
	char		**elems;
	char		**elem_0;
	char		*elem_1;
	char		*elem_2;

 	elems = ft_split_args(env->file_content[i], ',', 3);
	elem_0 = ft_split_args(elems[0], ' ', 2);
	elem_1 = ft_strtrim(elems[1]);
	elem_2 = ft_strtrim(elems[2]);

	args = ft_dbstrnew(5);
	args[0] = ft_strinit(elem_0[0]);
	args[1] = ft_strinit(elem_0[1]);
	args[2] = ft_strinit(elem_1);
	args[3] = ft_strinit(elem_2);
	ft_dbstrdel(elems);
	ft_dbstrdel(elem_0);
	ft_strdel(&elem_1);
	ft_strdel(&elem_2);
	return (args);
}

void			ft_get_size(t_asm *env, int i)
{

	int			(*tab[17])(t_asm *env, char *, char *, char *);
	int			opcode;
	int			arg_value;

	arg_value = 0;
	env->args[i] = ft_get_args(env, i);

	opcode = ft_get_opcode(env->args[i][0]);
	ft_get_opweight(env, opcode);
	ft_init_function_tab(tab);
	if (opcode != 0)
	{
		arg_value = tab[(int)opcode](env, env->args[i][1], env->args[i][2], env->args[i][3]);
		if (ft_strlen(env->opcode_next[i]) == 2)
			ft_strcat(env->opcode_next[i], "000000");
		if (ft_strlen(env->opcode_next[i]) == 4)
			ft_strcat(env->opcode_next[i], "0000");
		if (ft_strlen(env->opcode_next[i]) == 6)
			ft_strcat(env->opcode_next[i], "00");
		//ICI WESH MAGGLE
	}
	if (arg_value < 0)
	{
		if (arg_value == -1)
			ft_printf("{9}ERROR{0} : One argument of this line is falty [%s]", env->file_content[i]);
		if (arg_value == -2)
			ft_printf("{9}ERROR{0} : Too many arguments for [%s]", env->args[i][1]);
		ft_error_asm(env, "", 1);
	}
	env->instruct_size += arg_value;
	// ft_dbstrdel(env->args[i]);
	// env->args = NULL;
}
