/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:11:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/09 13:14:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_btree		*ft_btreenew(void const *content, size_t c_size)
{
	t_btree		*btree;

	if (!(btree = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	if (content == NULL)
	{
		btree->content = NULL;
		btree->content_size = 0;
	}
	else
	{
		btree->content = (void*)malloc(c_size);
		ft_memmove(btree->content, (void *)content, c_size);
		btree->content_size = c_size;
	}
	btree->left = NULL;
	btree->right = NULL;
	return (btree);
}
