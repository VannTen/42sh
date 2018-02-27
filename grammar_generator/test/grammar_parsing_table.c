/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parsing_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:39:13 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 10:39:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "test_interface.h"

static char const	*g_tokens[] = {"C", "D", "E", "F", "A", "B", NULL};
static char const	*g_parse_row_check[][ARRAY_LENGTH(g_tokens)] = {
	{"SYM_2", NULL, "SYM_2", NULL, "SYM_3", NULL, "SYM_2"},
	{"C D", NULL, "E F", NULL, NULL, NULL, ""},
	{NULL, NULL, NULL, NULL, "A B", NULL, NULL}
};

static char const	g_grammar[] =
"SYM_1: SYM_3 | SYM_2;"
"SYM_2: C D | E F|;"
"SYM_3: A B";

static char const	*g_sym_names[] = {"SYM_1", "SYM_2", "SYM_3"};

static char const	*g_tokens_expr[] =
{"INTEGER", "LEFT_PAR", "RIGHT_PAR", "PLUS", "MULT", NULL};

static char const	*g_parse_row_check_expr[][ARRAY_LENGTH(g_tokens)] = {
	{"TERM EXPR_LREC", "TERM EXPR_LREC", NULL,
		NULL, NULL, NULL},
	{"FACTOR TERM_LREC", "FACTOR TERM_LREC", NULL,
		NULL, NULL, NULL},
	{"INTEGER", "LEFT_PAR EXPR RIGHT_PAR", NULL,
		NULL, NULL, NULL},
	{NULL , NULL, "",
		"PLUS TERM EXPR_LREC", NULL, ""},
	{NULL , NULL, "",
		"", "MULT FACTOR TERM_LREC", ""}
};

static char const	g_grammar_expr[] =
"EXPR: TERM EXPR_LREC;"
"TERM: FACTOR TERM_LREC;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;"
"EXPR_LREC: PLUS TERM EXPR_LREC | ;"
"TERM_LREC: MULT FACTOR TERM_LREC | ;";

static char const	*g_sym_names_expr[] = {"EXPR", "TERM", "FACTOR",
"EXPR_LREC", "TERM_LREC"};

static t_bool	test_parse_table(t_grammar const *gram)
{
	size_t			index;
	t_symbol const	*sym;

	index = 0;
	while (index < ARRAY_LENGTH(g_sym_names))
	{
		sym = find_sym_by_name(gram, g_sym_names[index]);
		if (!parse_row_is_correct(sym, g_parse_row_check[index],
					ARRAY_LENGTH(g_tokens)))
			break ;
		index++;
	}
	return (index == ARRAY_LENGTH(g_sym_names));
}

static t_bool	test_parse_table_expr(t_grammar const *gram)
{
	size_t			index;
	t_symbol const	*sym;

	index = 0;
	while (index < ARRAY_LENGTH(g_sym_names_expr))
	{
		sym = find_sym_by_name(gram, g_sym_names_expr[index]);
		if (!parse_row_is_correct(sym, g_parse_row_check_expr[index],
					ARRAY_LENGTH(g_tokens_expr)))
			break ;
		index++;
	}
	return (index == ARRAY_LENGTH(g_sym_names_expr));
}

int	main(void)
{
	t_grammar	*gram;
	t_bool		result;

	gram = parse_grammar_string(g_grammar);
	result = gram != NULL
		&& compute_first_grammar(gram)
		&& compute_follow_grammar(gram)
		&& compute_parsing_table(gram, g_tokens)
		&& test_parse_table(gram);
	destroy_grammar(&gram);
	if (!result)
		RET_TEST(result);
	gram = parse_grammar_string(g_grammar_expr);
	result = gram != NULL
		&& compute_first_grammar(gram)
		&& compute_follow_grammar(gram)
		&& compute_parsing_table(gram, g_tokens_expr)
		&& test_parse_table_expr(gram);
	destroy_grammar(&gram);
	RET_TEST(result);
}
