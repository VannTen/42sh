/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:34:33 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 13:30:39 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_DEFS_H
# define TRIE_DEFS_H
# include "trie_interface.h"
# include "lst_interface.h"

/*
** children: the list contains children nodes (struct s_trie*)
** content is different based on whether it is a leaf or a node.
** If it is a leaf, content holds data.
** If it is a node, content holds a ref to the last item common to all its
** children (and following up, to all its descendant). That ref actually points
** to any of the instance present in the tree, thus it has to be updated if one
** the children is removed of the tree.
*/

/*
** Internals functions for implementation.
*/

/*
** Node creation.
** Implementation file : trie_ressources.c
*/

struct		s_trie
{
	union	u_trie_content
	{
		void const	*ref;
		void		*data;
	}		content;
	t_lst	*children;
};

t_trie		*create_node(void const *ref_elem);

#endif
