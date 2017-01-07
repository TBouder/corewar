/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:40:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 12:31:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_btree_asm	*ft_btreenew_asm(void const *content, size_t c_size,
					int line)
{
	t_btree_asm		*btree;

	if (!(btree = (t_btree_asm *)malloc(sizeof(t_btree_asm))))
		return (NULL);
	if (content == NULL)
	{
		btree->content = NULL;
		btree->content_size = 0;
		btree->line = 0;
	}
	else
	{
		btree->content = (void*)malloc(c_size);
		ft_memmove(btree->content, (void *)content, c_size);
		btree->content_size = c_size;
		btree->line = line;
	}
	btree->left = NULL;
	btree->right = NULL;
	return (btree);
}

void				ft_btreecmp_asm(t_asm *env, t_btree_asm **tree,
					void const *content, size_t c_size)
{
	if (!(*tree))
	{
		(*tree) = ft_btreenew_asm(content, c_size, env->file_len);
		return ;
	}
	if (CMP((char *)content, (char *)(*tree)->content) < 0)
		ft_btreecmp_asm(env, &(*tree)->left, content, c_size);
	else if (CMP((char *)content, (char *)(*tree)->content) > 0)
		ft_btreecmp_asm(env, &(*tree)->right, content, c_size);
	else
	{
		env->error_int = 1;
		env->error_val = ft_strinit((char *)content);
	}
}

void				ft_btreedel_asm(t_btree_asm *tree)
{
	if (tree)
	{
		ft_btreedel_asm(tree->left);
		ft_btreedel_asm(tree->right);
		tree->content_size = 0;
		tree->line = 0;
		tree->left = NULL;
		tree->right = NULL;
		free(tree->content);
		free(tree);
		tree = NULL;
	}
}

void				ft_btreesearch_asm(t_btree_asm *node, char *content,
					int *ret)
{
	if (node)
	{
		if (CMP(node->content, content) > 0)
			ft_btreesearch_asm(node->left, content, ret);
		else if (CMP(node->content, content) < 0)
			ft_btreesearch_asm(node->right, content, ret);
		else
		{
			*ret = node->line;
			return ;
		}
	}
}

void				ft_btree_print_inorder_asm(t_btree_asm *node)
{
	if (node)
	{
		ft_btree_print_inorder_asm(node->left);
		ft_printf("[%d] : [%s]\n", node->line, node->content);
		ft_btree_print_inorder_asm(node->right);
	}
}
