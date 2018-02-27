/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:53:59 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 13:00:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"

static t_bool	equ(void const *sym_1, void const *sym_2)
{
	return (ft_strequ(get_name(sym_1), get_name(sym_2)));
}

t_bool			prod_are_equ(t_prod const *prod_1, t_prod const *prod_2)
{
	return (lst_equ(prod_1->sym_list, prod_2->sym_list, equ));
}
