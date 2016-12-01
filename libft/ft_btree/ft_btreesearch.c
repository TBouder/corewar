/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreesearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:49:26 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/25 13:50:41 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_btreesearch(t_btree *node, char *content, int *ret)
{
	if (node)
	{
		ft_btreesearch(node->left, content, ret);
		if (EQU(node->content, content))
		{
			*ret = 1;
			return ;
		}
		ft_btreesearch(node->right, content, ret);
	}
}
