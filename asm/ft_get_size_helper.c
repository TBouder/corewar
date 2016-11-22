/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:02:31 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/22 10:39:23 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_verif_label(char *str)
{
	int		i;

	i = 0;
	if (str && str[i] == DIRECT_CHAR && str[i + 1] == LABEL_CHAR)
	{
		i = 2;
		while ((str[i] >= 97 && str[i] <= 122) || ft_isnumber(str[i]) ||
				str[i] == '-')
			i++;
		if (!str[i])
			return (1); //SUCCESS DIRECT LABEL
	}
	else if (str && str[i] == DIRECT_CHAR && str[i + 1] != LABEL_CHAR)
	{
		i = 1;
		while (ft_isnumber(str[i]) || str[i] == '-')
			i++;
		if (!str[i])
			return (1); //SUCCESS DIRECT INT
	}
	else if (str && (ft_isnumber(str[i]) || str[i] == '-'))
	{
		i = 1;
		while (ft_isnumber(str[i]))
			i++;
		if (!str[i])
			return (2); //SUCCESS INDIRECT
	}
	else if (str && str[i] == 'r')
	{
		int		reg_nb;

		reg_nb = ft_atoi(str);
		i = 1;
		if (reg_nb <= REG_NUMBER)
			return (3); //SUCCESS REG

	}

	return (0);
}

/******************************************************************************/

int		ft_opweight_1(char *arg1)
{
	if (ft_verif_label(arg1) == 1)
		return (5);
	return (-1);
}

int		ft_opweight_9_12_15(char *arg1)
{
	if (ft_verif_label(arg1) == 1)
		return (3);
	return (-1);
}

int		ft_opweight_16(char *arg1)
{
	if (ft_verif_label(arg1) == 3)
		return (2);
	return (-1);
}

int		ft_opweight_2(char *arg1, char *arg2)
{
	int		count;

	count = 0;
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

int		ft_opweight_3(char *arg1, char *arg2)
{
	int		count;

	count = 0;
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

int		ft_opweight_13(char *arg1, char *arg2)
{
	int		count;

	count = 0;
	if (ft_verif_label(arg1) == 1)
		count += 4;
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
		return (4);
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

int		ft_opweight_10_14(char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (ft_verif_label(arg1) == 3)
		count += 1;
	else if (ft_verif_label(arg1) == 1)
		count += 2;
	else if (ft_verif_label(arg1) == 2)
		count += 2;
	else
		return (-1);
	if (ft_verif_label(arg2) == 3)
		count += 1;
	else if (ft_verif_label(arg2) == 1)
		count += 4;
	else
		return (-1);
	if (ft_verif_label(arg3) == 3)
		count += 1;
	else
		return (-1);
	return (count + 1);
}

int		ft_opweight_11(char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (ft_verif_label(arg1) == 3)
		count += 1;
	else if (ft_verif_label(arg1) == 1)
		count += 2;
	else if (ft_verif_label(arg1) == 2)
		count += 2;
	if (count != 0 && ft_verif_label(arg2) == 3)
		count += 1;
	else if (count != 0 && ft_verif_label(arg2) == 1)
		count += 4;
	else if (count != 0 && ft_verif_label(arg2) == 2)
		count += 2;
	if (count != 0 && ft_verif_label(arg3) == 3)
		count += 1;
	else if (count != 0 && ft_verif_label(arg3) == 1)
		count += 4;
	else
		return (-1);
	return (count + 1);
}

/******************************************************************************/

int		ft_analyse_args_three(int code, char *arg1, char *arg2, char *arg3)
{
	if (code == 4 || code == 5)
		return (ft_opweight_4_5(arg1, arg2, arg3));
	if (code == 6 || code == 7 || code == 8)
		return (ft_opweight_6_7_8(arg1, arg2, arg3));
	if (code == 10 || code == 14)
		return (ft_opweight_10_14(arg1, arg2, arg3));
	if (code == 11)
		return (ft_opweight_11(arg1, arg2, arg3));
	return (0);
}

int		ft_analyse_args_two(int code, char *arg1, char *arg2)
{
	if (code == 2)
		return (ft_opweight_2(arg1, arg2));
	if (code == 3)
		return (ft_opweight_3(arg1, arg2));
	if (code == 13)
		return (ft_opweight_13(arg1, arg2));
	return (0);
}

int		ft_analyse_args_one(int code, char *arg1)
{
	if (code == 1)
		return (ft_opweight_1(arg1));
	if (code == 9 || code == 12 || code == 15)
		return (ft_opweight_9_12_15(arg1));
	if (code == 16)
		return (ft_opweight_16(arg1));
	return (0);
}
