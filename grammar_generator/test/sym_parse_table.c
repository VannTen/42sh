/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:51:29 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/21 17:51:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#define NB_SYM ARRAY_LENGTH(g_sym)

static char const	*g_sym[] = {
	"SYM: A B | SYM_2 W ",
	"SYM_2: X Y | N M |"
};

static char const	*g_tokens[] = {"A", "B", "W", "X", "Y", "N", "M", NULL};

static char const	*g_parse_row[][ARRAY_LENGTH(g_tokens)] = {
	{"A B", NULL, "SYM_2 W", "SYM_2 W", NULL, "SYM_2 W", NULL, NULL},
	{NULL, NULL, "", "X Y", NULL, "N M", NULL, NULL}
};

t_bool				test_sym_parse_table(
		__attribute__((unused))t_prod **prod, t_symbol **sym, ...)
{
	size_t	index;

	(void)fill_syms_parse_table(sym, NB_SYM, g_tokens);
	index = 0;
	while (index < ARRAY_LENGTH(g_sym)
			&& parse_row_is_correct(
				sym[index], g_parse_row[index], ARRAY_LENGTH(g_tokens)))
		index++;
	return (index == ARRAY_LENGTH(g_sym));
}

int					main(void)
{
	RET_TEST(test_sym_prod(
				g_sym,
				ARRAY_LENGTH(g_sym) - NB_SYM,
				NB_SYM,
				test_sym_parse_table));
}
