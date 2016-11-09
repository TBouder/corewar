/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_print_inorder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:15:43 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/09 13:17:13 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_btree_print_inorder(t_btree *node)
{
	if (node)
	{
		ft_btree_print_inorder(node->left);
		ft_printf("%s\n", node->content);
		ft_btree_print_inorder(node->right);
	}
}
