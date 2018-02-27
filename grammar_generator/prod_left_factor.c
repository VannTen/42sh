/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_left_factor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:28:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/21 15:29:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include "left_factor_implem.h"

static t_bool	cut_prod_past_n(void *prod, va_list args)
{
	remove_symbols_head(prod, va_arg(args, size_t));
	return (TRUE);
}

static t_bool	add_to_new_sym(void *prod, va_list args)
{
	return (NULL == add_prod(va_arg(args, t_symbol*), prod));
}

t_prod			*prod_group_left_factor(t_lst *prods, size_t const index,
		t_left_fac *ref_sym)
{
	t_prod		*common_prefix;
	t_symbol	*lfac_sym;
	char		*derivate;

	common_prefix = dup_prod(get_lst_elem(prods, 0));
	remove_symbols_tail(common_prefix, get_prod_len(common_prefix) - index);
	f_lstiterr_va(prods, cut_prod_past_n, index);
	ft_asprintf(&derivate, "%zu%s", ref_sym->index, LEFT_FAC_SUFFIX);
	lfac_sym = derivate_new_sym(ref_sym->sym, derivate);
	ft_strdel(&derivate);
	f_lstiterr_va(prods, add_to_new_sym, lfac_sym);
	f_lstdel(&prods, no_destroy);
	ref_sym->index++;
	append_to_prod(common_prefix, lfac_sym);
	f_lstpush(lfac_sym, &ref_sym->sym_left_factored);
	return (common_prefix);
}
