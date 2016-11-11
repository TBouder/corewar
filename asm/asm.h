/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/11 17:44:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include <errno.h>

typedef struct		s_asm
{
	char			*filename;
	char			*filename_noext;
	char			*champ_name;
	char			*champ_comment;
}					t_asm;

#endif
