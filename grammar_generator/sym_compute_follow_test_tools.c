/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_follow_test_tools.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:29:42 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/21 18:29:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"

t_bool	compute_follow_sets(t_symbol **syms, size_t const nb_sym)
{
	size_t		index;
	t_bool		sym_added;
	t_symbol	*end_of_input;

	end_of_input = create_symbol("END_OF_INPUT");
	if (!add_one_to_follow(syms[0], end_of_input, &sym_added))
		return (FALSE);
	index = 0;
	while (index < nb_sym && compute_follow_from_first_in_sym(syms[index]))
		index++;
	sym_added = TRUE;
	while (sym_added)
	{
		index = 0;
		sym_added = FALSE;
		while (index < nb_sym
				&& compute_follow_sym_step_3(syms[index], &sym_added))
			index++;
		if (index < nb_sym)
			return (FALSE);
	}
	return (TRUE);
}
