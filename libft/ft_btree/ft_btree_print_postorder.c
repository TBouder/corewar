/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_print_postorder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:15:43 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/09 13:16:47 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_btree_print_postorder(t_btree *node)
{
	if (node)
	{
		ft_btree_print_postorder(node->left);
		ft_btree_print_postorder(node->right);
		ft_printf("%s\n", node->content);
	}
}
