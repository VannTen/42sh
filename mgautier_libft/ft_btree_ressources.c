/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_ressources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:50:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 18:09:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_defs.h"
#include "custom_stddef.h"
#include <stdlib.h>

t_btree	*btree_create(t_compare f_comp)
{
	t_btree	*new;

	new = NULL;
	if (f_comp != NULL)
	{
		new = malloc(sizeof(t_btree));
		if (new != NULL)
		{
			new->root = NULL;
			new->f_comp = f_comp;
			new->count = 0;
		}
	}
	return (new);
}

void	btree_destroy(t_btree **place_to_destroy, t_destroy content_destroy)
{
	t_btree *to_destroy;

	to_destroy = *place_to_destroy;
	if (to_destroy != NULL)
	{
		node_destroy(&to_destroy->root, content_destroy);
		to_destroy->root = NULL;
		to_destroy->f_comp = NULL;
	}
	free(to_destroy);
	*place_to_destroy = NULL;
}
