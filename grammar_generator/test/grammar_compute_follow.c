/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_compute_follow.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:54:26 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/13 16:54:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>

static char const	g_gram[] =
"E: T E2;"
"E2: PLUS T E2 |;"
"T: F T2;"
"T2: MULTIPLY F T2 |;"
"F: LEFT_PAR E RIGHT_PAR | ID;";

static char const	*g_gram_comparison[] = {
	"RIGHT_PAR END_OF_INPUT",
	"RIGHT_PAR END_OF_INPUT",
	"PLUS RIGHT_PAR END_OF_INPUT",
	"PLUS RIGHT_PAR END_OF_INPUT",
	"PLUS MULTIPLY RIGHT_PAR END_OF_INPUT"
};

static void			print_error(t_grammar const *gram, t_lst const *result)
{
	ft_dprintf(STDERR_FILENO, "Result:\n");
	print_follow_sets(gram, STDERR_FILENO);
	ft_dprintf(STDERR_FILENO, "\nComparison:\n");
	print_first_set_comp(result, STDERR_FILENO);
}

int					main(void)
{
	t_bool		result;
	t_grammar	*transform;
	t_lst		*expected_result;

	transform = parse_grammar_string(g_gram);
	expected_result = str_to_first_set_lst(
			g_gram_comparison, ARRAY_LENGTH(g_gram_comparison));
	compute_first_grammar(transform);
	compute_follow_grammar(transform);
	result = gram_check_follow_sets(transform, expected_result);
	if (!result)
		print_error(transform, expected_result);
	destroy_grammar(&transform);
	f_lstdel(&expected_result, destroy_cmp_first_set);
	RET_TEST(result);
}
