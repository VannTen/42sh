/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interface.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:12:51 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 15:12:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERFACE_H
# define PARSER_INTERFACE_H
# include "exec_interface.h"
# include <stddef.h>

typedef struct s_parser	t_parser;

/*
** Parser generation
*/

t_parser	*generate_parser(
		char const *grammar,
		char const **tokens_names,
		t_exec const *rules,
		size_t (*get_token_id)(void const *token));
void		destroy_parser(t_parser **parser);

/*
** Parser execution
*/

struct	s_input
{
	void	*input;
	void	*(*get_token)(void *input);
	void	(*del_token)(void **token);
};

void		*execute_construct(
		t_parser const *parser,
		char const *construct,
		struct s_input const *input);

/*
** *** generate_parser ***
**
** 'grammar'
** is a string defining symbols in this form :
** "SYM: <prod> [ | <prod> ...];".
** Each <prod> is a space separated string of symbols name, possibly empty
** ("SYM_1 SYM_2 SYM_2").
** charset for symbol names : [A-Z_].
**
** tokens_names
** is a NULL-terminated array of strings, which are the tokens
** names (used in the grammar) that the tokenizer will use.
**
** get_token_id
** function, when called with a token obtained from get_token
** (below) shall return the same index where that token name is place in
** 'tokens_names'. It shall return the size of the array (the last index + 1)
** when used on the symbol representing the end of the input.
**
** rules
** shall define array of t_associate struct, exposed in this interface.
** The caller shall provide an entry in this array for each grammar construct
** which has a corresponding task to be achieved during execution.
** it shall end with a t_associate struct containing NULL in its .name member.
**
** The behavior is slighty different for terminal and non-terminals
**
** terminals :
** - create will be called when the token is consummed, with the
** return of the function get_token (below) as argument.
** - give will never be called, and expected to be NULL.
**
** non-terminals :
** - create will be called when the symbol is derived in on of its production,
** with NULL as argument.
** - give will be called each time a symbol which have a create method finish to
** be parsed (for a terminal, as soon as it is created, for a non-terminal, once
** the parser has consummed all terminals derived from it). The first argument
** is the symbol being parsed, the second the one that just terminated.
**
** A symbol will only be given to its immediated ancestor (aka, the one which
** has produced him during derivation).
**
** grammar symbols which does not have a create method (and therefore, neither a
** give method) are considered to be only syntaxic, that serve to organize the
** others.
**
** *** execute_construct ***
**
** parser
**
** t_parser returned by generate_parser.
**
** construct
** name of the construct the the parser is supposed to begin at. Most of the
** time, it shall be the start symbol of the grammar.
**
** get_token && input.
**
** The parser will call 'get_token(input)' each time it needs to obtain a new
** token.
**
** That function returns the return of the create function for the symbol which
** has been given as 'construct', after it has finish to parse it. (in the same
** way that it gives to the parent construct with 'give' function).
** It returns NULL on a syntax error.
**
** (No diagnostics messages for now).
*/

#endif
