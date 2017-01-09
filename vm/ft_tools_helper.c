/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:39:20 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 18:25:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_get_file_size(int fd)
{
	unsigned int	o_pos;
	unsigned int	file_size;
	unsigned int	prog_size;

	o_pos = lseek(fd, 0, SEEK_CUR);
	file_size = lseek(fd, 0, SEEK_END) * 2;
	prog_size = (8) + (128 * 2) + (2048 * 2) + (24);
	lseek(fd, o_pos, SEEK_SET);
	return ((file_size - prog_size) / 2);
}

void	ft_put_map_reg(t_vm *env, t_champions *champ, int i, int j)
{
	char			*reg;
	char			*begin_reg;
	char			*sub_reg;
	int				len;

	reg = ft_strinit((char *)"00000000");
	begin_reg = ft_itox(env->arg1);
	len = ft_strlen(begin_reg);
	while (i < 8 && len)
	{
		reg[7 - i++] = begin_reg[len - 1];
		len--;
	}
	i = 0;
	while (i < 8)
	{
		sub_reg = ft_strsub(reg, i, 2);
		ft_color_map(env, champ, champ->pc - 1
			+ ft_mod(env->sum_idx + j, I), sub_reg);
		i += 2;
		j += 1;
		ft_strdel(&sub_reg);
	}
	ft_strdel(&begin_reg);
	ft_strdel(&reg);
}
