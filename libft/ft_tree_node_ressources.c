/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_node_ressources.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:18:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 11:21:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_node_defs.h"
#include "custom_stddef.h"
#include <stdlib.h>

struct s_node	*node_create(void)
{
	struct s_node	*new;

	new = malloc(sizeof(struct s_node));
	if (new != NULL)
	{
		new->content = NULL;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}

void			node_destroy(struct s_node **where_to_destroy,
		t_destroy content_destroy)
{
	struct s_node	*to_destroy;

	to_destroy = *where_to_destroy;
	if (to_destroy != NULL)
	{
		content_destroy(&to_destroy->content);
		node_destroy(&to_destroy->left, content_destroy);
		node_destroy(&to_destroy->right, content_destroy);
		to_destroy->content = NULL;
		to_destroy->left = NULL;
		to_destroy->right = NULL;
	}
	free(to_destroy);
	*where_to_destroy = NULL;
}
