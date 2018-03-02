/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_node_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:15:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 16:44:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_node_defs.h"
#include <stddef.h>

static const void	*insert_left(struct s_node *node, const void *content,
		t_compare comp)
{
	if (node->left == NULL)
	{
		node->left = node_create();
		if (node->left != NULL)
		{
			node->left->content = (void*)content;
			return (NULL);
		}
		else
			return (content);
	}
	else
		return (insert_node(node->left, content, comp));
}

static const void	*insert_right(struct s_node *node, const void *content,
		t_compare comp)
{
	if (node->right == NULL)
	{
		node->right = node_create();
		if (node->right != NULL)
		{
			node->right->content = (void*)content;
			return (NULL);
		}
		else
			return (content);
	}
	else
		return (insert_node(node->right, content, comp));
}

const void			*insert_node(struct s_node *node, const void *content,
		t_compare comp)
{
	int	comp_result;

	comp_result = comp(content, node->content);
	if (comp_result < 0)
		return (insert_left(node, content, comp));
	else
		return (insert_right(node, content, comp));
}

struct s_node		*insert_root(const void *content)
{
	struct s_node	*root;

	root = node_create();
	if (root != NULL)
		root->content = (void*)content;
	return (root);
}
