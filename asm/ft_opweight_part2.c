/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opweight_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:55:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/25 16:52:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_opweight_9_12_15(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	if (arg2 || arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		return (ft_get_line_weight(env, 9, 1, 3));
	return (-1);
}

int		ft_opweight_10_14(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 10, 3, 1);
	else if (ft_verif_label(env, arg1) == 1)
		count += ft_get_line_weight(env, 10, 1, 2);
	else if (ft_verif_label(env, arg1) == 2)
		count += ft_get_line_weight(env, 10, 2, 2);
	else
		return (-1);

	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 10, 3, 3);
	else if (ft_verif_label(env, arg2) == 1)
		count += ft_get_line_weight(env, 10, 1, 4);
	else
		return (-1);

	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_line_weight(env, 10, 3, 1);
	else
		return (-1);
	return (count);
}

int		ft_opweight_11(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (ft_verif_label(env, arg1) == 3)
		count += ft_get_line_weight(env, 11, 3, 1);
	else
		return (-1);

	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 11, 3, 3);
	else if (ft_verif_label(env, arg2) == 1)
		count += ft_get_line_weight(env, 11, 1, 4);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_line_weight(env, 11, 2, 2);
	else
		return (-1);

	if (ft_verif_label(env, arg3) == 3)
		count += ft_get_line_weight(env, 11, 3, 1);
	else if (ft_verif_label(env, arg3) == 1)
		count += ft_get_line_weight(env, 11, 1, 2);
	else
		return (-1);
	return (count);
}

int		ft_opweight_13(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 1)
		count += ft_get_line_weight(env, 13, 1, 4);
	else
		return (-1);
	if (ft_verif_label(env, arg2) == 3)
		count += ft_get_line_weight(env, 13, 3, 1);
	else if (ft_verif_label(env, arg2) == 2)
		count += ft_get_line_weight(env, 13, 2, 2);
	else
		return (-1);
	return (count + 2);
}

int		ft_opweight_16(t_asm *env, char *arg1, char *arg2, char *arg3)
{
	if (arg2 || arg3)
		return (-2);
	if (ft_verif_label(env, arg1) == 3)
		return (ft_get_line_weight(env, 16, 3, 2));
	return (-1);
}
