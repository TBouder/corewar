/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2016/12/12 20:28:10 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACRO_H
# define FT_MACRO_H

	# define IS_REG(x) x == 1 ? 1 : 0
	# define IS_DIR(x) x == 10 ? 1 : 0
	# define IS_IND(x) x == 11 ? 1 : 0
	# define IS_DIR_REG(x) x == 11 || x == 1 ? 1 : 0
	# define IS_DIR_IND(x) x == 11 || x == 10 ? 1 : 0
	# define IS_IND_REG(x) x == 10 || x == 1 ? 1 : 0
	# define IS_ALL(x) x == 11 || x == 10 || x == 1 ? 1 : 0

	# define LIVE 1
	# define LD 2
	# define ST 3
	# define ADD 4
	# define SUB 5
	# define AND 6
	# define OR 7
	# define XOR 8
	# define ZJMP 9
	# define LDI 10
	# define STI 11
	# define FORK 12
	# define LLD 13
	# define LLDI 14
	# define LFORK 15
	# define AFF 16

	# define M MEM_SIZE
	# define I IDX_MOD

#endif
