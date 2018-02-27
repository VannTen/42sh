/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_transform_indirect_lrec.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:59:29 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 16:52:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

/*
** Arguments are (in va_list for being able to be use a iterator):
**	t_symbol const *to_develop,
**	t_prod *prod,
**	t_lst **new_prods.
*/

static t_bool	produce_developed_prods(
		void *dev_symbol,
		va_list args)
{
	t_prod	*new_dev_prod;

	new_dev_prod = produce_developed_prod(
			(t_prod const *)dev_symbol,
			va_arg(args, t_prod const*));
	return (NULL != new_dev_prod
			&& NULL != f_fifo_add(va_arg(args, t_fifo*), new_dev_prod));
}

static t_bool	replace_sym_with_prods(
		void *prod,
		va_list args)
{
	t_symbol const	*sym;
	t_fifo			*new_prods;

	sym = va_arg(args, t_symbol const*);
	new_prods = va_arg(args, t_fifo*);
	remove_symbols_head(prod, 1);
	return (f_lstiterr_va(
				sym->prods,
				produce_developed_prods,
				prod,
				new_prods));
}

t_bool			elim_indirect_left_recursion(
		t_symbol *sym,
		t_symbol const *sym_indir,
		__attribute__((unused))t_bool dev_if_left)
{
	t_lst	*indirect_left_recur_prods;
	t_fifo	*new_prods;
	t_bool	success;

	new_prods = f_fifo_create();
	success = FALSE;
	if (new_prods != NULL)
	{
		indirect_left_recur_prods = f_split_lst_va(
				&sym->prods, TRUE, gen_prod_is_left_recursive, sym_indir);
		if (f_lstiterr_va(
					indirect_left_recur_prods, replace_sym_with_prods,
					sym_indir, new_prods))
		{
			sym->prods = join_lst(sym->prods, f_fifo_extract(&new_prods));
			success = TRUE;
		}
		else
			f_fifo_destroy(&new_prods, iter_del_prod);
		f_lstdel(&indirect_left_recur_prods, iter_del_prod);
	}
	return (success);
}
