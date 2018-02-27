/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:05:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 18:07:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** arith_expr grammar
**
** Non-terminals symbols  :
** EXPR, TERM, FACTOR.
** Terminals symbols : INTEGER, MINUS, PLUS, MULTIPLY, DIVIDE, LEFT_PAR,
** RIGHT_PAR.
*/

static const char	g_str_arith_expr[] =
"EXPR: EXPR PLUS TERM | EXPR MINUS TERM | TERM;"
"TERM: TERM MULTIPLY FACTOR | TERM DIVIDE FACTOR | FACTOR;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR | MINUS FACTOR;";

static t_bool		test_generated_gram(t_grammar const *gram)
{
	return (
			symbols_are_valid(gram)
			&& terminal_sym_count(gram) == 7 + 1
			&& non_terminal_sym_count(gram) == 3
			&& ft_strequ(get_name(get_start_symbol(gram)), "EXPR"));
}

/*
** '+ 1' terminal sym count is for EOF.
*/

static t_bool		t_parse_from_string(void)
{
	t_grammar	*gram;
	t_bool		result;

	gram = parse_grammar_string(g_str_arith_expr);
	result = test_generated_gram(gram);
	destroy_grammar(&gram);
	return (result);
}

/*

static t_bool		t_parse_from_file(char const *file_path)
{
	t_grammar	*gram;
	t_bool		result;

	gram = parse_grammar_file(file_path);
	result = test_generated_gram(gram);
	destroy_grammar(&gram);
	return (result);
}

static t_bool		t_parse_from_fd(void)
{
	t_grammar	*gram;
	t_bool		result;
	int			pipes[2];

	if (pipe(pipes) == -1)
		return (FALSE);
	ft_putstr_fd(g_str_arith_expr, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	gram = parse_grammar_fd(pipes[READ_END]);
	close(pipes[READ_END]);
	result = test_generated_gram(gram);
	destroy_grammar(&gram);
	return (result);
}

*/

int					main(void)
{
	RET_TEST(t_parse_from_string());
}
