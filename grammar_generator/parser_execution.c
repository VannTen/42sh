/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:15:02 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 11:15:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_defs.h"
#include "grammar_interface.h"
#include "sym_interface.h"
#include "prods_interface.h"
#include "exec_construct_interface.h"
#include <unistd.h>
#include <assert.h>

static t_bool		token_transition(
		t_symbol const *token,
		struct s_parse_state *state,
		size_t const token_id,
		t_exec const *functions)
{
	return(get_token_id(token) == token_id
			&& put_token_in_stack(state->token, &state->exec_stack,
				functions));
}

static t_bool		non_terminal_transition(
		t_symbol const *sym,
		struct s_parse_state *state,
		size_t const token_id,
		t_exec const *functions)
{
	t_prod const	*derivation;

	derivation = get_prod_for_token(sym, token_id);
	return (derivation != NULL
			&& add_prod_to_stack(
				derivation,
				&state->parse_stack)
			&& put_sym_in_stack(
				&state->exec_stack,
				functions,
				get_prod_len(derivation)));
}

static t_bool		one_symbol_transition(
		struct s_parse_state *state,
		struct s_input const *token_flow,
		size_t (*get_token_id)(void const *token))
{
	t_symbol const	*sym;
	t_bool			result;
	t_bool			(*transition)(t_symbol const*,
			struct s_parse_state*, size_t, t_exec const*);

	sym = f_lstpop(&state->parse_stack);
	if (state->token == NULL)
		state->token = token_flow->get_token(token_flow->input);
	transition = is_terminal(sym) ? token_transition : non_terminal_transition;
	result = state->token != NULL
		&& transition(sym, state,
				get_token_id(state->token),
				get_exec_functions(sym));
	if (result && is_terminal(sym))
		token_flow->del_token(&state->token);
	return (result);
}

static t_bool	init(
		t_lst **parse_stack,
		char const *construct,
		t_grammar const *gram)
{
	t_symbol const	*end_of_input;
	t_symbol const	*initial_symbol;

	initial_symbol = find_sym_by_name(gram, construct);
	end_of_input = find_sym_by_name(gram, "END_OF_INPUT");
	assert(initial_symbol != NULL && end_of_input != NULL);
	if (NULL == f_lstpush(end_of_input, parse_stack)
			|| NULL == f_lstpush(initial_symbol, parse_stack))
		f_lstdel(parse_stack, no_destroy);
	return (*parse_stack != NULL);
}

void		*execute_construct(
		t_parser const *parser,
		char const *construct,
		struct s_input const *input)
{
	struct s_parse_state	state;
	t_exec_construct		*meta_construct;

	state.token = NULL;
	state.parse_stack = NULL;
	state.exec_stack = NULL;
	meta_construct = create_init_meta_construct();
	(void)f_lstpush(meta_construct, &state.exec_stack);
	if (init(&state.parse_stack, construct, parser->grammar))
	{
		while (state.parse_stack != NULL)
		{
			if (!one_symbol_transition(&state,
						input,
						parser->get_token_id))
			{
				ft_dprintf(STDERR_FILENO, "Syntax error\n");
				f_lstdel(&state.parse_stack, no_destroy);
				f_lstdel(&state.exec_stack, clean_exec_struct);
				break ;
			}
		}
	}
	input->del_token(&state.token);
	return (extract_top_symbol_value(&meta_construct));
}

/*
** Debug
*/

static void	print_sym(void *sym)
{
	ft_dprintf(STDERR_FILENO, "%s\n", get_name(sym));
}

void	print_token(void const *token, t_parser const *parser)
{
	ft_dprintf(STDERR_FILENO, "%zu\n", parser->get_token_id(token));
}
void	print_stack(t_lst *stack)
{
	f_lstiter(stack, print_sym);
}
