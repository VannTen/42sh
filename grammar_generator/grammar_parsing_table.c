/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parsing_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:32:37 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 18:32:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include <stddef.h>

static t_bool	init_parse_row(void *sym, va_list args)
{
	return (init_sym_parse_table(sym, va_arg(args, size_t)));
}

static t_bool	fill_parse_row(void *sym, va_list args)
{
	return (fill_sym_parse_table(sym, va_arg(args, char const**)));
}

t_bool			compute_parsing_table(
		t_grammar *gram, char const **tokens_names)
{
	return (f_fifoiterr_va(gram->sym_list,
				init_parse_row, ft_string_array_count(tokens_names) + 1)
			&& f_fifoiterr_va(gram->sym_list,
				fill_parse_row, tokens_names));
}

void const	**create_tokens_table(
		char const **tokens_name,
		t_grammar const *gram)
{
	size_t		index;
	void const	**tokens_table;

	index = ft_string_array_count(tokens_name) + 1;
	tokens_table = malloc(sizeof(*tokens_table) * index);
	if (tokens_table != NULL)
	{
		index = 0;
		while (tokens_name[index] != NULL)
		{
			tokens_table[index] = find_sym_by_name(gram, tokens_name[index]);
			if (tokens_table[index] == NULL)
			{
				free(tokens_table);
				tokens_table = NULL;
				return (tokens_table);
			}
			else
				set_token_id((void*)tokens_table[index], index);
			index++;
		}
		tokens_table[index] = find_sym_by_name(gram, "END_OF_INPUT");
		set_token_id((void*)tokens_table[index], index);
	}
	return (tokens_table);
}
