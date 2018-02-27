/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_follow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:19:23 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 18:35:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"

/*
** Dummy never used, for lib function.
*/

static t_bool	add_set_follow(void const *sym_to_add, va_list args)
{
	t_bool		*sym_is_added;
	t_symbol	*add_to_sym;

	if (sym_to_add != EMPTY_SYMBOL)
	{
		add_to_sym = va_arg(args, t_symbol*);
		sym_is_added = va_arg(args, t_bool*);
		return (add_one_to_follow(add_to_sym, sym_to_add, sym_is_added));
	}
	else
		return (TRUE);
}

t_bool			add_set_to_follow_set(
		t_symbol *sym, t_lst const *set_to_add, t_bool *sym_is_added)
{
	return (f_lstiterr_va_const(set_to_add,
				add_set_follow, sym, sym_is_added));
}

t_bool			add_one_to_follow(
		t_symbol *add_to,
		t_symbol const *sym,
		t_bool *sym_added)
{
	if (!has_symbol_in_follow(add_to, sym))
	{
		*sym_added = TRUE;
		return (NULL != f_lstpush(sym, &add_to->follow));
	}
	else
		return (TRUE);
}

static t_bool	prod_follow(void *prod)
{
	return (compute_follow_prod(prod));
}

t_bool			compute_follow_from_first_in_sym(t_symbol *sym)
{
	return (f_lstiterr(sym->prods, prod_follow));
}


static t_bool	prod_va(void *prod, va_list args)
{
	t_bool		*sym_added;
	t_symbol	*sym;

	sym = va_arg(args, t_symbol*);
	sym_added = va_arg(args, t_bool*);
	return (compute_follow_prod_step_3(prod, sym, sym_added));
}

t_bool			compute_follow_sym_step_3(t_symbol *sym, t_bool *sym_added)
{
	return (f_lstiterr_va(sym->prods, prod_va, sym, sym_added));
}
