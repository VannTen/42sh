/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_first2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:56:38 by heynard           #+#    #+#             */
/*   Updated: 2018/03/02 18:00:21 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"

static t_bool	add_symbol(void *sym_to_add, va_list args)
{
	t_lst	**add_to_set;
	t_bool	*sym_added;

	add_to_set = va_arg(args, t_lst**);
	sym_added = va_arg(args, t_bool*);
	return (sym_to_add != EMPTY_SYMBOL ?
			add_symbol_to_set(sym_to_add, add_to_set, sym_added) :
			TRUE);
}

t_bool			add_first_set_to_set(
					t_symbol const *sym,
					t_lst **add_to,
					t_bool *sym_added)
{
	return (f_lstiterr_va(sym->first, add_symbol, add_to, sym_added));
}

t_bool			add_symbol_to_first_set(
					t_symbol const *sym,
					t_symbol *add_to,
					t_bool *sym_added)
{
	return (add_symbol_to_set(sym, &add_to->first, sym_added));
}
