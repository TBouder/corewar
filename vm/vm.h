/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/12 15:36:53 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <errno.h>
# include "ft_macro.h"

typedef struct		s_champions
{
	char			*name;				//name
	char			*comment;			//comment
	unsigned int	magic;				//magic number
	unsigned int	prog_size;			//total size
	char			*content;			//instructions
	unsigned int	starting_pos;		//position de depart dans la map
	int				champ_id;

	int				reg[REG_NUMBER];	//Los registros
	int				pc;					//el pc
	void			*pc_void;			//el pc de trump
	bool			carry;				//bool for carry fisher
	int				is_alive;			//Le champion a t'il dit qu'il etait en vie ?
	bool			exist;				//Le champion existe t'il encore ?
	int				cycle;				//Ya une histoire de cycle
	int				next_cycle;
}					t_champions;

typedef struct		s_vm
{
	t_options		*options;			//Flags

	t_champions		*champions;			//Struct for each champion
	t_champions		*winner;			//WINNER
	int				*fd;				//Each champion
	char			**filename;			//Each champion name
	int				nb_champ;			//Number of champion
	int				total_size;			//Total size of the champions

	int				cycle_to_die;
	int				cpt_to_die;
	int				cycle_check;
	int				cycle;

	int				arg1;
	int				arg2;
	int				arg3;
	int				buf;

	// int				detla;
	// int				nbr_live;

	header_t		*header;			//header struct
	char			*map;				//Total map
}					t_vm;

/*
** main.c
*/
void			ft_error_asm(t_vm *env, char *msg, int clear);

void			ft_fight(t_vm *env);

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
int				*ft_send_args(char *bin);
int				*ft_get_size(t_vm *env, t_champions *champ, int is_not_live);
int				ft_count_to_next(int *nbr, int op);
int				ft_byte_to_str(char *str, int len);

int				ft_get_args(t_vm *env, t_champions *champ, int op);

void			ft_corewar_live(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_aff(t_vm *env, t_champions *champ, int *nbr);

void			ft_corewar_st(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr);

void			ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr);

void			ft_corewar_ldi(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_lldi(t_vm *env, t_champions *champ, int *nbr);

void			ft_corewar_zjmp(t_vm *env, t_champions *champ, int *nbr);

void			ft_corewar_fork(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_lfork(t_vm *env, t_champions *champ, int *nbr);

void			ft_corewar_add(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_sub(t_vm *env, t_champions *champ, int *nbr);

void			ft_corewar_and(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_or(t_vm *env, t_champions *champ, int *nbr);
void			ft_corewar_xor(t_vm *env, t_champions *champ, int *nbr);

/*
** TMP
*/
void		ft_print_arg_count(int *nbr, int count, int pc);


#endif
