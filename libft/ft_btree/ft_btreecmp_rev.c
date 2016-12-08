/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreecmp_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:11:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 17:31:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_btreecmp() function comp by rev ascii the content and the list to
** insert the new data
*/

#include "../libft.h"

void	ft_btreecmp_rev(t_btree **tree, void const *content, size_t c_size)
{
	if (!(*tree))
		(*tree) = ft_btreenew(content, c_size);
	if (CMP((char *)content, (char *)(*tree)->content) < 0)
		ft_btreecmp_rev(&(*tree)->right, content, c_size);
	else if (CMP((char *)content, (char *)(*tree)->content) > 0)
		ft_btreecmp_rev(&(*tree)->left, content, c_size);
}
