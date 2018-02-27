/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 14:41:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include <stdarg.h>

static void	iter(void const *sym, va_list args)
{
	int			fd;
	char const	*separator;

	fd = va_arg(args, int);
	separator = va_arg(args, char const*);
	ft_dprintf(
			fd,
			"%s%s",
			separator,
			get_name(sym));
}

static void	print_it(t_prod const *prod, int const fd, char const *sep)
{
	if (prod->sym_list != NULL)
	{
		ft_putstr_fd(get_name(f_lst_first_elem(prod->sym_list)), fd);
		f_lstiter_va(advance_list(prod->sym_list, 1), iter, fd, sep);
	}
}

void		print_prod(t_prod const *prod, int const fd)
{
	print_it(prod, fd, ", ");
}

void		print_prod_back(t_prod const *prod, int const fd)
{
	print_it(prod, fd, " ");
}
