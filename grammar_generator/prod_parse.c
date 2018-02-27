/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:47:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 16:51:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

static t_symbol		*find_sym(
		t_fifo const *sym_already_parsed,
		t_fifo *sym_pending,
		char const *sym_name)
{
	t_symbol	*sym_to_add;

	sym_to_add = f_fifo_every_valid_va(
			sym_already_parsed, FALSE, same_sym_parsed, sym_name);
	if (sym_to_add == NULL)
	{
		sym_to_add = f_fifo_every_valid_va(sym_pending,
				FALSE, same_sym_parsed, sym_name);
		if (sym_to_add == NULL)
		{
			sym_to_add = create_symbol(sym_name);
			if (sym_to_add != NULL)
				f_fifo_add(sym_pending, sym_to_add);
			else
				destroy_symbol(&sym_to_add);
		}
	}
	return (sym_to_add);
}

static t_bool		is_valid(char const *prod_str)
{
	size_t	index;

	index = 0;
	while (prod_str[index] != '\0')
	{
		if (!(is_among(" \n\t", prod_str[index])
					|| is_unix_constants(prod_str[index])
					|| ft_isdigit(prod_str[index])))
			break ;
		index++;
	}
	return (prod_str[index] == '\0');
}

static void			error_funct(t_symbol **sym, t_prod **prod)
{
	destroy_symbol(sym);
	destroy_prod(prod);
}

t_prod				*parse_prod(
		char const *one_str_prod,
		t_fifo const *sym_parsed,
		t_fifo *sym_pending)
{
	char		**each_sym_name;
	size_t		index;
	t_symbol	*sym_added;
	t_prod		*new_prod;

	index = 0;
	if (!is_valid(one_str_prod))
		return (NULL);
	each_sym_name = strsplit_with_str(one_str_prod, " \t\n");
	new_prod = create_prod();
	while (each_sym_name[index] != NULL)
	{
		sym_added = find_sym(sym_parsed, sym_pending, each_sym_name[index]);
		if (sym_added == NULL || !append_to_prod(new_prod, sym_added))
			error_funct(&sym_added, &new_prod);
		index++;
	}
	ft_free_string_array(&each_sym_name);
	return (new_prod);
}
