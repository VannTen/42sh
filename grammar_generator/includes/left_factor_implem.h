/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_factor_implem.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:03:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/21 14:47:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEFT_FACTOR_IMPLEM_H
# define LEFT_FACTOR_IMPLEM_H
# include "sym_interface.h"
# include "prods_interface.h"
# include <stddef.h>
# define LEFT_FAC_SUFFIX "_LFAC_"

typedef struct	s_left_fac
{
	t_symbol const *sym;
	size_t			index;
	t_lst			*sym_left_factored;
}				t_left_fac;

/*
** Prod left factor tools
** Implementation file : prod_left_factor.c
*/

t_prod		*prod_group_left_factor(t_lst *prods, size_t index,
		t_left_fac *ref_sym);

#endif
