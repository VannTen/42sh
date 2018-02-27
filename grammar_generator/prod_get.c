/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:22:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/13 19:26:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include <stddef.h>

size_t		get_prod_len(t_prod const *prod)
{
	return (f_lst_len(prod->sym_list));
}

const char	*get_sym_name_n(t_prod const *prod, size_t index)
{
	t_symbol const	*sym;

	sym = get_sym_of_prod(prod, index);
	return (sym != NULL ? get_name(sym) : NULL);
}

void const	*get_sym_of_prod(t_prod const *prod, size_t const index)
{
	return (get_lst_elem(prod->sym_list, index));
}
