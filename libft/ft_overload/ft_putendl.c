/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 17:34:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	OVERLOAD ft_putendl(int nbr)
{
	ft_nbrendl(nbr);
}

void	OVERLOAD ft_putendl(char c)
{
	ft_putcendl(c);
}

void	OVERLOAD ft_putendl(const char *format, ...)
{
	ft_put(format);
	ft_put('\n');
}
