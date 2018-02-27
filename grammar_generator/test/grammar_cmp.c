/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:01:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 13:03:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "libft.h"

static const char	g_str_arith_expr[] =
"EXPR: EXPR PLUS TERM | EXPR MINUS TERM | TERM;"
"TERM: TERM MULTIPLY FACTOR | TERM DIVIDE FACTOR | FACTOR;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR | MINUS FACTOR;";

int	main(void)
{
	t_grammar	*gram[2];
	t_bool		result;

	gram[0] = parse_grammar_string(g_str_arith_expr);
	gram[1] = parse_grammar_string(g_str_arith_expr);
	result = gram_are_equ(gram[0], gram[1]);
	destroy_grammar(&gram[0]);
	destroy_grammar(&gram[1]);
	RET_TEST(result);
}
