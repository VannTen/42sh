/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_left_factor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:07:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/05 16:15:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"

static void		sym_del(void **sym)
{
	destroy_symbol((t_symbol**)sym);
}

static t_bool	lfactor_sym(void *sym, va_list args)
{
	return (left_factor_sym(sym, va_arg(args,t_fifo*)));
}

t_bool			left_factor_grammar(t_grammar *gram)
{
	t_fifo	*new_syms;

	new_syms = f_fifo_create();
	if (new_syms != NULL
			&& f_fifoiterr_va(gram->sym_list, lfactor_sym, new_syms))
	{
		join_fifo(gram->sym_list, new_syms);
		return (TRUE);
	}
	else
	{
		f_fifo_destroy(&new_syms, sym_del);
		return (FALSE);
	}
}
