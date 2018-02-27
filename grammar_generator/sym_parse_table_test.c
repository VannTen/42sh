/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse_table_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 21:19:43 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/21 21:19:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "libft.h"
#include "test_interface.h"

t_bool	fill_syms_parse_table(t_symbol **syms, size_t nb_syms,
		char const **tokens)
{
	size_t	index;
	size_t	nb_tokens;

	index = 0;
	nb_tokens = ft_string_array_count(tokens) + 1;
	while (index < nb_syms && init_sym_parse_table(syms[index], nb_tokens))
		index++;
	if (index < nb_syms)
		return (FALSE);
	index = 0;
	while (index < nb_syms && fill_sym_parse_table(syms[index], tokens))
		index++;
	return (index == nb_syms);
}
