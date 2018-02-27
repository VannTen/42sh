/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_compute_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:42:31 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/05 12:17:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include "libft.h"

static t_bool	add_first_and_has_not_empty(void const *sym, va_list arg)
{
	t_symbol	*add_to;
	t_bool		*error_occurred;
	t_bool		*sym_added;

	add_to = va_arg(arg, t_symbol*);
	error_occurred = va_arg(arg, t_bool*);
	sym_added = va_arg(arg, t_bool*);
	*error_occurred = !add_first_set_to_first_set(sym, add_to, sym_added);
	return (has_symbol_in_first(sym, EMPTY_SYMBOL));
}

t_bool		add_firsts_of_sub_symbols(
		t_prod const *prod,
		t_symbol *add_to,
		t_bool *sym_added)
{
	t_symbol	*last_first_set_to_add;
	t_bool		error_occurred;

	error_occurred = FALSE;
	last_first_set_to_add = f_lst_every_valid_va(prod->sym_list,
			TRUE,
			add_first_and_has_not_empty, add_to, &error_occurred, sym_added);
	if (!error_occurred)
	{
		if (last_first_set_to_add == NULL)
			add_symbol_to_first_set(EMPTY_SYMBOL, add_to, sym_added);
	}
	return (!error_occurred);
}
