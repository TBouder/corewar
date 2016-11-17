/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:52:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/17 15:54:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_transform_magic(void)
{
	int		i;
	int		y;
	char	*magic;
	char	*magic_hex;
	int		magic_len;
	char	*tmp;

	i = 0;
	magic = ft_itox(COREWAR_EXEC_MAGIC);
	magic_hex = ft_strnew_hex(MAGIC_LEN);
	magic_len = ft_strlen(magic);
	y = (MAGIC_LEN * 2) / magic_len;
	if (y == 1 && (PROG_NAME_LENGTH * 2) % (magic_len - 1) == 0)
		y = 0;
	while (i <= MAGIC_LEN)
	{
		tmp = ft_strsub(magic, i, 2);
		magic_hex[y] += ft_atoi_hexa(tmp);
		ft_strdel(&tmp);
		y++;
		i += 2;
	}
	ft_strdel(&magic);
	return (magic_hex);
}

char		*ft_transform_name(t_asm *env)
{
	int		i;
	int		y;
	char	*magic;
	char	*magic_hex;
	int		magic_len;

	i = 0;
	magic = ft_strinit(env->champ_name);
	magic_hex = ft_strnew_hex(PROG_NAME_LENGTH);
	magic_len = ft_strlen(magic);
	y = (PROG_NAME_LENGTH * 2) / magic_len;
	if (y == 1 && (PROG_NAME_LENGTH * 2) % (magic_len - 1) == 0)
		y = 0;
	while (magic[i])
	{
		magic_hex[y] += magic[i];
		y++;
		i += 1;
	}
	ft_strdel(&magic);
	return (magic_hex);
}
