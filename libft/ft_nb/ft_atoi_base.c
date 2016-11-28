/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:12:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/28 19:28:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_atoi_base() function converts the initial portion of the string pointed
** to by str to int representation.
*/

#include "../libft.h"

static int		ft_verif(char *str, int *i, int sign)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t' ||
			str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-')
		sign = -1;
	else if (str[*i] == '+')
		sign = 1;
	return (sign);
}

long			ft_atoi_base(char *str, int base)
{
	int			i;
	long		res;
	int			sign;

	i = 0;
	res = 0;
	sign = ft_verif(str, &i, 1);
	while (ft_isdigit(str[i]) == 1 || (str[i] <= 'f' && str[i] >= 'a') ||
			(str[i] <= 'F' && str[i] >= 'A'))
	{
		if (str[i] == '\0')
			return (res);
		res *= base;
		if (ft_isdigit(str[i]) == 1)
			res += (str[i] - '0') * base;
		else if (str[i] <= 'f' && str[i] >= 'a')
			res += (str[i] - 'a' + 10) * base;
		else if (str[i] <= 'F' && str[i] >= 'A')
			res += (str[i] - 'A' + 10) * base;
		i++;
	}
	return (sign * (res /= base));
}
