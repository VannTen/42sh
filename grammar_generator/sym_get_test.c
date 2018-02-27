/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:45:30 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/21 20:45:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"

t_prod const	*const *get_sym_parse_row(t_symbol const *sym)
{
	return ((t_prod const *const*)sym->parse_row);
}
