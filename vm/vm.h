/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 16:33:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <errno.h>

typedef		int	bool;

typedef struct		s_champions
{
	char			*name;				//name
	char			*comment;			//comment
	unsigned int	magic;				//magic number
	unsigned int	prog_size;			//total size
	char			*content;			//instructions
	unsigned int	starting_pos;		//position de depart dans la map

	char			reg[REG_NUMBER];	//Los registros
	int				pc;					//el pc
	void			*pc_void;			//el pc de trump
	bool			carry;				//bool for carry fisher
	int				is_alive;			//Le champion a t'il dit qu'il etait en vie ?
	bool			exist;				//Le champion existe t'il encore ?
	int				cycle;				//Ya une histoire de cycle
}					t_champions;

typedef struct		s_vm
{
	t_options		*options;			//Flags

	t_champions		*champions;			//Struct for each champion
	int				*fd;				//Each champion
	char			**filename;			//Each champion name
	int				nb_champ;			//Number of champion
	int				total_size;			//Total size of the champions

	int				to_die;
	int				detla;
	int				nbr_live;

	header_t		*header;			//header struct
	char			*map;				//Total map
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
