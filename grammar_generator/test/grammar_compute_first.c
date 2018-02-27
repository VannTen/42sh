/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_compute_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:48:01 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/10 22:18:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>

static char const g_gram[] =
"A: B C | D E | F G;"
"B: AA WW | EE LL;"
"E: R Z T | J;"
"AA: GHU WRV PP |;"
"Z: EE RR TT |;"
"C: CC RR | TT;"
"F: HUY TR |;"
"G: NER VB |;";

static char const *g_gram_comparison[] = {
	"GHU WW EE D HUY NER EMPTY",
	"GHU WW EE",
	"R J",
	"GHU EMPTY",
	"EE EMPTY",
	"CC TT",
	"HUY EMPTY",
	"NER EMPTY"
};

static char const g_gram_2[] =
"E: T E2;"
"E2: PLUS T E2 |;"
"T: F T2;"
"T2: MULTIPLY F T2 |;"
"F: LEFT_PAR E RIGHT_PAR | ID;";

static char const *g_gram_comparison_2[] = {
	"LEFT_PAR ID",
	"PLUS EMPTY",
	"LEFT_PAR ID",
	"MULTIPLY EMPTY",
	"LEFT_PAR ID"
};

static void	print(void const *first_set, va_list args)
{
	int	fd;

	fd = va_arg(args, int);
	ft_dprintf(fd, "\n");
	print_first_set_comp(first_set, fd);
}

static void	print_error(t_grammar const *gram, t_lst const *comp)
{
	print_first_sets(gram, STDERR_FILENO);
	ft_dprintf(STDERR_FILENO, "\nExpect result:\n");
	f_lstiter_va(comp, print, STDERR_FILENO);
	ft_dprintf(STDERR_FILENO, "\n");
}

int	main(void)
{
	t_bool		result[2];
	t_grammar	*transform[2];
	t_lst		*expected_result[2];

	transform[0] = parse_grammar_string(g_gram);
	expected_result[0] = str_to_first_set_lst(
			g_gram_comparison, ARRAY_LENGTH(g_gram_comparison));
	transform[1] = parse_grammar_string(g_gram_2);
	expected_result[1] = str_to_first_set_lst(
			g_gram_comparison_2, ARRAY_LENGTH(g_gram_comparison_2));
	compute_first_grammar(transform[0]);
	compute_first_grammar(transform[1]);
	result[0] = gram_check_first_sets(transform[0], expected_result[0]);
	result[1] = gram_check_first_sets(transform[1], expected_result[1]);
	if (!result[0])
		print_error(transform[0], expected_result[0]);
	if (!result[1])
		print_error(transform[1], expected_result[1]);
	destroy_grammar(&transform[0]);
	f_lstdel(&expected_result[0], destroy_cmp_first_set);
	destroy_grammar(&transform[1]);
	f_lstdel(&expected_result[1], destroy_cmp_first_set);
	RET_TEST(result[0] && result[1]);
}
