/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_first_test_tools.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:19:51 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/10 21:22:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

static t_bool	equ(void const *str, void const *sym)
{
	return (ft_strequ(str, get_name(sym)));
}

static void		print(void const *sym, va_list args)
{
	ft_dprintf(va_arg(args, int), "%s ", get_name(sym));
}

t_bool	compute_first_sets(
		t_symbol **syms, size_t nb_sym)
{
	size_t	index;
	t_bool	sym_added;
	t_bool	redundant;

	sym_added = TRUE;
	while (sym_added == TRUE)
	{
		index = 0;
		sym_added = FALSE;
		while (index < nb_sym)
		{
			redundant = FALSE;
			compute_sym_first_set(syms[index], &sym_added);
			compute_sym_first_set(syms[index], &redundant);
			if (redundant)
			{
				ft_dprintf(STDERR_FILENO,
						"Two add to first in %s\n", get_name(syms[index]));
				return (FALSE);
			}
			index++;
		}
	}
	return (TRUE);
}

void	print_symbol_first_set(t_symbol const *sym, int const fd)
{
	f_lstiter_va(get_first_set(sym), print, fd);
}

t_bool	check_first_sets(
		t_symbol **syms, t_lst **first_sets, size_t nb_sym)
{
	size_t	index;

	index = 0;
	while (index < nb_sym
			&& lst_same_contents(first_sets[index],
				get_first_set(syms[index]), equ))
		index++;
	if (index != nb_sym)
	{
		ft_dprintf(STDERR_FILENO,
				"expected for symbol %s :\n", get_name(syms[index]));
		print_first_set_comp(first_sets[index], STDERR_FILENO);
		ft_dprintf(STDERR_FILENO, "\nresult :\n");
		print_symbol_first_set((syms[index]), STDERR_FILENO);
	}
	return (index == nb_sym);
}
