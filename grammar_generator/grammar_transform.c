/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:00:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 18:28:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include <stdarg.h>

static t_bool	dev_prev_symbol(void *prev_sym, va_list args)
{
	t_symbol	*current_sym;
	t_bool		*error_occured;

	current_sym = va_arg(args, t_symbol*);
	error_occured = va_arg(args, t_bool*);
	if (prev_sym == current_sym)
		return (FALSE);
	else if (!elim_indirect_left_recursion(current_sym, prev_sym, FALSE))
		*error_occured = TRUE;
	return (!(*error_occured));
}

static t_bool	elim_lrecur(void *sym, va_list args)
{
	t_bool		error;
	t_symbol	*new_non_lrec_sym;
	t_fifo		*produced_syms;
	t_fifo		*sym_prev_list;

	error = FALSE;
	produced_syms = va_arg(args, t_fifo*);
	sym_prev_list = va_arg(args, t_fifo*);
	f_fifoiterr_va(sym_prev_list, dev_prev_symbol, sym, &error);
	if (!error)
	{
		new_non_lrec_sym = eliminate_left_recursion(sym);
		if (NULL != new_non_lrec_sym)
		{
			if (NULL == f_fifo_add(produced_syms, new_non_lrec_sym))
			{
				destroy_symbol(&new_non_lrec_sym);
				error = TRUE;
			}
		}
		else if (has_left_recursion(sym))
			error = TRUE;
	}
	return (!error);
}

t_bool			eliminate_all_left_recursion(t_grammar *gram)
{
	t_fifo	*produced_syms;

	produced_syms = f_fifo_create();
	if (produced_syms != NULL)
	{
		if (f_fifoiterr_va(gram->sym_list, elim_lrecur,
				produced_syms, gram->sym_list))
			gram->sym_list = join_fifo(gram->sym_list, produced_syms);
		return (TRUE);
	}
	return (FALSE);
}
