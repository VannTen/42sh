/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_defs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:00:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/25 11:51:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_DEFS_H
# define GRAMMAR_DEFS_H
# include "grammar_interface.h"
# include "sym_interface.h"
# include "libft.h"

/*
** sym_list is a list of t_symbol elements which have productions.
** tokens_list is also a list of t_symbol elements which does not have any
** productions.
*/

struct s_grammar
{
	t_symbol		*start_symbol;
	t_fifo			*sym_list;
	t_fifo			*tokens_list;
};

#endif
