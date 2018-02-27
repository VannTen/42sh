/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_compute_follow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:00:14 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 18:19:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"

/*
** variable sym_added is never_used, but lst_add_to_filter interface requires it.
*/

static t_bool	is_empty_first(t_lst const *lst)
{
	return (f_lst_len(lst) == 1
			&& get_lst_elem(lst, 0) == EMPTY_SYMBOL);
}

static void		*comp_sym_follow(void *sym, void *first_set_of_following)
{
	t_lst	*first_set_of_next;
	t_bool	sym_added;

	if (first_set_of_following == NULL)
		return (NULL);
	first_set_of_next = first_set_of_following;
	if (!is_empty_first(first_set_of_next) && !is_terminal(sym))
	{
		if (!add_set_to_follow_set(sym, first_set_of_next, &sym_added))
			return (NULL);
	}
	if (!has_symbol_in_first(sym, EMPTY_SYMBOL))
	{
		f_lstdel(&first_set_of_next, no_destroy);
		if (NULL == f_lstpush(EMPTY_SYMBOL, &first_set_of_next))
			return (NULL);
	}
	return (lst_add_to_filter(
				&first_set_of_next, get_first_set(sym), &sym_added));
}

t_bool		compute_follow_prod(t_prod *prod)
{
	t_lst	*empty_lst;

	empty_lst = NULL;
	if (NULL == f_lstpush(EMPTY_SYMBOL, &empty_lst))
		return (FALSE);
	empty_lst = lst_do_from_end(prod->sym_list, empty_lst, comp_sym_follow);
	if (empty_lst == NULL)
		return (FALSE);
	else
	{
		f_lstdel(&empty_lst, no_destroy);
		return (TRUE);
	}
}

static void	*sym_add_follow_parent(void *sym, void *prev_result, va_list args)
{
	t_bool			*sym_added;
	t_symbol const	*parent_sym;

	if (EMPTY_SYMBOL == prev_result)
	{
		parent_sym = va_arg(args, t_symbol const*);
		sym_added = va_arg(args, t_bool*);
		if (!add_set_to_follow_set(sym, get_follow_set(parent_sym), sym_added))
			return (NULL);
		else if (!has_symbol_in_first(sym, EMPTY_SYMBOL))
			return (sym);
	}
	return (prev_result);
}

t_bool		compute_follow_prod_step_3(
		t_prod *prod, t_symbol const *parent_sym, t_bool *sym_added)
{
	return (NULL != lst_do_from_end_va(prod->sym_list,
				(void*)EMPTY_SYMBOL,
				sym_add_follow_parent,
				parent_sym, sym_added));
}

/*
** EMPTY_SYMBOL as second parameter is a check to control whether
** sym_add_follow_parent continue or just return.
**
** With a prod A -> aBCy. If FIRST(y) contains EMPTY_SYMBOL, FIRST(Cy) can, if
** not, it can't. sym_add_follow_parent reproduces that by passing to the
** previous item in the list only if :
** -1 its previous iteration did not modify prev_result
** -2 it has EMPTY_SYMBOL in the current symbol
*/

