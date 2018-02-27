/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:14:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/24 12:59:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <assert.h>

size_t			terminal_sym_count(t_grammar const *gram)
{
	assert(gram != NULL);
	return (fifo_len(gram->tokens_list));
}

size_t			non_terminal_sym_count(t_grammar const *gram)
{
	assert(gram != NULL);
	return (fifo_len(gram->sym_list));
}

t_symbol const	*get_start_symbol(t_grammar const *gram)
{
	assert(gram != NULL);
	return (get_fifo_elem(gram->sym_list, 0));
}

static t_bool	same_name(void const *sym, va_list arg)
{
	return (ft_strequ(get_name(sym), va_arg(arg, char const*)));
}

t_symbol		*find_sym_by_name(t_grammar const *gram, char const *sym_name)
{
	t_symbol	*sym;

	sym = f_fifo_every_valid_va(gram->tokens_list, FALSE, same_name, sym_name);
	if (sym == NULL)
		sym =
			f_fifo_every_valid_va(gram->sym_list, FALSE, same_name, sym_name);
	return (sym);
}
