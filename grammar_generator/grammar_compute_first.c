/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_compute_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:46:43 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/10 19:40:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"

static t_bool	compute_sym_first(void *sym, va_list args)
{
	return (compute_sym_first_set(sym, va_arg(args, t_bool*)));
}

t_bool	compute_first_grammar(t_grammar *grammar)
{
	t_bool	sym_added;

	sym_added = TRUE;
	if (!f_fifoiterr_va(grammar->tokens_list, compute_sym_first, &sym_added))
		return (FALSE);
	while (sym_added)
	{
		sym_added = FALSE;
		if (!f_fifoiterr_va(grammar->sym_list,
				compute_sym_first, &sym_added))
			return (FALSE);
	}
	return (TRUE);
}

