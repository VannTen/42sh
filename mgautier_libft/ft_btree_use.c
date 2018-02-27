/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:44:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/07 13:18:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_defs.h"
#include "btree_node_interface.h"
#include "custom_stddef.h"
#include <stddef.h>

void	btree_iter_in_order(t_btree *tree, t_iter f)
{
	if (tree != NULL)
		node_in_order_traversal(tree->root, f);
}

void	btree_iter_in_rev_order(t_btree *tree, t_iter f)
{
	if (tree != NULL)
		node_in_rev_order_traversal(tree->root, f);
}

void	btree_iter_two_param_in_order(t_btree *tree,
		t_iter_two f, void *param_supp)
{
	if (tree != NULL)
		node_in_order_two_param_traversal(tree->root, f, param_supp);
}

void	btree_iter_two_param_in_rev_order(t_btree *tree,
		t_iter_two f, void *param_supp)
{
	if (tree != NULL)
		node_in_rev_order_two_param_traversal(tree->root, f, param_supp);
}

int		btree_sum(t_btree *tree, t_sum add)
{
	if (tree != NULL)
		return (node_sum(tree->root, add));
	else
		return (-1);
}
