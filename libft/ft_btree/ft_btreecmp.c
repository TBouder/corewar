/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreecmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:11:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/09 13:15:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_btreecmp() function comp by ascii the content and the list to insert
** the new data
*/

#include "../libft.h"

void 		ft_btreecmp(t_btree **tree, void const *content, size_t c_size)
{
    if (!(*tree))
		(*tree) = ft_btreenew(content, c_size);
    if (CMP((char *)content, (char *)(*tree)->content) < 0)
        ft_btreecmp(&(*tree)->left, content, c_size);
	else if (CMP((char *)content, (char *)(*tree)->content) > 0)
        ft_btreecmp(&(*tree)->right, content, c_size);
}
