/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_compute_follow.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:55:38 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/13 17:55:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include <assert.h>
#include <stdarg.h>

static t_bool	follow_from_first(void *sym)
{
	return (compute_follow_from_first_in_sym(sym));
}

static t_bool	follow_from_follow(void *sym, va_list args)
{
	return (compute_follow_sym_step_3(sym, va_arg(args, t_bool*)));
}

t_bool			compute_follow_grammar(t_grammar *grammar)
{
	t_bool			sym_added;
	t_symbol const	*end_of_input;

	sym_added = TRUE;
	end_of_input = find_sym_by_name(grammar, "END_OF_INPUT");
	assert(end_of_input != NULL);
	if (add_one_to_follow(grammar->start_symbol, end_of_input, &sym_added))
	{
		assert(sym_added);
		if (f_fifoiterr(grammar->sym_list, follow_from_first))
		{
			while (f_fifoiterr_va(grammar->sym_list,
						follow_from_follow, &sym_added)
					&& sym_added)
				sym_added = FALSE;
			return (!sym_added);
		}
	}
	return (FALSE);
}
