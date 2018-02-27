/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_equality.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:48:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 17:33:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "libft.h"

static t_bool	sym_equ(void const *v_sym_1, void const *v_sym_2)
{
	return (v_sym_1 == v_sym_2);
}

t_bool			prod_are_identical(t_prod const *prod_1, t_prod const *prod_2)
{
	return (lst_equ(prod_1->sym_list, prod_2->sym_list, sym_equ));
}
