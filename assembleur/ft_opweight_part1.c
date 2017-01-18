/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opweight_part1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:55:28 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/16 10:34:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_opweight_1(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	env->opcode = 1;
	if (arg2 || arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		return (ft_get_weight(env, 1, 5, 1));
	return (-1);
}

int		ft_opweight_2(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	env->opcode = 2;
	if (arg3 || (arg1 && ft_strchr(arg1, ' '))
		|| (arg2 && ft_strchr(arg2, ' ')))
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		count += ft_get_weight(env, 1, 4, 1);
	else if (ft_verif_label(env, arg1) == 2)
		count += ft_get_weight(env, 2, 2, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_weight(env, 3, 1, 2);
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
		count += ft_get_weight(env, 3, 1, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_weight(env, 3, 1, 2);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_weight(env, 2, 2, 2);
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
		count += ft_get_weight(env, 3, 2, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_weight(env, 3, 2, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_weight(env, 3, 2, 3);
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
		count += ft_get_weight(env, 3, 1, 1);
	else if (ft_verif_label(env, arg1) == 1)
		count += ft_get_weight(env, 1, 4, 1);
	else if (ft_verif_label(env, arg1) == 2)
		count += ft_get_weight(env, 2, 2, 1);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_weight(env, 3, 1, 2);
	else if (ft_verif_label(env, arg2) == 1)
		count += ft_get_weight(env, 1, 4, 2);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_weight(env, 2, 2, 2);
	else
		return (-1);
	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_weight(env, 3, 1, 3);
	else
		return (-1);
	return (count + 2);
}
