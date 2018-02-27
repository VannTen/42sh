/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:00:13 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 18:00:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_defs.h"
#include "grammar_interface.h"
#include <assert.h>

static t_bool	create_symbols_have_destructor(t_exec const *sym_rules)
{
	size_t	index;

	index = 0;
	while (sym_rules[index].create != NULL && sym_rules[index].destroy != NULL)
		index++;
	return (sym_rules[index].create == NULL);
}

t_parser	*generate_parser(
		char const *grammar,
		char const **tokens_names,
		t_exec const *rules,
		size_t (*get_token_id)(void const *token))
{
	t_parser	*new_parser;

	assert(create_symbols_have_destructor(rules));
	new_parser = malloc(sizeof(*new_parser));
	if (new_parser != NULL)
	{
		new_parser->grammar = parse_grammar_string(grammar);
		new_parser->tokens = create_tokens_table(tokens_names, new_parser->grammar);
		if (new_parser->grammar == NULL || new_parser->tokens == NULL
				|| !eliminate_all_left_recursion(new_parser->grammar)
				|| !left_factor_grammar(new_parser->grammar)
				|| !compute_first_grammar(new_parser->grammar)
				|| !compute_follow_grammar(new_parser->grammar)
				|| !compute_parsing_table(new_parser->grammar, tokens_names)
				|| !associate_exec_functions(new_parser->grammar, rules))
			destroy_parser(&new_parser);
		else
		{
			new_parser->get_token_id = get_token_id;
			(void)rules;
		}

	}
	return (new_parser);
}

void		destroy_parser(t_parser **parser)
{
	t_parser	*to_destroy;

	to_destroy = *parser;
	if (to_destroy != NULL)
	{
		destroy_grammar(&to_destroy->grammar);
		free(to_destroy->tokens);
		free(to_destroy);
		*parser = NULL;
	}
}
