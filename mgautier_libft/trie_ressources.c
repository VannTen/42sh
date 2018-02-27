/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:26:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/13 11:56:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_defs.h"
#include "lst_interface.h"
#include <stdlib.h>

t_trie		*create_node(void const *ref_elem)
{
	t_trie	*new_node;

	new_node = malloc(sizeof(t_trie));
	if (new_node != NULL)
	{
		new_node->children = NULL;
		new_node->content.ref = ref_elem;
	}
	return (new_node);
}

t_trie		*create_trie(void)
{
	return (create_node(NULL));
}

static void	sub_del(void **trie, void (*del)(void**))
{
	destroy_trie((t_trie**)trie, del);
}

void		destroy_trie(t_trie **del_trie, void (*del)(void**))
{
	t_trie	*trie;

	trie = *del_trie;
	if (trie != NULL)
	{
		if (trie->children == NULL)
			del(&trie->content.data);
		else
		{
			f_lstdel_set(&trie->children, sub_del, del);
			trie->content.ref = NULL;
			trie->children = NULL;
		}
		free(trie);
		*del_trie = NULL;
	}
}
