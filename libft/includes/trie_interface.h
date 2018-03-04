/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:49:56 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 12:14:07 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_INTERFACE_H
# define TRIE_INTERFACE_H

# include "bool_interface.h"
# include "lst_interface.h"

typedef	struct s_trie	t_trie;

/*
** The trie structure is a tree structure where each data is an ordered set of
** potentially common items ; for example, strings (where item are characaters).
** - data is stored in leaves
** - each node represents the prefix of all of its descendants
** - each subtree is the existing prefix for a given prefix
** - each cousins of a node represents a substring with exactly one characters
** that differ after the common prefix.
** - the depth of the node is equal to the length of the common prefix.
**
** Limits :
** - the structure can not handle identical content.
**
** TODO: Make this expose more understandable.
*/

/*
** Ressources
** Implementation file : trie_ressources.c
*/

t_trie					*create_trie(void);
void					destroy_trie(t_trie **trie, void (*del)(void**));

/*
** Insertion in the tree
** Implementation file : trie_insert.c
**
** The caller shall provides two function to trie_insert :
** - get_elem shall return the elem from a set at the specified index.
** - equ shall compare two elem (the return of get_elem) and return if they are
** equivalent for the purpose of the trie.
** special case : when ref is NULL,
** it shall return if elem is the 'end of set' - what that means is up to the
** caller.
*/

t_bool					trie_insert(
		t_trie *trie,
		void *content,
		t_bool (*equ)(
			void const *ref,
			void const *elem),
		void const *(get_elem)(void const *set, size_t index));

/*
** Produces a list of prefix groups. A prefix groups can include another.
** Implementation file : trie_list_prefix.c
*/

typedef struct			s_trie_ope
{
	void		*(*summarize)(t_lst *lst, size_t index, void *ext_ref);
	void		*(*copy)(const void *content);
	void		(*del)(void **);
	void		*ext_ref;
}						t_trie_ope;

t_lst					*list_prefix_groups(
		t_trie const *trie,
		t_trie_ope const *f);

/*
** Get trie characteristics
** Implementation file : trie_get.c
*/

size_t					max_common_prefix(t_trie const *trie);
size_t					trie_count_members(t_trie const *trie);

/*
** Debug print
** Implementation file trie_print.c
*/

void					print_node(int const fd,
		t_trie const *trie,
		void (*print_content)(int, void const *),
		void (*print_ref)(int, void const *));

#endif
