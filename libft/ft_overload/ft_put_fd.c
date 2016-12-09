/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:19:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 17:33:56 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	OVERLOAD ft_put_fd(int nbr, int fd)
{
	ft_putnbr_fd(nbr, fd);
}

void	OVERLOAD ft_put_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
}

void	OVERLOAD ft_put_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
}
