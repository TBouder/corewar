/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:31:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/12/01 15:12:55 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long			ft_atoi_l(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (ft_strlen(str) == 0 || (*str < 32 && !ft_isspace(*str)))
		return (0);
	while (*str <= 32)
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result + *str++ - '0') * 10;
	return (result / 10 * sign);
}

long			ft_calcul_jump(t_asm *env, char *str, int line, int pds)
{
	long		cpt;
	int			match;
	char		*label;

	cpt = 0;
	match = -1;
	label = ft_strjoin(str, ":");
	ft_btreesearch_asm(env->file_labels, label, &match);
	if (match > 0 && line < match)
	{
		while (line < match)
		{
			cpt += env->instruct_weight[line];
			line++;
		}
	}
	else if (match > 0 && line > match)
	{
		line--;
		while (line > match)
		{
			cpt += env->instruct_weight[line];
			line--;
		}
		if (pds == 2)
			cpt = (cpt != 0) ? (USHRT_MAX + 1) - cpt : 0;
		else if (pds == 4)
			cpt = (cpt != 0) ? (UINT_MAX + 1) - cpt : 0;
	}
	ft_strdel(&label);
	return (cpt);
}

// static void		ft_write_args(t_asm *env, char **args, int *pds, int line)
static void		ft_write_args(t_asm *env, int line)
{
	int			i;
	long		tmp;

	i = 1;
	tmp = 0;
	while (i <= 3 && env->arg_weight[line][i] > 0)
	{
		if (env->args[line][i][0] && env->args[line][i][0] == 'r')
			ft_transform_size(ft_atoi(&env->args[line][i][1]), env->fd_cor, env->arg_weight[line][i]);
		else if (env->args[line][i][0] && env->args[line][i][0] == '%')
		{
			if (env->args[line][i][1] && env->args[line][i][1] == ':')
				ft_transform_size(ft_calcul_jump(env, &env->args[line][i][2], line, env->arg_weight[line][i]), env->fd_cor, env->arg_weight[line][i]);
			else
			{
				if (env->arg_weight[line][i] == 2)
				{
					tmp = ft_atoi(&env->args[line][i][1]);
					tmp < 0 ? tmp = (USHRT_MAX + 1) + tmp : 0;
				}
				else if (env->arg_weight[line][i] == 4)
				{
					tmp = ft_atoi_l(&env->args[line][i][1]);
					if (tmp < 0)
						tmp = (UINT_MAX + 1) + (int)tmp;
				}
				ft_transform_size(tmp, env->fd_cor, env->arg_weight[line][i]);
			}
		}
		else if (env->args[line][i][0] && env->args[line][i][0] == ':')
		{
			ft_transform_size(ft_calcul_jump(env, &env->args[line][i][1], line, env->arg_weight[line][i]), env->fd_cor, env->arg_weight[line][i]);

		}
		else
		{
			tmp = ft_atoi(&env->args[line][i][0]);
			if (tmp < 0)
			{
				tmp = (USHRT_MAX + 1) + tmp;
			}
			ft_transform_size(tmp, env->fd_cor, env->arg_weight[line][i]);
		}
		i++;
	}
}

// static void		ft_write_opcode(t_asm *env, char *inst, int pds, char *op_next)
static void		ft_write_opcode(t_asm *env, int line)
{
	int			opcode;
	char		*real_hex;

	opcode = ft_get_opcode(env->args[line][0]);

	real_hex = ft_strnew_hex(1);
	real_hex[0] += opcode;
	write(env->fd_cor, real_hex, 1);
	ft_strdel(&real_hex);

	if (opcode != 1 && opcode != 9 && opcode != 12 && opcode != 15 && opcode != 16)
	{
		real_hex = ft_strnew_hex(1);
		real_hex[0] += ft_atoi_base(env->opcode_next[line], 2);
		write(env->fd_cor, real_hex, 1);
		ft_strdel(&real_hex);
	}

	// int			opcode;
	// char		*real_hex;

	// opcode = ft_get_opcode(inst);

	// // TODO voir si on peut utiliser poids
	// pds = 0;

	// real_hex = ft_strnew_hex(1);
	// real_hex[0] += opcode;
	// write(env->fd_cor, real_hex, 1);
	// ft_strdel(&real_hex);

	// if (opcode != 1 && opcode != 9 && opcode != 12 && opcode != 15 && opcode != 16)
	// {
	// 	real_hex = ft_strnew_hex(1);
	// 	real_hex[0] += ft_atoi_base(op_next, 2);
	// 	write(env->fd_cor, real_hex, 1);
	// 	ft_strdel(&real_hex);
	// }
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
	// char		**tab;

	i = 0;
	ft_write_empty(env, &i);
	while (env->file_content[i])
	{
		if (env->arg_weight[i][0] > 0)
		{
			// tab = ft_strsplit(env->file_content[i], ' ');
			// ft_write_opcode(env, tab[0], env->arg_weight[i][0], env->opcode_next[i]);
			ft_write_opcode(env, i);
			// ft_write_args(env, tab, env->arg_weight[i], i);
			ft_write_args(env, i);
			// ft_dbstrdel(tab);
		}
		i++;
	}
}
