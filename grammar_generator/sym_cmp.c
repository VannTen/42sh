/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:49:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 16:58:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include "libft.h"

static t_bool	equ(void const *prod_1, void const *prod_2)
{
	return (prod_are_equ(prod_1, prod_2));
}

t_bool			sym_are_equ(t_symbol const *sym_1, t_symbol const *sym_2)
{
	return (ft_strequ(sym_1->name, sym_2->name)
			&& prods_are_equ(sym_1, sym_2));
}

t_bool			prods_are_equ(t_symbol const *sym_1, t_symbol const *sym_2)
{
	return (lst_same_contents(sym_1->prods, sym_2->prods, equ));
}
