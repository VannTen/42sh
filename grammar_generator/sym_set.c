/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:03:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 15:12:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include <assert.h>
#include <stdlib.h>

t_prod		*add_prod(t_symbol *sym, t_prod *prod)
{
	return (f_pushend_lst(&sym->prods, prod));
}

void			set_token_id(t_symbol *token, size_t index)
{
	assert(is_terminal(token));
	token->token_id = index;
}
