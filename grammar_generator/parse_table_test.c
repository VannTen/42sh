/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_table_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:57:57 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 10:57:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_interface.h"
#include "test_interface.h"
#include <stddef.h>

static t_bool	equ(void const *sym, void const *str)
{
	return (ft_strequ(get_name(sym), str));
}

static t_bool	one_prod_parse_correct(
		t_prod const *prod,
		char const *prod_str)
{
	t_lst	*prod_cmp;
	t_bool	result;

	if (prod == NULL || prod_str == NULL)
		return (prod == NULL && prod_str == NULL);
	if (ft_strequ(prod_str, "") && get_prod_len(prod) == 0)
		return (TRUE);
	prod_cmp = f_strsplit_lst(prod_str, ' ');
	result = lst_equ(get_prod_lst(prod), prod_cmp, equ);
	f_lstdel(&prod_cmp, ft_gen_strdel);
	return (result);
}

t_bool			parse_row_is_correct(
		t_symbol const *sym,
		char const **cmp,
		size_t const nb_tokens)
{
	size_t				index;
	t_prod const *const	*parse_row;

	index = 0;
	parse_row = get_sym_parse_row(sym);
	while (index < nb_tokens
			&& one_prod_parse_correct(parse_row[index], cmp[index]))
		index++;
	return (index == nb_tokens);
}
