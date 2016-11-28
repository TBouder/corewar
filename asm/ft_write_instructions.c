/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:31:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/28 20:39:03 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static void		ft_jump_to_label()
// {

// }

static void		ft_write_args(t_asm *env, char **args, int *pds)
{
	int			i;
	char		*real_hex;

	i = 1;
	while (i <= 3 && pds[i] > 0)
	{
		real_hex = ft_strnew_hex(pds[i]);
		if (args[i][0] && args[i][0] == 'r')
			real_hex[0] += ft_atoi_hexa(&args[i][1]);
		else if (args[i][0] && args[i][0] == '%')
		{
			if (args[i][1] && args[i][1] == ':')
				real_hex[0] += 7;
				// ft_jump_to_label();
			else
				real_hex[0] += ft_atoi_hexa(&args[i][1]);
		}
		else
			real_hex[0] += ft_atoi_hexa(&args[i][0]);
		write(env->fd, real_hex, pds[i]);
		i++;
	}
}

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
		if (env->arg_weight[i][0] > 0)
		{
			tab = ft_strsplit(env->file_content[i], ' ');
			ft_write_opcode(env, tab[0], env->arg_weight[i][0]);
			ft_write_args(env, tab, env->arg_weight[i]);
			ft_dbstrdel(tab);
		}
		i++;
	}

	// real_hex = ft_transform_size_helper(opcode, env->arg_weight[i][0]);
	// write(env->fd, real_hex, env->arg_weight[i][0]);

	// ft_transform_size(opcode, env->fd);


}
