/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:31:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/29 13:06:50 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static void		ft_jump_to_label()
// {

// }

char		*my_transform_size_helper(int content, size_t content_size)
{
	int		i;
	int		y;
	char	*magic;
	char	*magic_hex;
	int		odd;
	char	*tmp;

	i = 0;
	y = 0;
	magic = ft_itox(content);
	magic_hex = ft_strnew_hex(content_size);
	odd = ft_strlen(magic) % 2;
	while (magic[i])
	{
		tmp = ft_strsub(magic, i, (i == 0 && odd) ? 1 : 2);
		magic_hex[y] += ft_atoi_hexa(tmp);
		ft_strdel(&tmp);
		y++;
		i += (i == 0 && odd) ? 1 : 2;
	}
	ft_strdel(&magic);
	return (magic_hex);
}

void		my_transform_size(int content, int fd, int len)
{
	char		*hex_string;
	char		*content_str;
	int			len_size;
	int			len_buffer;
	int			odd;

	content_str = ft_itox(content);
	len_size = ft_strlen(content_str);
	odd = len_size % 2 ? 1 : 0;
	len_size = (len_size / 2) + odd;
	len_buffer = len - len_size; // TODO remplacer 8 par macro
	write(fd, "\x00", len_buffer);
	hex_string = my_transform_size_helper(content, len_size);
	write(fd, hex_string, len_size);
	ft_strdel(&hex_string);
	ft_strdel(&content_str);
}



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

				// my_transform_size(7, env->fd, pds[i]);
				// ft_jump_to_label();
			else
			{
				// ft_printf("%d\n")
				my_transform_size(ft_atoi_hexa(&args[i][1]), env->fd, pds[i]);
			}
				// real_hex[0] += ft_atoi_hexa(&args[i][1]);
		}
		else
			real_hex[0] += ft_atoi_hexa(&args[i][0]);
		i++;
	}
}

static void		ft_write_opcode(t_asm *env, char *inst, int pds, char *op_next)
{
	int			opcode;
	char		*real_hex;

	opcode = ft_get_opcode(inst);
	
	real_hex = ft_strnew_hex(pds / 2);
	real_hex[0] += opcode;
	ft_printf("int %d\n", opcode);
	write(env->fd, real_hex, pds / 2);
	ft_strdel(&real_hex);

	real_hex = ft_strnew_hex(pds / 2);
	real_hex[0] += ft_atoi_base(op_next, 2);
	ft_printf("opnext [%s], int %d\n", op_next, ft_atoi_base(op_next, 2));
	write(env->fd, real_hex, pds / 2);
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
			ft_write_opcode(env, tab[0], env->arg_weight[i][0], env->opcode_next[i]);
			ft_write_args(env, tab, env->arg_weight[i]);
			ft_dbstrdel(tab);
		}
		i++;
	}

	// real_hex = ft_transform_size_helper(opcode, env->arg_weight[i][0]);
	// write(env->fd, real_hex, env->arg_weight[i][0]);

	// ft_transform_size(opcode, env->fd);


}
