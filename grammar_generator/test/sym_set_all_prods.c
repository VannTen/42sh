/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set_all_prods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:47:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 16:02:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include <stdlib.h>

/*
** TODO: add test for function to_each_prod
*/

static void		parse_and_delete(const char **strs, t_symbol **syms,
		size_t size, t_bool parse)
{
	size_t	index;

	index = 0;
	if (parse)
	{
		while (index < size && (index == 0 || syms[index - 1] != NULL))
		{
			syms[index] = parse_symbol(strs[index]);
			index++;
		}
	}
	else
	{
		while (index < size)
		{
			destroy_symbol(&syms[index]);
			index++;
		}
	}
}

static t_bool	append_prefix_to_each_prod(void)
{
	const char	*symbol[] = {
		"SYMBOL : OTHER_SYMBP OTHER | SYM | SYMI OTHER SYMO",
		"SYMBOL : OTHER_SYMBP OTHER TEKI | SYM TEKI | SYMI OTHER SYMO TEKI",
		"SYMBOL : TAKO OTHER_SYMBP OTHER TEKI | TAKO SYM TEKI |"
			"TAKO SYMI OTHER SYMO TEKI", "TEKI : OTHER_SYMBP OTHER | SYM ",
		"TAKO : OTHER_SYMBP OTHER | SYM "};
	t_symbol	*sym[ARRAY_LENGTH(symbol)];
	t_bool		result;

	result = TRUE;
	parse_and_delete(symbol, sym, ARRAY_LENGTH(symbol), TRUE);
	append_to_each_prod(sym[0], sym[3]);
	if (!symbol_are_identical(sym[0], sym[1]))
		result = FALSE;
	prefix_to_each_prod(sym[0], sym[4]);
	if (!symbol_are_identical(sym[0], sym[2]))
		result = FALSE;
	parse_and_delete(symbol, sym, ARRAY_LENGTH(symbol), FALSE);
	return (result);
}

int				main(void)
{
	return (append_prefix_to_each_prod() ? EXIT_SUCCESS : EXIT_FAILURE);
}
