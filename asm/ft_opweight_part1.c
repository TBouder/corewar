/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opweight_part1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:55:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/22 16:10:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_opweight_1(char *arg1, char *arg2, char *arg3)
{
	if (arg2 || arg3)
		return (-2);
	if (ft_verif_label(arg1) == 1)
		return (5);
	return (-1);
}

int		ft_opweight_2(char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (arg3)
		return (-2);
	if (ft_verif_label(arg1) == 1)
		count += 4;
	else if (ft_verif_label(arg1) == 2)
		count += 2;
	else
		return (-1);
	if (ft_verif_label(arg2) == 3)
		count += 1;
	else
		return (-1);
	return (count + 2);
}

int		ft_opweight_3(char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (arg3)
		return (-2);
	if (ft_verif_label(arg1) == 3)
		count += 1;
	else
		return (-1);
	if (ft_verif_label(arg2) == 3)
		count += 1;
	else if (ft_verif_label(arg2) == 2)
		count += 2;
	else
		return (-1);
	return (count + 2);
}

int		ft_opweight_4_5(char *arg1, char *arg2, char *arg3)
{
	if (ft_verif_label(arg1) == 3 &&
		ft_verif_label(arg2) == 3 &&
		ft_verif_label(arg3) == 3)
		return (4 + 1);
	return (-1);
}

int		ft_opweight_6_7_8(char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (ft_verif_label(arg1) == 3)
		count += 1;
	else if (ft_verif_label(arg1) == 1)
		count += 4;
	else if (ft_verif_label(arg1) == 2)
		count += 2;
	else
		return (-1);
	if (ft_verif_label(arg2) == 3)
		count += 1;
	else if (ft_verif_label(arg2) == 1)
		count += 4;
	else if (ft_verif_label(arg2) == 2)
		count += 2;
	else
		return (-1);
	if (ft_verif_label(arg3) == 3)
		count += 1;
	else
		return (-1);
	return (count + 2);
}
