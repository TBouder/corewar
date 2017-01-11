/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:43:15 by quroulon          #+#    #+#             */
/*   Updated: 2017/01/11 09:32:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_valid_label(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '_'))
			;
		else if (str[i] == ':' && str[i + 1] == '\0')
			;
		else
			return (0);
		i++;
	}
	return (1);
}

int			ft_valid_spaces(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && ft_isspace(str[i]))
		{
			while (str[i] && ft_isspace(str[i]))
				i++;
			if (str[i] && !ft_isspace(str[i]))
				count++;
		}
		i++;
	}
	return (count);
}

void		ft_verif_valid_spaces_fail(t_asm *env, char *str)
{
	ft_printf("{9}Err{0} : arg error here : %s", str);
	ft_error_asm(env, "", 1);
}
