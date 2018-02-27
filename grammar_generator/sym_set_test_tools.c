/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set_test_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 23:52:41 by mgautier          #+#    #+#             */
/*   Updated: 2018/02/01 23:52:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "libft.h"
#include "test_interface.h"

static t_bool	compute_sym_first(void *sym, va_list args)
{
	return (compute_sym_first_set(sym, va_arg(args, t_bool*)));
}

static t_bool	follow_from_first(void *sym)
{
	return (compute_follow_from_first_in_sym(sym));
}

static t_bool	follow_from_follow(void *sym, va_list args)
{
	return (compute_follow_sym_step_3(sym, va_arg(args, t_bool*)));
}

t_bool	compute_sets_all_syms(t_fifo *tokens, t_fifo *sym)
{
	t_bool	sym_added;

	sym_added = TRUE;
	if (!f_fifoiterr_va(tokens, compute_sym_first, &sym_added))
		return (FALSE);
	while (sym_added)
	{
		sym_added = FALSE;
		if (!f_fifoiterr_va(sym, compute_sym_first, &sym_added))
			return (FALSE);
	}
	sym_added = TRUE;
	if (add_one_to_follow((void*)get_fifo_elem(sym, 0),
				(void*)get_fifo_elem(tokens, 0), &sym_added))
	{
		if (f_fifoiterr(sym, follow_from_first))
		{
			while (f_fifoiterr_va(sym,
						follow_from_follow, &sym_added)
					&& sym_added)
				sym_added = FALSE;
			return (!sym_added);
		}
	}
	return (FALSE);
}
