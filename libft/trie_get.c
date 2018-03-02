/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:15:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/13 14:26:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_defs.h"
#include <stddef.h>
#include <stdarg.h>

static void	max_intern(void const *v_trie, va_list args)
{
	size_t			*glob_max;
	size_t			current_depth;
	t_trie const	*trie;

	trie = v_trie;
	glob_max = va_arg(args, size_t*);
	current_depth = va_arg(args, size_t);
	f_lstiter_va(trie->children, max_intern, glob_max, current_depth + 1);
	if (current_depth > *glob_max && f_lst_len(trie->children) >= 2)
		*glob_max = current_depth;
}

size_t		max_common_prefix(t_trie const *trie)
{
	size_t	max;

	max = 0;
	f_lstiter_va(trie->children, max_intern, &max, 1);
	return (max);
}

static void	f_count(void const *v_trie, va_list args)
{
	t_trie const	*trie;
	size_t			*count;

	trie = v_trie;
	count = va_arg(args, size_t*);
	if (trie->children == NULL)
		(*count)++;
	else
		f_lstiter_va(trie->children, f_count, count);
}

size_t		trie_count_members(t_trie const *trie)
{
	size_t	count;

	count = 0;
	f_lstiter_va(trie->children, f_count, &count);
	return (count);
}
