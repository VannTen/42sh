/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_left_factor_implem.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:20:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/21 15:31:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYM_LEFT_FACTOR_IMPLEM_H
# define SYM_LEFT_FACTOR_IMPLEM_H
# include "libft.h"
# include "sym_interface.h"
# define LEFT_FAC_SUFFIX "_LFAC_"

/*
** Private method for sym_left_factor.c
** Implementation file : sym_left_factor_compute.c
*/

t_lst	*sym_left_factor_compute(t_symbol const *sym, t_lst **derived_syms);

#endif
