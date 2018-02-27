/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_first_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:36:29 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 19:36:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include "libft.h"

t_bool		empty_in_sym_first(void const *sym, __attribute__((unused))va_list args)
{

	if (!has_symbol_in_first(sym, EMPTY_SYMBOL))
	{
		(void)va_arg(args, t_lst**);
		*(va_arg(args, t_bool*))= FALSE;
		return (FALSE);
	}
	else
		return (TRUE);

}

t_bool		add_to_prod_first_set(void *sym, va_list args)
{
	t_bool	__attribute__((unused))sym_added;

	return (add_first_set_to_set(sym, va_arg(args, t_lst**), &sym_added));
}

t_lst		*create_first_set_prod(t_prod const *prod)
{
	t_lst	*prod_first_set;
	t_bool	empty_in_first;
	t_bool	result;

	prod_first_set = NULL;
	empty_in_first = TRUE;
	result = lst_do_while_err_va(prod->sym_list,
			add_to_prod_first_set,
			empty_in_sym_first, &prod_first_set, &empty_in_first);
	if (empty_in_first && result)
		result = NULL != f_lstpush(EMPTY_SYMBOL, &prod_first_set);
	if (!result)
		f_lstdel(&prod_first_set, no_destroy);
	return (prod_first_set);
}
