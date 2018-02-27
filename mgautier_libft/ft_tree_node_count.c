/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_node_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:40:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/06 17:53:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_node_defs.h"
#include "custom_stddef.h"
#include <stddef.h>

int	node_sum(struct s_node *node, t_sum add)
{
	if (node == NULL)
		return (0);
	else
		return (add(node->content) +
				node_sum(node->left, add) +
				node_sum(node->right, add));
}
