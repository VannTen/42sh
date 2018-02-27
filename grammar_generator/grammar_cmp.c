/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:55:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 19:13:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "libft.h"

static t_bool	equ(void const *sym_1, void const *sym_2)
{
	return (sym_are_equ(sym_1, sym_2));
}

t_bool			gram_are_equ(t_grammar const *gram_1, t_grammar const *gram_2)
{
	return (fifo_same_contents(gram_1->sym_list, gram_2->sym_list, equ));
}
