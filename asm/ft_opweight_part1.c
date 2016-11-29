/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opweight_part1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:55:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/29 19:09:40 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_get_line_weight(t_asm *env, int value, int ret, int pos)
{
	(value == 1 && env->opcode == 1) ? env->arg_weight[env->line_nb][pos] += 4 : 0;
	(value == 1 && env->opcode == 2) ? env->arg_weight[env->line_nb][pos] += 4 : 0;
	// 6 == VALABLE POUR OPCODE 6/7/8
	(value == 1 && env->opcode == 6) ? env->arg_weight[env->line_nb][pos] += 4 : 0;
	// 9 == VALABLE POUR OPCODE 9/12/15
	(value == 1 && env->opcode == 9) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	// 9 == VALABLE POUR OPCODE 10/14
	(value == 1 && env->opcode == 10) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	(value == 1 && env->opcode == 11) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	(value == 1 && env->opcode == 13) ? env->arg_weight[env->line_nb][pos] += 4 : 0;

	(value == 2) ? env->arg_weight[env->line_nb][pos] += 2 : 0;
	(value == 3) ? env->arg_weight[env->line_nb][pos] += 1 : 0;

	if (env->opcode != 1 && env->opcode != 9 && env->opcode != 12 && env->opcode != 15 && env->opcode != 16) // TODO vérifier pour 16
	{
		(value == 1) ? ft_strcat(env->opcode_next[env->line_nb], "10") : 0;
		(value == 2) ? ft_strcat(env->opcode_next[env->line_nb], "11") : 0;
		(value == 3) ? ft_strcat(env->opcode_next[env->line_nb], "01") : 0;
	}
	return (ret);
}

int		ft_opweight_1(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	env->opcode = 1;
	if (arg2 || arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		return (ft_get_line_weight(env, 1, 5, 1));
	return (-1);
}

int		ft_opweight_2(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	env->opcode = 2;
	if (arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		count += ft_get_line_weight(env, 1, 4, 1);
	else if (ft_verif_label(env, arg1) == 2)
		count += ft_get_line_weight(env, 2, 2, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 3, 1, 2);
	else
		return (-1);
	return (count + 2);
}

int		ft_opweight_3(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	env->opcode = 3;
	if (arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 3, 1, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 3, 1, 2);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_line_weight(env, 2, 2, 2);
	else
		return (-1);
	return (count + 2);
}

int		ft_opweight_4_5(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	env->opcode = 4;
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 3, 2, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 3, 2, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_line_weight(env, 3, 2, 3);
	else
		return (-1);
	return (count - 1);
}

int		ft_opweight_6_7_8(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	env->opcode = 6;
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 3, 1, 1);
	else if (ft_verif_label(env, arg1) == 1)
		count += ft_get_line_weight(env, 1, 4, 1);
	else if (ft_verif_label(env, arg1) == 2)
		count += ft_get_line_weight(env, 2, 2, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 3, 1, 2);
	else if (ft_verif_label(env, arg2) == 1)
		count += ft_get_line_weight(env, 1, 4, 2);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_line_weight(env, 2, 2, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_line_weight(env, 3, 1, 3);
	else
		return (-1);
	return (count + 2);
}
