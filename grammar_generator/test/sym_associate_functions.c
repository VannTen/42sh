/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_associate_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:27:41 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 16:27:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "grammar_interface.h"
#include "exec_interface.h"
#include "test_interface.h"

static char const g_grammar[] =
"EXPR: EXPR PLUS TERM | TERM;"
"TERM: TERM MULT FACTOR | FACTOR;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;";

t_bool	check_functions(t_grammar const *gram, t_exec const *functions)
{
	size_t		index;
	t_symbol	*sym;

	index = 0;
	while (functions[index].name != NULL)
	{
		sym = find_sym_by_name(gram, functions[index].name);
		if (get_exec_functions(sym) != &functions[index])
			break ;
		index++;
	}
	return (functions[index].name == NULL);
}

int	main(void)
{
	t_grammar		*gram;
	t_exec const	functions[] = {
		{.name = "EXPR", .create = create_expr, .give = give_expr},
		{.name = "TERM", .create = create_term, .give = give_term},
		{.name = "FACTOR", .create = create_factor, .give = give_factor},
		{.name = NULL, NULL, NULL},
	};
	t_bool			result;

	gram = parse_grammar_string(g_grammar);
	result = associate_exec_functions(gram, functions)
		&& check_functions(gram, functions);
	destroy_grammar(&gram);
	gram = parse_grammar_string(g_grammar);
	result = eliminate_all_left_recursion(gram)
		|| left_factor_grammar(gram)
		|| compute_first_grammar(gram)
		|| compute_follow_grammar(gram)
		|| associate_exec_functions(gram, functions)
		|| check_functions(gram, functions);
	destroy_grammar(&gram);
	RET_TEST(result);
}
