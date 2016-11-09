/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_print_preorder.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:15:43 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/09 13:17:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_btree_print_preorder(t_btree *node)
{
	if (node)
	{
		ft_printf("%s\n", node->content);
		ft_btree_print_preorder(node->left);
		ft_btree_print_preorder(node->right);
	}
}
