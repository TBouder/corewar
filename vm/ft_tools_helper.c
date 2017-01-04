/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:39:20 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/04 13:53:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_get_file_size(int fd)
{
	unsigned int	o_pos;
	unsigned int	file_size;
	unsigned int	prog_size;

 	o_pos = lseek(fd, 0, SEEK_CUR);
	file_size = lseek(fd, 0, SEEK_END) * 2;
	// file_size *= 2;
	prog_size = (MAGIC_LEN * 2) + (PROG_NAME_LENGTH * 2)
				+ (COMMENT_LENGTH * 2) + (SIZE_LEN * 2);
	lseek(fd, o_pos, SEEK_SET);
	return ((file_size - prog_size) / 2);
}
