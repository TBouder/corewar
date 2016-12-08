/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:31:48 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 17:19:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putcendl() function writes the character c (converted to an
** 'unsigned char') to STDIN. And add a \n
*/

#include "../libft.h"

void		ft_putcendl(char c)
{
	ft_putchar(c);
	ft_putchar('\n');
}
