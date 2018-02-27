/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prods_syms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:47:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 15:39:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_interface.h"
#include "prods_interface.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

static void		destroy_prods(t_prod ***d_prods, size_t nb_prod)
{
	size_t	index;
	t_prod	**prods;

	prods = *d_prods;
	if (prods != NULL)
	{
		index = 0;
		while (index < nb_prod)
		{
			destroy_prod(&prods[index]);
			index++;
		}
		free(prods);
		*d_prods = NULL;
	}
}

static void		sym_del(void **sym)
{
	destroy_symbol((t_symbol**)sym);
}

static t_prod	**parse_prods(
		char const **str,
		size_t nb_prods,
		t_fifo **sym_lists)
{
	size_t	index;
	t_prod	**prods;

	prods = malloc(sizeof(t_prod*) * nb_prods);
	if (prods != NULL)
	{
		index = 0;
		while (index < nb_prods)
		{
			prods[index] = parse_prod(str[index], sym_lists[0], sym_lists[1]);
			index++;
		}
	}
	return (prods);
}

static t_symbol	**parse_symbols(
		char const **str,
		size_t nb_symbols,
		t_fifo **sym_lists)
{
	size_t		index;
	t_symbol	**symbols;

	symbols = malloc(sizeof(t_symbol*) * nb_symbols);
	if (symbols != NULL)
	{
		index = 0;
		while (index < nb_symbols)
		{
			symbols[index] = parse_symbol(
					str[index], sym_lists[0], sym_lists[1]);
			index++;
		}
	}
	return (symbols);
}

t_bool			test_sym_prod(
		char const **str,
		size_t nb_prods,
		size_t nb_symbols,
		t_bool (*test)(t_prod **prod, t_symbol **syms, ...))
{
	t_prod		**prods;
	t_symbol	**syms;
	t_fifo		*sym_lists[2];
	t_bool		result;

	sym_lists[0] = f_fifo_create();
	sym_lists[1] = f_fifo_create();
	f_fifo_add(sym_lists[1], create_symbol("END_OF_INPUT"));
	prods = parse_prods(str, nb_prods, sym_lists);
	syms = parse_symbols(str + nb_prods, nb_symbols, sym_lists);
	if (prods != NULL && syms != NULL
			&& (fifo_len(sym_lists[0]) == 0
				|| compute_sets_all_syms(sym_lists[1], sym_lists[0])))
		result = test(prods, syms, sym_lists[0], sym_lists[1],
				nb_prods, nb_symbols);
	else
		result = FALSE;
	destroy_prods(&prods, nb_prods);
	free(syms);
	f_fifo_destroy(&sym_lists[0], sym_del);
	f_fifo_destroy(&sym_lists[1], sym_del);
	return (result);
}
