/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:02:31 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/19 15:18:44 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_isind(char c)
{
	if (ft_isnumber(c) || c == '-')
		return (1);
	return (0);
}

//IF RET 0 -> PRINT ERROR
int				ft_analyse_args_one(int code, char *arg1)
{
	if (code == 1 || code == 9 || code == 12 || code == 15)
	{
		if (code == 1 && arg1[0] == DIRECT_CHAR)
			return (5);
		else if (arg1[0] == DIRECT_CHAR)
			return (3);
		return (0);
	}
	else if (code == 16 && arg1[0] == 'r')
		return (2);
	return (0);
}

//IF RET 0 -> PRINT ERROR
static int		ft_analyse_args_two_helper(char *arg1, char *arg2)
{
	int		count;

	count = 0;
	arg1[0] == DIRECT_CHAR ? count += 4 : 0;
	if (arg2[0] == 'r')
		count += 1;
	else if (ft_isind(arg2[0]))
		count += 2;
	return (count);
}

int				ft_analyse_args_two(int code, char *arg1, char *arg2)
{
	int		count;

	count = 0;
	if (code == 2)
	{
		if (arg1[0] == DIRECT_CHAR)
			count += 4;
		else if (ft_isind(arg1[0]))
			count += 2;
		arg2[0] == 'r' ? count += 1 : 0;
	}
	if (code == 3)
	{
		arg1[0] == 'r' ? count += 1 : 0;
		if (arg2[0] == 'r')
			count += 1;
		else if (ft_isind(arg2[0]))
			count += 2;
	}
	else if (code == 13)
		count += ft_analyse_args_two_helper(arg1, arg2);
	return (count + 2);
}

int				ft_analyse_args_three(int code, char *arg1, char *arg2, char *arg3)
{
	int		count;

	count = 0;
	if (code == 4 || code == 5)
	{
		if (arg1[0] == 'r' && arg2[0] == 'r' && arg3[0] == 'r')
			return (4);
	}

	if (code == 6 || code == 7 || code == 8)
	{
		/*ADD VERIF SI AUCUN TRUC VALABLE*/
		arg1[0] == 'r' ? count += 1 : 0;
		arg1[0] == DIRECT_CHAR ? count += 4 : 0;
		ft_isind(arg1[0]) ? count += 2 : 0;

		/*ADD VERIF SI AUCUN TRUC VALABLE*/
		arg2[0] == 'r' ? count += 1 : 0;
		arg2[0] == DIRECT_CHAR ? count += 4 : 0;
		ft_isind(arg2[0]) ? count += 2 : 0;

		arg3[0] == 'r' ? count += 1 : /*ERROR*/0;
		return (count + 2);
	}

	if (code == 10 || code == 14)
	{
		/*ADD VERIF SI AUCUN TRUC VALABLE*/
		arg1[0] == 'r' ? count += 1 : 0;
		arg1[0] == DIRECT_CHAR ? count += 2 : 0;
		ft_isind(arg1[0]) ? count += 2 : 0;

		arg2[0] == 'r' ? count += 1 : 0;
		arg2[0] == DIRECT_CHAR ? count += 4 : 0;
		arg2[0] != 'r' && arg2[0] != DIRECT_CHAR ? /*ERROR*/count = 0 : 0;

		arg3[0] == 'r' ? count += 1 : /*ERROR*/0;
		return (count + 1);
	}

	if (code == 11)
	{
		/*ADD VERIF SI AUCUN TRUC VALABLE*/
		arg1[0] == 'r' ? count += 1 : 0;
		arg1[0] == DIRECT_CHAR ? count += 2 : 0;
		ft_isind(arg1[0]) ? count += 2 : 0;

		/*ADD VERIF SI AUCUN TRUC VALABLE*/
		arg2[0] == 'r' ? count += 1 : 0;
		arg2[0] == DIRECT_CHAR ? count += 4 : 0;
		ft_isind(arg2[0]) ? count += 2 : 0;

		/*ADD VERIF SI AUCUN TRUC VALABLE*/
		arg3[0] == 'r' ? count += 1 : 0;
		arg3[0] == DIRECT_CHAR ? count += 4 : 0;
		arg3[0] != 'r' && arg3[0] != DIRECT_CHAR ? /*ERROR*/count = 0 : 0;

		return (count + 1);
	}
	return (0);
}
