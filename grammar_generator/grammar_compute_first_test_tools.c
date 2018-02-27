/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_compute_first_test_tools.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:43:43 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/10 22:08:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"

static void		print(void const *sym, va_list args)
{
	ft_dprintf(va_arg(args, int), "%s ", get_name(sym));
}

static void print_sym_set(void const *sym, va_list args)
{
	int			fd;
	t_lst const	*(*get_set)(t_symbol const *sym);

	fd = va_arg(args, int);
	get_set = va_arg(args, t_lst const *(*)(t_symbol const*));
	ft_dprintf(fd, "Sym : %s:\n", get_name(sym));
	f_lstiter_va(get_set(sym), print, fd);
	ft_dprintf(fd, "\n");
}

void	print_follow_sets(t_grammar const *gramm, int const fd)
{
	f_fifoiter_va(gramm->sym_list, print_sym_set, fd, get_follow_set);
}

void	print_first_sets(t_grammar const *gramm, int const fd)
{
	f_fifoiter_va(gramm->sym_list, print_sym_set, fd, get_first_set);
}
