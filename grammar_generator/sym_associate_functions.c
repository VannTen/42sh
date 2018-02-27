/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_associate_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:43:20 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 15:43:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "grammar_interface.h"
#include "exec_interface.h"
#include <stddef.h>
#include <assert.h>

t_exec const	*get_exec_functions(t_symbol const *sym)
{
	return (sym->exec_functions);
}

t_bool			is_exec_construct(t_symbol const *sym)
{
	return (NULL != get_exec_functions(sym));
}

t_bool			associate_exec_functions(
		t_grammar const *grammar,
		t_exec const *rules)
{
	t_symbol	*sym;
	size_t		index;

	index = 0;
	while (rules[index].name != NULL)
	{
		sym = find_sym_by_name(grammar, rules[index].name);
		assert(sym != NULL);
		if (sym == NULL)
			break ;
		sym->exec_functions = &rules[index];
		index++;
	}
	return (rules[index].name == NULL);
}
