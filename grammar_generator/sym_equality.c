/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_equality.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:58:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 17:57:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"

t_bool			symbol_are_identical(t_symbol const *sym_1,
		t_symbol const *sym_2)
{
	return (sym_1 == sym_2);
}

t_bool			same_sym_parsed(const void *v_sym, va_list args)
{
	t_symbol const	*sym;

	sym = v_sym;
	return (ft_strequ(get_name(sym), va_arg(args, char const *)));
}

static t_bool	prod_equ(void const *prod_1, void const *prod_2)
{
	return (prod_are_identical(prod_1, prod_2));
}

t_bool			have_same_prods(t_symbol const *sym_1, t_symbol const *sym_2)
{
	return (lst_equ(sym_1->prods, sym_2->prods, prod_equ));
}
