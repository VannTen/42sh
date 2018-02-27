/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:11:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 13:03:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"

t_prod	*produce_developed_prod(
		t_prod const *developed_symbol,
		t_prod const *to_develop)
{
	return (join_prods(developed_symbol, to_develop));
}
