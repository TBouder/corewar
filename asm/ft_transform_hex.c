/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:52:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/17 21:29:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_transform_magic(void)
{
	int		i;
	int		y;
	char	*magic;
	char	*magic_hex;
	int		magic_len;
	char	*tmp;

	i = 0;
	magic = ft_itox(COREWAR_EXEC_MAGIC);
	magic_hex = ft_strnew_hex(MAGIC_LEN);
	magic_len = ft_strlen(magic);
	y = (MAGIC_LEN * 2) / magic_len;
	if (y == 1 && (MAGIC_LEN * 2) % (magic_len - 1) == 0)
		y = 0;
	while (i <= MAGIC_LEN)
	{
		tmp = ft_strsub(magic, i, 2);
		magic_hex[y] += ft_atoi_hexa(tmp);
		ft_strdel(&tmp);
		y++;
		i += 2;
	}
	ft_strdel(&magic);
	return (magic_hex);
}

char		*ft_transform_champ_infos(char *content, size_t content_size)
{
	int		i;
	int		y;
	char	*magic;
	char	*magic_hex;

	i = 0;
	magic = ft_strinit(content);
	magic_hex = ft_strnew_hex(content_size);
	y = 0;
	while (magic[i])
	{
		magic_hex[y] += magic[i];
		y++;
		i += 1;
	}
	ft_strdel(&magic);
	return (magic_hex);
}

static char		*ft_transform_size_helper(int content, size_t content_size)
{
	int		i;
	int		y;
	char	*magic;
	char	*magic_hex;
	int		odd;
	char	*tmp;

	i = 0;
	y = 0;
	magic = ft_itox(content);
	magic_hex = ft_strnew_hex(content_size);
	odd = ft_strlen(magic) % 2;
	while (magic[i])
	{
		tmp = ft_strsub(magic, i, (i == 0 && odd) ? 1 : 2);
		magic_hex[y] += ft_atoi_hexa(tmp);
		ft_strdel(&tmp);
		y++;
		i += (i == 0 && odd) ? 1 : 2;
	}
	ft_strdel(&magic);
	return (magic_hex);
}

void		ft_transform_size(int content, int fd)
{
	char		*content_str;
	int			len_size;
	int			len_buffer;
	int			odd;

	content_str = ft_itox(content);
	len_size = ft_strlen(content_str);
	odd = len_size % 2 ? 1 : 0;
	len_size = (len_size / 2) + odd;
	len_buffer = 8 - len_size;
	write(fd, "\x00", len_buffer);
	write(fd, ft_transform_size_helper(TMP_SIZE, len_size), len_size);
	ft_strdel(&content_str);
}
