/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:31:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/29 19:11:09 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_jump_to_label(t_asm *env, char *str, int line, int arg)
{
	int			i;
	int			j;
	int			found;
	int			cpt;
	char		**tab;

	i = 0;
	cpt = 0;
	found = 0;
	str = ft_strjoin(str, ":");
	while (env->file_content[i])
	{
		tab = ft_strsplit(env->file_content[i], ' ');
		if (ft_isstrstr(tab[0], str) == 1)
		{
			if (found != 0)
				return (cpt * found);
			found = -1;
		}
		j = 0;
		if (line == i && found == 0)
			found = 1;
		while (j <= 3 && env->arg_weight[i][j] > 0)
		{
			if (line == i && arg == j)
			{
				if (found < 0)
					return (cpt * found);
			}
			cpt += (found != 0) ? env->arg_weight[i][j] : 0;
			j++;
		}
		ft_dbstrdel(tab);
		i++;
	}

	// int			cpt;
	// int			tmp;
	// char		**tab;

	// cpt = 0;
	// tmp = arg;
	// str = ft_strjoin(str, ":");
	// ft_printf("HERE\n");
	// while (env->file_content[line])
	// {
	// 	tab = ft_strsplit(env->file_content[line], ' ');
	// 	if (ft_isstrstr(tab[0], str) == 1)
	// 	{
	// 		ft_dbstrdel(tab);
	// 		return (cpt);
	// 	}
	// 	ft_dbstrdel(tab);
	// 	arg = 0;
	// 	while (arg <= 3 && env->arg_weight[line][arg] > 0)
	// 	{
	// 		ft_printf("%d, %d\n", line, arg);
	// 		cpt += env->arg_weight[line][arg];
	// 		arg++;
	// 	}
	// 	line++;
	// }


	return (0);
}

static void		ft_write_args(t_asm *env, char **args, int *pds, int line)
{
	int			i;

	i = 1;
	while (i <= 3 && pds[i] > 0)
	{
		if (args[i][0] && args[i][0] == 'r')
			ft_transform_size(ft_atoi_hexa(&args[i][1]), env->fd, pds[i]);
		else if (args[i][0] && args[i][0] == '%')
		{
			if (args[i][1] && args[i][1] == ':')
				ft_transform_size(ft_jump_to_label(env, &args[i][2], line, i),
								env->fd, pds[i]);
			else
				ft_transform_size(ft_atoi_hexa(&args[i][1]), env->fd, pds[i]);
		}
		else
			ft_transform_size(ft_atoi_hexa(&args[i][1]), env->fd, pds[i]);
		i++;
	}
}

static void		ft_write_opcode(t_asm *env, char *inst, int pds, char *op_next)
{
	int			opcode;
	char		*real_hex;

	opcode = ft_get_opcode(inst);

	// TODO voir si on peut utiliser poids
	pds = 0;
	
	real_hex = ft_strnew_hex(1);
	real_hex[0] += opcode;
	// ft_printf("int %d\n", opcode);
	write(env->fd, real_hex, 1);
	ft_strdel(&real_hex);

	if (opcode != 1 && opcode != 9 && opcode != 12 && opcode != 15 && opcode != 16)
	{
		real_hex = ft_strnew_hex(1);
		real_hex[0] += ft_atoi_base(op_next, 2);
		// ft_printf("opnext [%s], int %d\n", op_next, ft_atoi_base(op_next, 2));
		write(env->fd, real_hex, 1);
		ft_strdel(&real_hex);
	}
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
		if (env->arg_weight[i][0] > 0)
		{
			tab = ft_strsplit(env->file_content[i], ' ');
			ft_write_opcode(env, tab[0], env->arg_weight[i][0], env->opcode_next[i]);
			ft_write_args(env, tab, env->arg_weight[i], i);
			ft_dbstrdel(tab);
		}
		i++;
	}

	// real_hex = ft_transform_size_helper(opcode, env->arg_weight[i][0]);
	// write(env->fd, real_hex, env->arg_weight[i][0]);

	// ft_transform_size(opcode, env->fd);


}
