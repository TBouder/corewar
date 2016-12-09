/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 17:24:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl() function prints the string str to STDIN followed by a \n.
*/

#include "../libft.h"

void		ft_put_endl(char const *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
