/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prods_defs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:28:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 12:55:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_PRODS_DEFS_H
# define GRAM_GEN_PRODS_DEFS_H
# include "prods_interface.h"
# define SYMBOL_NAME_SEP ' '

/*
** The prod is a list of symbols references.
** Each symbol is unique, and so, a symbol with the same as another is the same.
** s_prod does not own the symbols, and it shall not act upon them.
** (so, all t_symbol reference in s_prod implementation shall be const)
**
** s_prod is a structure solely for the purpose of encapsulation. C syntax does
** not provide another means to use opaque-pointers, and there is no overhead
** (other than a syntactic one) in the resulting machine code.
*/

struct	s_prod
{
	t_lst	*sym_list;
};

#endif
