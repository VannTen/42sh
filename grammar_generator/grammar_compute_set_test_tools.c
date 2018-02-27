/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_compute_set_test_tools.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:06:01 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/13 17:06:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"

static t_bool	equ(void const *str, void const *sym)
{
	return (ft_strequ(str, get_name(sym)));
}

static t_bool	compare_first_sets(void const *sym,
		void const *first_sets_list)
{
	return (lst_same_contents(first_sets_list, get_first_set(sym), equ));
}

t_bool	gram_check_first_sets(
		t_grammar const *gram, t_lst const *first_sets)
{
	return (lst_same_contents(
				get_intern_lst(gram->sym_list),
				first_sets,
				compare_first_sets));
}

static t_bool	compare_follow_sets(void const *sym,
		void const *follow_sets_list)
{
	return (lst_same_contents(follow_sets_list, get_follow_set(sym), equ));
}

t_bool	gram_check_follow_sets(
		t_grammar const *gram, t_lst const *follow_sets)
{
	return (lst_same_contents(
				get_intern_lst(gram->sym_list),
				follow_sets,
				compare_follow_sets));
}
