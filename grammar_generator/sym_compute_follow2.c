/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_follow2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:06:29 by heynard           #+#    #+#             */
/*   Updated: 2018/03/02 18:16:26 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"

t_bool			prod_follow(void *prod)
{
	return (compute_follow_prod(prod));
}

t_bool			compute_follow_from_first_in_sym(t_symbol *sym)
{
	return (f_lstiterr(sym->prods, prod_follow));
}

t_bool			prod_va(void *prod, va_list args)
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
