/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/04 10:55:11 by tbouder          ###   ########.fr       */
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
	char			*name;
	char			*comment;
	unsigned int	magic;
	unsigned int	prog_size;
	char			*content;
	unsigned int	starting_pos;
	int				champ_id;
	int				fake_id;
	unsigned long			reg[100];
	int				pc;
	int				carry;
	int				cycle;
	int				next_cycle;
	int				is_fork;
	int				color;
}					t_champions;

typedef struct		s_vm
{
	t_options		*options;
	t_list			*champs;
	int				dump_cycle;
	t_champions		*winner;
	t_list			*list_champions;
	int				nb_live[5];
	int				*fd;
	char			**filename;
	int				nb_champ;
	int				total_size;
	int				cycle_to_die;
	int				cpt_to_die;
	int				cycle_check;
	int				cycle;
	int				arg1;
	int				arg2;
	int				arg3;
	int				buf;
	int				sum_idx;
	t_header		*header;
	char			*map;
	int				*map_owner;
	int				*map_moves;
	int				*map_moves_buff;
	long			current_id;
	int				*fake_id;
	WINDOW			*main_border;
	WINDOW			*main;
	WINDOW			*info_border;
	WINDOW			*info;
	WINDOW			*notif_border;
	WINDOW			*notif;
	unsigned int	usleep;
	unsigned int	nb_notif;
	int				total_live;
	int				n_key;
}					t_vm;

void				ft_extract_champion(t_vm *env);
void				ft_fight(t_vm *env);

/*
** FLAGS
*/
int					ft_get_flags(t_vm *env, char **av, t_options *options);

/*
** FUNCS
*/
int					*ft_send_args(char *bin);
int					*ft_get_size(t_vm *env, t_champions *champ);
int					ft_count_to_next(int *nbr, int op);
int					ft_byte_to_str(char *str, int len);
int					ft_get_args(t_vm *env, t_champions *champ, int op);
void				ft_corewar_live(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_aff(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_st(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_ldi(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_lldi(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_zjmp(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_fork(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_lfork(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_add(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_sub(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_and(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_or(t_vm *env, t_champions *champ, int *nbr);
void				ft_corewar_xor(t_vm *env, t_champions *champ, int *nbr);

/*
** NCURSE
*/
void				ft_init_ncurse(t_vm *env);
void				ft_clear_ncurse(t_vm *env);
void				ft_get_key(t_vm *env);
void				ft_print_champion_color(t_champions *champion, WINDOW *win);
void				ft_print_infos(t_vm *env);
void				ft_print_champions_infos(t_vm *env);
void				ft_reload_windows(t_vm *env, int part);

/*
** DUMP
*/
void				ft_dump(const void *addr, size_t size);
void				ft_dump_ncurse(t_vm *env, const void *addr, size_t size);

/*
** INIT
*/
void				ft_init_env(t_vm *env, int part);
void				ft_init_reg(t_champions *new_champ, t_champions *champ);
void				ft_init_fake_id(t_vm *env);
void				ft_init_champ(t_vm *env, t_champions *champ, int id,
					int pc);

/*
** FREE
*/
void				ft_clear_champ(t_list **blist, int id);
void				ft_clear_all(t_vm *env);
void				ft_error_vm(t_vm *env, char *msg, int clear);
void				ft_success_vm(t_vm *env, int clear);

/*
** VERIF
*/
void				ft_verif_extension(t_vm *env, t_list *champs);
void				ft_verif_fake_id(t_vm *env);
int					ft_verif_one_alive(t_vm *env);
int					ft_verif_alives(t_vm *env);

/*
** VERBOSE
*/
void				ft_verbose_fork(t_vm *env, t_champions *champ,
					t_champions *c);
void				ft_verbose_champ_info(t_vm *env, t_champions *champ,
					int part);
void				ft_verbose_dead(t_vm *env, t_champions *champ);
void				ft_verbose_winner(t_vm *env);

/*
** TOOLS
*/
int					ft_ret_cycle(int op);
void				ft_set_lives(t_vm *env, int val);
void				ft_reset_lives(t_vm *env, int val);
int					ft_set_buffer_and_or_xor(int nbr);
int					ft_mod(int nbr, int mod);

#endif
