/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse_table_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:08:13 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 14:08:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"

t_prod const	*get_prod_for_token(t_symbol const *sym, size_t token_id)
{
	return (sym->parse_row[token_id]);
}
