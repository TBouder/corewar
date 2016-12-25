/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/25 14:54:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <errno.h>
# include "ft_macro.h"
# include <ncurses.h>

typedef struct		s_champions
{
	long			id;
	char			*name;				//name
	char			*comment;			//comment
	unsigned int	magic;				//magic number
	unsigned int	prog_size;			//total size
	char			*content;			//instructions
	unsigned int	starting_pos;		//position de depart dans la map
	int				champ_id;

	// int				reg[REG_NUMBER];	//Los registros
	int				reg[100];	//Los registros
	int				pc;					//el pc
	void			*pc_void;			//el pc de trump
	int				carry;				//bool for carry fisher
	int				cycle;				//Ya une histoire de cycle
	int				next_cycle;

	int				is_fork;
	int				color;
}					t_champions;

typedef struct		s_vm
{
	t_options		*options;			//Flags
	int				dump_cycle;

	t_champions		*winner;			//WINNER
	t_list			*list_champions;
	int				nb_live[5];
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
	int				sum_idx;

	header_t		*header;			//header struct
	char			*map;				//Total map
	int				*map_owner;			//FOR COLORS
	int				*map_moves;			//FOR CHANGES
	int				*map_moves_buff;	//FOR TIME BEFORE CHANGE EXPIRES

	long			current_id;

	//NCURSE
	WINDOW	*main_border;
	WINDOW	*main;
	WINDOW	*info_border;
	WINDOW	*info;
	WINDOW	*notif_border;
	WINDOW	*notif;

	unsigned int	usleep;
	unsigned int	nb_notif;
	int				total_live;
	int				n_key;
}					t_vm;

void			ft_extract_champion(t_vm *env);
void			ft_fight(t_vm *env);

/*
** FUNCS
*/
int				*ft_send_args(char *bin);
int				*ft_get_size(t_vm *env, t_champions *champ);
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
** NCURSE
*/
void			ft_init_ncurse(t_vm *env);
void			ft_clear_ncurse(t_vm *env);
void			ft_get_key(t_vm *env);
void			ft_print_champion_color(t_champions *champion, WINDOW *win);
void			ft_print_infos(t_vm *env);
void			ft_print_champions_infos(t_vm *env);
void			ft_reload_windows(t_vm *env, int part);

/*
** DUMP
*/
void			ft_dump(const void *addr, size_t size);
void			ft_dump_ncurse(t_vm *env, const void *addr, size_t size);

/*
** INIT
*/
void			ft_init_env(t_vm *env, int part);
void			ft_init_reg(t_champions *new_champ, t_champions *champ);
void			ft_set_nb_live(t_vm *env, int val);

/*
** FREE
*/
void			ft_clear_champ(t_list **blist, int id);
void			ft_clear_all(t_vm *env);
void			ft_error_vm(t_vm *env, char *msg, int clear);

/*
** VERBOSE
*/
void			ft_verbose_fork(t_vm *env, t_champions *champ, t_champions *c);
void			ft_verbose_champ_info(t_vm *env, t_champions *champ, int part);
void			ft_verbose_dead(t_vm *env, t_champions *champ);
void			ft_verbose_winner(t_vm *env);

/*
** TOOLS
*/
void			ft_verif_extension(t_vm *env, char **av, int i);
int				ft_which_isalive(t_vm *env);
int				ft_one_isalive(t_vm *env);
void			ft_add_champion(t_vm *env, t_champions *champ, int id, int pc);
int				ft_ret_cycle(int op);

#endif
