/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_empty_symbol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:56:31 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/05 18:10:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include <stddef.h>

t_symbol const g_empty_symbol =
{.name = "EMPTY", .prods = NULL, .first = NULL, .follow = NULL};
