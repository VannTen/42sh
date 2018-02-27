/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:26:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 15:43:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <assert.h>

static char		**strip_input(char const *src)
{
	char	**stripped_input;

	stripped_input = ft_strsplit(src, DERIVATION_SIGN);
	if (stripped_input != NULL
			|| ft_string_array_count((char const *const*)stripped_input) != 2)
	{
		ft_strip_in_place(stripped_input[0], is_valid_sym_name_part, TRUE);
		if (stripped_input[0][0] == '\0')
			ft_free_string_array(&stripped_input);
	}
	else
		ft_free_string_array(&stripped_input);
	return (stripped_input);
}

static void		*s_prod_parse(void const *v_prod, va_list args)
{
	t_fifo const	*sym_added;
	t_fifo			*sym_pending;

	sym_added = va_arg(args, t_fifo const*);
	sym_pending = va_arg(args, t_fifo*);
	return (parse_prod(v_prod, sym_added, sym_pending));
}

static t_lst	*parse_prods(char const *str,
		t_fifo const *sym_added, t_fifo *sym_pending)
{
	t_lst	*each_prod_str;
	t_lst	*each_prod;

	assert(str != NULL);
	each_prod_str = f_strsplit_lst_mod(str, "|", FALSE);
	if (each_prod_str != NULL)
		each_prod = f_lstmap_va(each_prod_str, s_prod_parse, iter_del_prod,
				sym_added, sym_pending);
	else
		each_prod = NULL;
	f_lstdel(&each_prod_str, ft_gen_strdel);
	return (each_prod);
}

static t_symbol	*find_symbol(
		char const *src, t_fifo *sym_parsed, t_fifo *sym_pending)
{
	t_symbol	*sym_to_add;

	if (f_fifo_every_valid_va(sym_parsed, FALSE, same_sym_parsed, src) != NULL)
		return (NULL);
	sym_to_add = f_fifotakeone_if_va(sym_pending, TRUE, same_sym_parsed, src);
	if (sym_to_add == NULL)
		sym_to_add = create_symbol(src);
	f_fifo_add(sym_parsed, sym_to_add);
	return (sym_to_add);
}

t_symbol		*parse_symbol(char const *src,
		t_fifo *sym_added, t_fifo *sym_pending)
{
	char		**name_and_prods;
	t_symbol	*new_symbol;

	name_and_prods = strip_input(src);
	if (name_and_prods != NULL)
	{
		new_symbol = find_symbol(name_and_prods[0], sym_added, sym_pending);
		if (new_symbol != NULL)
			new_symbol->prods = name_and_prods[1] == NULL ? NULL :
				parse_prods(name_and_prods[1], sym_added, sym_pending);
	}
	else
		new_symbol = NULL;
	ft_free_string_array(&name_and_prods);
	return (new_symbol);
}
