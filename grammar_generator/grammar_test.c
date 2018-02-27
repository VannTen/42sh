/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:09:14 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 18:41:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <assert.h>

static t_bool	va_is_terminal(void const *sym,
		__attribute__((unused))va_list args)
{
	assert(sym != NULL);
	return (is_terminal(sym));
}

t_bool	symbols_are_valid(t_grammar const *gram)
{
	assert(gram != NULL);
	return (NULL == f_fifo_every_valid_va(gram->sym_list, FALSE, va_is_terminal)
			&& NULL == f_fifo_every_valid_va(
				gram->tokens_list, TRUE, va_is_terminal));
}
