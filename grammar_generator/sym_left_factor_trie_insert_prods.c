/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_left_factor_trie_insert_prods.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:31:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/14 17:26:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_left_factor_compute_implem.h"
#include "sym_interface.h"
#include "prods_interface.h"
#include "libft.h"

/*
** Define the necessary methods for insertion in t_trie struct
** Wrapper function to have the proper signature to be used as function pointers
** arguments to trie_insert.
*/

static void const	*get_sym_of_prod_n(void const *prod, size_t const index)
{
	return (get_sym_of_prod(prod, index));
}

static t_bool	is_same_sym(void const *sym1, void const *sym2)
{
	return (symbol_are_identical(sym1, sym2));
}

t_bool		insert_in_trie(void *prod, va_list args)
{
	return (trie_insert(
				va_arg(args, t_trie*),
				prod,
				is_same_sym,
				get_sym_of_prod_n));
}
