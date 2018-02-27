/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:58:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/13 11:53:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_defs.h"
#include "lst_interface.h"
#include <stdarg.h>
#include <stddef.h>
#include <assert.h>

static t_bool	have_common_prefix(void const *v_trie, va_list args)
{
	t_bool			(*equ)(void const*, void const*);
	void const		*elem_inserted;
	t_trie const	*trie;

	trie = v_trie;
	equ = va_arg(args, t_bool (*)(void const*, void const*));
	elem_inserted = va_arg(args, void const*);
	return (equ(trie->content.ref, elem_inserted));
}

static t_trie	*create_branch(
		void *content,
		t_bool (*equ)(void const *elem, void const *elem_2),
		void const *(*get_elem_from_set)(void const *, size_t),
		size_t depth)
{
	t_trie	*new_branch_root;
	t_trie	*longest_common_prefix;
	t_trie	*new_node;

	new_branch_root = NULL;
	while (TRUE)
	{
		new_node = create_node(get_elem_from_set(content, depth));
		if (new_branch_root == NULL)
			new_branch_root = new_node;
		else
			f_lstpush(new_node, &longest_common_prefix->children);
		longest_common_prefix = new_node;
		if (equ(NULL, get_elem_from_set(content, depth)))
			break ;
		depth++;
	}
	longest_common_prefix->content.data = content;
	return (new_branch_root);
}

t_bool			trie_insert(
		t_trie *common_sub_prefix,
		void *content,
		t_bool (*equ)(void const *elem, void const *elem_2),
		void const *(*get_elem_from_set)(void const *, size_t))
{
	t_trie	*longest_common_prefix;
	t_trie	*new_branch;
	size_t	depth;

	depth = 0;
	assert(common_sub_prefix != NULL);
	longest_common_prefix = common_sub_prefix;
	while (common_sub_prefix != NULL)
	{
		common_sub_prefix = f_lst_every_valid_va(
				common_sub_prefix->children, FALSE, have_common_prefix,
					equ, get_elem_from_set(content, depth));
		if (common_sub_prefix != NULL)
			longest_common_prefix = common_sub_prefix;
		depth++;
	}
	depth--;
	assert(depth == 0 || longest_common_prefix->children != NULL);
	new_branch = create_branch(content, equ, get_elem_from_set, depth);
	f_lstpush(new_branch, &longest_common_prefix->children);
	return (TRUE);
}
