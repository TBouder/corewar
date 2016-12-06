/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:31:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/12/06 15:19:44 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_write_args_helper(t_asm *env, char *arg, int pds, int tmp)
{
	if (pds == 2)
	{
		tmp = ft_atoi(&arg[1]);
		tmp < 0 ? tmp = (USHRT_MAX + 1) + tmp : 0;
	}
	else if (pds == 4)
	{
		tmp = ft_atoi_l(&arg[1]);
		tmp < 0 ? tmp = (UINT_MAX + 1) + (int)tmp : 0;
	}
	ft_transform_size(tmp, env->fd_cor, pds);
}

static void		ft_write_args(t_asm *env, char *arg, int pds, int line)
{
	long		tmp;

	tmp = 0;
	if (arg[0] && arg[0] == 'r')
		ft_transform_size(ft_atoi(&arg[1]), env->fd_cor, pds);
	else if (arg[0] && arg[0] == '%')
	{
		if (arg[1] && arg[1] == ':')
			ft_transform_size(ft_calcul_jump(env, &arg[2], line, pds),
								env->fd_cor, pds);
		else
			ft_write_args_helper(env, arg, pds, tmp);
	}
	else if (arg[0] && arg[0] == ':')
		ft_transform_size(ft_calcul_jump(env, &arg[1], line, pds),
							env->fd_cor, pds);
	else
	{
		tmp = ft_atoi(&arg[0]);
		tmp < 0 ? tmp = (USHRT_MAX + 1) + tmp : 0;
		ft_transform_size(tmp, env->fd_cor, pds);
	}
}

static void		ft_write_opcode(t_asm *env, int line)
{
	int			opcode;
	char		*real_hex;

	opcode = ft_get_opcode(env->args[line][0]);
	real_hex = ft_strnew_hex(1);
	real_hex[0] += opcode;
	write(env->fd_cor, real_hex, 1);
	ft_strdel(&real_hex);
	if (opcode != 1 && opcode != 9 && opcode != 12 && opcode != 15 &&
		opcode != 16)
	{
		real_hex = ft_strnew_hex(1);
		real_hex[0] += ft_atoi_base(env->opcode_next[line], 2);
		write(env->fd_cor, real_hex, 1);
		ft_strdel(&real_hex);
	}
}

void			ft_write_empty(t_asm *env, int *i)
{
	char		*real_hex;

	while (env->file_content[(*i)][0] == '.')
		(*i)++;
	real_hex = ft_strnew_hex(4);
	write(env->fd_cor, real_hex, 4);
	ft_strdel(&real_hex);
}

void			ft_write_instructions(t_asm *env)
{
	int			i;
	int			j;

	i = 0;
	ft_write_empty(env, &i);
	while (env->file_content[i])
	{
		j = 1;
		if (env->arg_weight[i][0] > 0)
		{
			ft_write_opcode(env, i);
			while (j <= 3 && env->arg_weight[i][j] > 0)
			{
				ft_write_args(env, env->args[i][j], env->arg_weight[i][j], i);
				j++;
			}
		}
		i++;
	}
}














