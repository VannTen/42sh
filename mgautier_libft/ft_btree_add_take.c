/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add_take.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:17:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 18:11:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_defs.h"
#include "btree_node_interface.h"
#include <stddef.h>

const void	*btree_add(t_btree *tree, const void *content)
{
	if (tree == NULL)
		return (content);
	if (tree->root != NULL)
	{
		if (content != insert_node(tree->root, content, tree->f_comp))
		{
			tree->count++;
			return (NULL);
		}
		else
			return (NULL);
	}
	else
	{
		tree->root = insert_root(content);
		if (tree->root == NULL)
			return (content);
		else
		{
			tree->count++;
			return (NULL);
		}
	}
}

int			btree_count(t_btree *tree)
{
	return (tree != NULL ? tree->count : -1);
}
