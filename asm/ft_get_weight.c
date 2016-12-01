/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_weight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:38:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 12:42:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_get_line_weight(t_asm *env, int value)
{
	int		op;

	op = env->opcode;
	(value == 1 && op == 1) ? env->instruct_weight[env->line_nb] += 4 : 0;
	(value == 1 && op == 2) ? env->instruct_weight[env->line_nb] += 4 : 0;
	(value == 1 && op == 6) ? env->instruct_weight[env->line_nb] += 4 : 0;
	(value == 1 && op == 9) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 1 && op == 10) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 1 && op == 11) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 1 && op == 13) ? env->instruct_weight[env->line_nb] += 4 : 0;
	(value == 2) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 3) ? env->instruct_weight[env->line_nb] += 1 : 0;
}

static void		ft_get_args_weight(t_asm *env, int value, int pos)
{
	int		op;

	op = env->opcode;
	(value == 1 && op == 1) ? env->arg_weight[env->line_nb][pos] += 4 : 0;
	(value == 1 && op == 2) ? env->arg_weight[env->line_nb][pos] += 4 : 0;
	(value == 1 && op == 6) ? env->arg_weight[env->line_nb][pos] += 4 : 0;
	(value == 1 && op == 9) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	(value == 1 && op == 10) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	(value == 1 && op == 11) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	(value == 1 && op == 13) ? env->arg_weight[env->line_nb][pos] += 4 : 0;
	(value == 2) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	(value == 3) ? env->arg_weight[env->line_nb][pos] += 1 : 0;
	if (op != 1 && op != 9 && op != 12 && op != 15)
	{
		(value == 1) ? ft_strcat(env->opcode_next[env->line_nb], "10") : 0;
		(value == 2) ? ft_strcat(env->opcode_next[env->line_nb], "11") : 0;
		(value == 3) ? ft_strcat(env->opcode_next[env->line_nb], "01") : 0;
	}
}

int				ft_get_weight(t_asm *env, int value, int ret, int pos)
{
	ft_get_line_weight(env, value);
	ft_get_args_weight(env, value, pos);
	return (ret);
}
