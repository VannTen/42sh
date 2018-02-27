/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_left_factor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:38:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/21 15:53:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "sym_left_factor_implem.h"
#include "left_factor_implem.h"
#include "libft.h"

static void		iter_del_list_prods(void **list_prods)
{
	f_lstdel((t_lst**)list_prods, iter_del_prod);
}

t_bool			left_factor_sym(t_symbol *sym, t_fifo *new_syms)
{
	t_lst	*new_prods;
	t_lst	*derived_syms;

	derived_syms = NULL;
	new_prods = sym_left_factor_compute(sym, &derived_syms);
	if (new_prods != NULL)
	{
		if (derived_syms != NULL)
		{
			f_lstdel(&sym->prods, iter_del_prod);
			sym->prods = f_lstpop(&new_prods);
			add_lst_to_fifo(new_syms, derived_syms);
			f_lstdel(&new_prods, no_destroy);
		}
		else
			f_lstdel(&new_prods, iter_del_list_prods);
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool			is_result_of_left_factor(t_symbol const *sym)
{
	return (NULL != ft_strstr(sym->name, LEFT_FAC_SUFFIX));
}
