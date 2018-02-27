/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_left_factor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:27:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 19:17:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "libft.h"
#include <unistd.h>

static char const	*g_gram[] = {
	"SYM: A B C D E"
		"| A B C"
		"| A B C F E"
		"| A B W"
		"| A B D W"
		"|"
		"| A B E;"
		"MYS: Z B C D E"
		"| Z B D W"
		"| Z B W"
		"|"
		"| Z B E;",
	"EXPR: TERM EXPR_LREC;"
		"TERM: FACTOR TERM_LREC;"
		"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;"
		"EXPR_LREC: PLUS TERM EXPR_LREC |;"
		"TERM_LREC: MULT FACTOR TERM_LREC;"
};

static char const	*g_gram_left_factored[] = {
	"SYM: A B SYM_1_LFAC_ | ;"
		"SYM_1_LFAC_: C SYM_0_LFAC_ | D W | W | E;"
		"SYM_0_LFAC_: D E | | F E;"
		"MYS: | Z B MYS_0_LFAC_;"
		"MYS_0_LFAC_: C D E | D W | W | E;",
	"EXPR: TERM EXPR_LREC;"
		"TERM: FACTOR TERM_LREC;"
		"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;"
		"EXPR_LREC: PLUS TERM EXPR_LREC |;"
		"TERM_LREC: MULT FACTOR TERM_LREC;"
};

int					main(void)
{
	t_grammar	*gram;
	t_grammar	*gram_left_factored;
	t_bool		result;
	size_t		index;

	index = 0;
	result = TRUE;
	while (index < ARRAY_LENGTH(g_gram) && result)
	{
		gram = parse_grammar_string(g_gram[index]);
		gram_left_factored = parse_grammar_string(g_gram_left_factored[index]);
		if (!left_factor_grammar(gram))
			return (EXIT_FAILURE);
		result = gram_are_equ(gram, gram_left_factored);
		if (!result)
		{
			print_grammar_back(STDERR_FILENO, gram);
			ft_putstr_fd("\nRef :", STDERR_FILENO);
			print_grammar_back(STDERR_FILENO, gram_left_factored);
		}
		destroy_grammar(&gram);
		destroy_grammar(&gram_left_factored);
		index++;
	}
	RET_TEST(result);
}
