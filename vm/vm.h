/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/29 20:06:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <errno.h>

typedef struct		s_champions
{
	char			*name;
	char			*comment;
	unsigned int	magic;
	unsigned int	prog_size;
	char			*content;
	unsigned int	starting_pos;
}					t_champions;

typedef struct		s_vm
{
	t_options		*options;			//Flags
	int				*fd;
	char			**filename;
	int				nb_champ;
	t_champions		*champions;
	int				total_size;
	header_t		*header;
	char			*map;
}					t_vm;

/*
** main.c
*/
void			ft_error_asm(t_vm *env, char *msg, int clear);

/*
** ft_init.c
*/
void			ft_init_env(t_vm *env, int part);


/*
** ft_extract_champion.c
*/
void			ft_extract_champion(t_vm *env);


/*
** ft_func_part1
*/
void		ft_corewar_live(void);
void		ft_corewar_ld(void);
void		ft_corewar_st(void);
void		ft_corewar_add(void);
void		ft_corewar_sub(void);
void		ft_corewar_and(void);
void		ft_corewar_or(void);
void		ft_corewar_xor(void);
void		ft_corewar_zjmp(void);
void		ft_corewar_ldi(void);
void		ft_corewar_sti(void);
void		ft_corewar_fork(void);
void		ft_corewar_lld(void);
void		ft_corewar_lldi(void);
void		ft_corewar_lfork(void);
void		ft_corewar_aff(void);



#endif
