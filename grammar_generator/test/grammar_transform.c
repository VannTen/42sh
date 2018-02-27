/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:56:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/05 15:27:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "libft.h"
#include <unistd.h>

/*
** The two global variables holds corresponding version of several grammar :
** original and expected result after left recursion elimination.
** I use globals since the norminette bugs on multi-lines string litterals
** inside functions, no matter what I tried.
*/

static const char	*g_gram[] = {
	"EXPR: EXPR PLUS TERM | EXPR MINUS TERM | TERM;"
		"TERM: TERM MULTIPLY FACTOR | TERM DIVIDE FACTOR | FACTOR;"
		"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR | MINUS FACTOR;",
	"S: A AA | B;"
		"A: A Z C | S D | ;" };

static const char	*g_gram_non_lrec[] = {
	"EXPR: TERM EXPR_LREC;"
		"TERM: FACTOR TERM_LREC;"
		"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR | MINUS FACTOR;"
		"EXPR_LREC: PLUS TERM EXPR_LREC | MINUS TERM EXPR_LREC | ;"
		"TERM_LREC: MULTIPLY FACTOR TERM_LREC | DIVIDE FACTOR TERM_LREC | ;",
	"S: A AA | B;"
		"A: A_LREC | B D A_LREC;"
		"A_LREC: Z C A_LREC | AA D A_LREC | ;" };

int					main(void)
{
	t_grammar	*gram;
	t_grammar	*gram_no_lrec;
	t_bool		result;
	size_t		index;

	index = 0;
	result = TRUE;
	while (index < ARRAY_LENGTH(g_gram) && result)
	{
		gram = parse_grammar_string(g_gram[index]);
		gram_no_lrec = parse_grammar_string(g_gram_non_lrec[index]);
		eliminate_all_left_recursion(gram);
		result = gram_are_equ(gram, gram_no_lrec);
		if (!result)
		{
			print_grammar_back(STDERR_FILENO, gram);
			ft_putstr_fd("Test :", STDERR_FILENO);
			print_grammar_back(STDERR_FILENO, gram_no_lrec);
		}
		destroy_grammar(&gram);
		destroy_grammar(&gram_no_lrec);
		index++;
	}
	RET_TEST(result);
}
