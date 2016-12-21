/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:46:14 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 09:37:21 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define CHAMPIONS	((t_champions *)champion->content)

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

static void		ft_extract_starting_pos_lst(int pos, t_list *champion)
{
	CHAMPIONS->starting_pos = pos;
	CHAMPIONS->pc = pos;
	CHAMPIONS->next_cycle = 0;
}

static void		ft_extract_content_lst(t_vm *env, int i, t_list *champion)
{
	int read_success;

	read_success = 0;
	CHAMPIONS->content = ft_strnew(CHAMPIONS->prog_size);
	read_success = read(env->fd[i], CHAMPIONS->content, CHAMPIONS->prog_size);
	if (read_success)
		; // ft_print_memory(CHAMPIONS->content, CHAMPIONS->prog_size); //DEBUG
	else
		ft_error_vm(env, ERR_CONT, 1);
}

static void		ft_extract_header_lst(t_vm *env, int i, t_list *champion)
{
	int		read_success;
	char	*hex;

	read_success = read(env->fd[i], &env->header[i], sizeof(header_t));
	if (read_success)
	{
		CHAMPIONS->name = ft_strinit(env->header[i].prog_name);
		CHAMPIONS->comment = ft_strinit(env->header[i].comment);
		hex = ft_itoa_base(env->header[i].magic, 16);
		CHAMPIONS->magic = ft_rev_hex(hex);
		ft_strdel(&hex);
		if (CHAMPIONS->magic != COREWAR_EXEC_MAGIC)
			ft_error_vm(env, "{9}Error{0} : This is a bad magic ...", 1);
		hex = ft_itoa_base(env->header[i].prog_size, 16);
		CHAMPIONS->prog_size = ft_rev_hex(hex);
		ft_strdel(&hex);
		if (CHAMPIONS->prog_size > CHAMP_MAX_SIZE)
			ft_error_vm(env, "{9}Error{0} : Champion size is over 682", 1);
		env->total_size += CHAMPIONS->prog_size;
	}
	else
		ft_error_vm(env, ERR_HEAD, 1);
}


void			ft_extract_champion(t_vm *env)
{
	int		i;
	int		pos;
	t_list	*list;

	i = 0;
	pos = 0;
	list = env->list_champions;
	while (i < env->nb_champ)
	{
		ft_extract_header_lst(env, i, list);
		ft_extract_content_lst(env, i, list);
		ft_extract_starting_pos_lst(pos, list);
		pos += MEM_SIZE / env->nb_champ;
		i++;
		list = list->next;
	}
}
