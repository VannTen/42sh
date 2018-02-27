/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:53:15 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/03 18:45:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sym_defs.h"
#include <stdarg.h>

static t_bool	same_sym(void const *sym, va_list args)
{
	return (sym == va_arg(args, t_symbol const*));
}

t_bool			has_symbol_in_set(t_lst const *set, t_symbol const *to_find)
{
	return (NULL !=
			f_lst_every_valid_va(set, FALSE, same_sym, to_find));
}

t_bool			has_symbol_in_first(
		t_symbol const *search_in, t_symbol const *to_find)
{
	return (has_symbol_in_set(search_in->first, to_find));
}

t_bool			has_symbol_in_follow(
		t_symbol const *search_in, t_symbol const *to_find)
{
	return (has_symbol_in_set(search_in->follow, to_find));
}

/*
** Used in debug.
*/

t_lst const		*get_first_set(t_symbol const *sym)
{
	return (sym->first);
}

t_lst const		*get_follow_set(t_symbol const *sym)
{
	return (sym->follow);
}
