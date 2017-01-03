/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2016/12/21 12:22:43 by tbouder          ###   ########.fr       */
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

	# define IS_GRAPH env->options->flags['g']
	# define IS_DUMP env->options->flags['d']
	# define IS_VERBOSE env->options->flags['v']

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

	# define COLS_MAIN (2 * COLS / 3)
	# define COLS_INFO (COLS / 3)
	# define LINES_INFO (2 * LINES / 3)
	# define LINES_NOTIF (LINES / 3)

	# define MAX (USHRT_MAX / 2) + 1

	# define ERR_HEAD "{9}ERR{0} : The magic doesn't work with the header ..."
	# define ERR_CONT "{9}ERR{0} : The magic doesn't work with the content ..."
	# define ERR_BAD_SRC_FILE "{9}ERR{0} : Can't read source file"
	# define ERR_DIR "{9}ERR{0} : Directories are not allowed"
	# define ERR_NOEXT "{9}ERR{0} : Extension .cor is missing (NOEXT)"
	# define ERR_NOT_COR "{9}ERR{0} : File extension is not .cor"
#endif
