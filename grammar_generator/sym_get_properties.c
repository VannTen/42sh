/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get_properties.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:13:37 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/12 18:21:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include "libft.h"
#include <stddef.h>
#include <assert.h>

static t_bool	is_empty_prod(void const *prod,
		__attribute__((unused))va_list args)
{
	return (get_prod_len(prod) == 0);
}

t_bool			has_empty_prod(t_symbol const *sym)
{
	return (NULL != f_lst_every_valid_va(sym->prods, FALSE, is_empty_prod));
}

t_bool			is_terminal(t_symbol const *sym)
{
	return (0 == get_prod_nb(sym));
}

size_t			get_token_id(t_symbol const *token)
{
	assert(is_terminal(token));
	return (token->token_id);
}
