/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:46:14 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/06 13:54:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		ft_rev_hex(char *hex)
{
	char	*new_hex;
	long	ret_value;
	int		hex_len;
	int		i;
	int		y;

	hex_len = ft_strlen(hex);
	new_hex = ft_strnew(hex_len);
	i = hex_len;
	y = 0;
	while (y < hex_len)
	{
		if (i - 2 >= 0)
		{
			new_hex[y++] = hex[i - 2];
			new_hex[y++] = hex[i - 1];
		}
		else
			new_hex[y++] = hex[i - 1];
		i -= (i - 2 >= 0) ? 2 : 1;
	}
	ret_value = ft_atoi_base(new_hex, 16);
	ft_strdel(&new_hex);
	return (ret_value);
}

static void		ft_extract_content(t_vm *env, int i)
{
	int read_success;

	read_success = 0;
	env->champions[i].content = ft_strnew(env->champions[i].prog_size);
	read_success = read(env->fd[i], env->champions[i].content, env->champions[i].prog_size);
	if (read_success)
	{
		//DEBUG
		ft_print_memory(env->champions[i].content, env->champions[i].prog_size);
	}
	else
		ft_error_asm(env, "{9}Error{0} : The magic doesn't work with the content ...", 1);
}

static void		ft_extract_header(t_vm *env, int i)
{
	int		read_success;
	char	*hex;

	read_success = read(env->fd[i], &env->header[i], sizeof(header_t));
	if (read_success)
	{
		env->champions[i].name = ft_strinit(env->header[i].prog_name);
		env->champions[i].comment = ft_strinit(env->header[i].comment);
		hex = ft_itoa_base(env->header[i].magic, 16);
		env->champions[i].magic = ft_rev_hex(hex);
		ft_strdel(&hex);
		if (env->champions[i].magic != COREWAR_EXEC_MAGIC)
			ft_error_asm(env, "{9}Error{0} : This is a bad magic ...", 1);
		hex = ft_itoa_base(env->header[i].prog_size, 16);
		env->champions[i].prog_size = ft_rev_hex(hex);
		ft_strdel(&hex);
		if (env->champions[i].prog_size > CHAMP_MAX_SIZE)
			ft_error_asm(env, "{9}Error{0} : Champion size is over 682", 1);
		env->total_size += env->champions[i].prog_size;
	}
	else
		ft_error_asm(env, "{9}Error{0} : The magic doesn't work with the header ...", 1);
}

static void		ft_extract_starting_pos(t_champions *champion, int pos)
{
	champion->starting_pos = pos;
	champion->pc = pos;
	champion->next_cycle = 0;
}

void			ft_extract_champion(t_vm *env)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	while (i < env->nb_champ)
	{
		ft_extract_header(env, i);
		ft_extract_content(env, i);
		ft_extract_starting_pos(&env->champions[i], pos);
		pos += MEM_SIZE / env->nb_champ;
		i++;
	}
}
