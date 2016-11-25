/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opweight_part1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:55:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/25 22:37:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_get_line_weight(t_asm *env, int opcode, int value, int ret)
{
	(value == 1 && opcode == 1) ? env->instruct_weight[env->line_nb] += 4 : 0;
	(value == 1 && opcode == 2) ? env->instruct_weight[env->line_nb] += 4 : 0;

	// 6 == VALABLE POUR OPCODE 6/7/8
	(value == 1 && opcode == 6) ? env->instruct_weight[env->line_nb] += 4 : 0;
	(value == 1 && opcode == 7) ? env->instruct_weight[env->line_nb] += 4 : 0;
	(value == 1 && opcode == 8) ? env->instruct_weight[env->line_nb] += 4 : 0;

	// 9 == VALABLE POUR OPCODE 9/12/15
	(value == 1 && opcode == 9) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 1 && opcode == 12) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 1 && opcode == 15) ? env->instruct_weight[env->line_nb] += 2 : 0;

	// 9 == VALABLE POUR OPCODE 10/14
	(value == 1 && opcode == 10) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 1 && opcode == 14) ? env->instruct_weight[env->line_nb] += 2 : 0;

	(value == 1 && opcode == 11) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 1 && opcode == 13) ? env->instruct_weight[env->line_nb] += 4 : 0;

	(value == 2) ? env->instruct_weight[env->line_nb] += 2 : 0;
	(value == 3) ? env->instruct_weight[env->line_nb] += 1 : 0;
	return (ret);
}

int		ft_opweight_1(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	if (arg2 || arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		return (ft_get_line_weight(env, 1, 1, 5));
	return (-1);
}

int		ft_opweight_2(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		count += ft_get_line_weight(env, 2, 1, 4);
	else if (ft_verif_label(env, arg1) == 2)
		count += ft_get_line_weight(env, 2, 2, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 2, 3, 1);
	else
		return (-1);
	return (count + 2);
}

int		ft_opweight_3(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 3, 3, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 3, 3, 1);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_line_weight(env, 3, 2, 2);
	else
		return (-1);
	return (count + 2);
}

int		ft_opweight_4_5(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 4, 3, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 4, 3, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_line_weight(env, 4, 3, 2);
	else
		return (-1);
	return (count - 1);
}

int		ft_opweight_6_7_8(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 6, 3, 1);
	else if (ft_verif_label(env, arg1) == 1)
		count += ft_get_line_weight(env, 6, 1, 4);
	else if (ft_verif_label(env, arg1) == 2)
		count += ft_get_line_weight(env, 6, 2, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 6, 3, 1);
	else if (ft_verif_label(env, arg2) == 1)
		count += ft_get_line_weight(env, 6, 1, 4);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_line_weight(env, 6, 2, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_line_weight(env, 6, 3, 1);
	else
		return (-1);
	return (count + 2);
}
