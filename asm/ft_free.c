/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:02:26 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/25 13:10:17 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_clear_all(t_asm *env)
{
	ft_dbstrdel(env->file_content);
	ft_strdel(&env->filename);
	ft_strdel(&env->filename_noext);
	ft_strdel(&env->champ_name);
	ft_strdel(&env->champ_comment);
	ft_btreedel(env->file_labels);
	ft_strdel(&env->error_val);
	ft_dbstrdel(env->args);
}
