/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_left_factor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:38:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 17:38:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>

static char const	*g_str_symbol[] = {
	"SYM: A B C D E"
		"| A B C"
		"| A B C F E"
		"| A B D W"
		"| A B D"
		"| A B D E"
		"| A B W"
		"|"
		"| A B E",
	"SAM: A B SYM_2_LFAC_ |",
	"SYM_2_LFAC_: E | W | D SYM_0_LFAC_ | C SYM_1_LFAC_",
	"SYM_1_LFAC_: | D E | F E",
	"SYM_0_LFAC_: | E | W"
};

static char const	*g_str_sym_no_op[] = {
	"EXPR: TERM EXPR_LREC",
	"TERM: FACTOR TERM_LREC",
	"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR",
	"EXPR_LREC: PLUS TERM EXPR_LREC |",
	"TERM_LREC: MULT FACTOR TERM_LREC"
};

static t_bool		test_left_factor(
			__attribute__((unused))t_prod **prods,
			t_symbol **syms,
			...)
{
	t_fifo	*new_syms;
	t_bool	result;
	size_t	index;

	new_syms = f_fifo_create();
	left_factor_sym(syms[0], new_syms);
	result = prods_are_equ(syms[0], syms[1]);
	result = result && sym_are_equ(syms[2], get_fifo_elem(new_syms, 0));
	result = result && sym_are_equ(syms[3], get_fifo_elem(new_syms, 1));
	index = 0;
	while (!result && index < ARRAY_LENGTH(g_str_symbol))
	{
		print_sym_back(syms[index], STDERR_FILENO);
		ft_dprintf(STDERR_FILENO, "\nSym number %zu\n", index);
		index++;
	}
	index = 0;
	ft_putstr_fd("\n", STDERR_FILENO);
	while (!result && index < fifo_len(new_syms))
	{
		print_sym_back(get_fifo_elem(new_syms, index), STDERR_FILENO);
		ft_dprintf(STDERR_FILENO, "\nSym result number %zu\n", index);
		index++;
	}
	f_fifo_destroy(&new_syms, iter_del_sym);
	return (result);
}

static t_bool		test_no_op(
			__attribute__((unused))t_prod **prods,
			t_symbol **syms,
			...)
{
	size_t		index;
	t_fifo		*sym_list[3];
	t_symbol	*sym;

	sym_list[2] = f_fifo_create();
	sym_list[0] = f_fifo_create();
	sym_list[1] = f_fifo_create();
	index = 0;
	while (index < ARRAY_LENGTH(g_str_sym_no_op))
	{
		sym = parse_symbol(g_str_sym_no_op[index], sym_list[0], sym_list[1]);
		if (!left_factor_sym(sym, sym_list[2]) || !sym_are_equ(sym, syms[index])
				|| fifo_len(sym_list[2]) != 0)
		{
			print_sym_back(sym, STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			break ;
		}
		index++;
	}
	f_fifo_destroy(&sym_list[0], iter_del_sym);
	f_fifo_destroy(&sym_list[1], iter_del_sym);
	f_fifo_destroy(&sym_list[2], iter_del_sym);
	return (index == ARRAY_LENGTH(g_str_sym_no_op));
}

int					main(void)
{
	RET_TEST(test_sym_prod(g_str_symbol, 0, ARRAY_LENGTH(g_str_symbol),
				test_left_factor)
			&& test_sym_prod(
				g_str_sym_no_op, 0, ARRAY_LENGTH(g_str_sym_no_op), test_no_op));
}
