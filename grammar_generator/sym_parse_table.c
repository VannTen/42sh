/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:17:14 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 19:17:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include <assert.h>

t_bool			init_sym_parse_table(t_symbol *sym, size_t nb_tokens)
{
	size_t	index;

	sym->parse_row = malloc(sizeof(*(sym->parse_row)) * nb_tokens);
	if (sym->parse_row != NULL)
	{
		index = 0;
		while (index < nb_tokens)
		{
			sym->parse_row[index] = NULL;
			index++;
		}
	}
	return (sym->parse_row != NULL);
}

static void		fill_from_follow_set(void const *token, va_list args)
{
	t_symbol	*sym;
	char const	**token_names;
	size_t		index;

	sym = va_arg(args, t_symbol*);
	token_names = va_arg(args, char const**);
	if (ft_strequ(get_name(token), "END_OF_INPUT"))
		index = ft_string_array_count(token_names);
	else
	{
		index = 0;
		while (token_names[index] != NULL
				&& !ft_strequ(get_name(token), token_names[index]))
			index++;
		assert(token_names[index] != NULL);
	}
	assert(sym->parse_row[index] == NULL);
	sym->parse_row[index] = va_arg(args, t_prod*);
}

static void		fill_parse_row(void const *token, va_list args)
{
	t_symbol	*sym;
	char const	**token_names;
	size_t		index;

	sym = va_arg(args, t_symbol*);
	token_names = va_arg(args, char const**);
	index = 0;
	if (token == EMPTY_SYMBOL)
		f_lstiter_va(sym->follow,
				fill_from_follow_set, sym, token_names, va_arg(args, t_prod*));
	else
	{
		while (token_names[index] != NULL
				&& !ft_strequ(get_name(token), token_names[index]))
			index++;
		assert(token_names[index] != NULL);
		assert(sym->parse_row[index] == NULL);
		sym->parse_row[index] = va_arg(args, t_prod*);
	}
}

static t_bool	add_to_parse_row(void *prod, va_list arg)
{
	t_symbol	*sym;
	char const	**token_names;
	t_lst		*prod_first;

	sym = va_arg(arg, t_symbol*);
	token_names = va_arg(arg, char const**);
	prod_first = create_first_set_prod(prod);
	if (prod_first != NULL)
	{
		f_lstiter_va(prod_first,
				fill_parse_row, sym, token_names, prod);
		f_lstdel(&prod_first, no_destroy);
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool			fill_sym_parse_table(t_symbol *sym, char const **token_names)
{
	return (f_lstiterr_va(sym->prods,
				add_to_parse_row, sym, token_names));
}
