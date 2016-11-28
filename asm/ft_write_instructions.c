/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:31:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/28 19:39:16 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static void		ft_write_args(t_asm *env, )

static void		ft_write_opcode(t_asm *env, char *inst, int pds)
{
	int			opcode;
	char		*real_hex;

	opcode = ft_get_opcode(inst);
	real_hex = ft_strnew_hex(pds);
	real_hex[0] += opcode;
	write(env->fd, real_hex, pds);
	ft_strdel(&real_hex);
}

static void		ft_write_empty(t_asm *env, int *i)
{
	char		*real_hex;

	while (env->file_content[(*i)][0] == '.')
		(*i)++;
	real_hex = ft_strnew_hex(4);
	write(env->fd, real_hex, 4);
	ft_strdel(&real_hex);
}

void			ft_write_instructions(t_asm *env)
{
	int			i;
	char		**tab;

	i = 0;
	ft_write_empty(env, &i);
	while (env->file_content[i])
	{
		tab = ft_strsplit(env->file_content[i], ' ');
		ft_write_opcode(env, tab[0], env->arg_weight[i][0]);
		// ft_write_args(env, tab, env->arg_weight[i]);
		i++;
	}

	// real_hex = ft_transform_size_helper(opcode, env->arg_weight[i][0]);
	// write(env->fd, real_hex, env->arg_weight[i][0]);

	// ft_transform_size(opcode, env->fd);


}
