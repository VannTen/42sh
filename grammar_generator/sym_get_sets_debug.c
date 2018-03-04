/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get_sets_debug.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 11:24:00 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/04 11:24:26 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sym_defs.h"
#include <stdarg.h>

/*
** Used in debug.
*/

t_lst const		*get_first_set(t_symbol const *sym)
{
	return (sym->first);
}

t_lst const		*get_follow_set(t_symbol const *sym)
{
	return (sym->follow);
}
