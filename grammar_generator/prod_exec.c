/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:52:00 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 14:52:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"

static void		*copy(void const *src)
{
	return ((void*)src);
}

t_bool		add_prod_to_stack(t_prod const *prod, t_lst **stack)
{
	t_lst	*prod_dup;
	t_lst	*new_stack;

	prod_dup = f_lstmap(prod->sym_list, copy, no_destroy);
	new_stack = join_lst(prod_dup, *stack);
	if (new_stack != NULL
			|| (prod->sym_list == NULL
				&& *stack == NULL))
	{
		*stack = new_stack;
		return (TRUE);
	}
	else
		return (FALSE);
}
