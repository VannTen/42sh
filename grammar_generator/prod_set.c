/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:15:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 15:26:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include <stdlib.h>

t_bool	append_to_prod(t_prod *prod, t_symbol const *type)
{
	return (NULL == f_pushend_lst(&prod->sym_list, (t_symbol*)type));
}

t_bool	prefix_to_prod(t_prod *prod, t_symbol const *type)
{
	return (NULL != f_lstpush(type, &prod->sym_list));
}

t_prod	*join_prods(t_prod const *prod_1, t_prod const *prod_2)
{
	t_prod	*new_prod;
	t_lst	*new_sym_list;

	new_sym_list = lst_join(prod_1->sym_list, prod_2->sym_list);
	new_prod = create_prod();
	if (new_prod != NULL
			&& (new_sym_list != NULL
			|| (prod_1->sym_list == NULL && prod_2->sym_list == NULL)))
		new_prod->sym_list = new_sym_list;
	else
	{
		f_lstdel(&new_sym_list, no_destroy);
		destroy_prod(&new_prod);
	}
	return (new_prod);
}

void	remove_symbols_tail(t_prod *prod, size_t nb_sym)
{
	while (nb_sym != 0 && NULL != f_popend_lst(&prod->sym_list))
		nb_sym--;
}

void	remove_symbols_head(t_prod *prod, size_t nb_sym)
{
	while (nb_sym != 0 && NULL != f_lstpop(&prod->sym_list))
		nb_sym--;
}
