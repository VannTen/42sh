/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_left_factor_compute.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:02:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/21 15:52:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "sym_left_factor_compute_implem.h"
#include "sym_left_factor_implem.h"
#include "left_factor_implem.h"
#include "prods_interface.h"
#include "libft.h"

static void	*left_factor_prods(t_lst *prods, size_t const index,
		void *sym_ind)
{
	if (index == 0)
		return (NULL);
	return (prod_group_left_factor(prods, index, sym_ind));
}

static void		*s_dup_prod(void const *prod)
{
	return (dup_prod(prod));
}

t_lst			*sym_left_factor_compute(t_symbol const *sym,
		t_lst **derived_syms)
{
	t_trie		*trie;
	t_lst		*list_new_syms_prods;
	t_trie_ope	trie_ft;
	t_left_fac	sym_and_index;

	trie_ft.summarize = left_factor_prods;
	trie_ft.copy = s_dup_prod;
	trie_ft.del = iter_del_prod;
	trie_ft.ext_ref = &sym_and_index;
	sym_and_index.sym = sym;
	sym_and_index.index = 0;
	sym_and_index.sym_left_factored = NULL;
	trie = create_trie();
	if (trie != NULL
			&& f_lstiterr_va(sym->prods, insert_in_trie, trie))
		list_new_syms_prods = list_prefix_groups(trie, &trie_ft);
	else
		list_new_syms_prods = NULL;
	destroy_trie(&trie, no_destroy);
	*derived_syms = sym_and_index.sym_left_factored;
	return (list_new_syms_prods);
}
