/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:48:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/04 15:16:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"
#include "libft.h"

static void		prod_back(void const *prod, va_list args)
{
	int	fd;

	fd = va_arg(args, int);
	ft_putstr_fd(va_arg(args, char const*), fd);
	print_prod_back(prod, fd);
}

static void		s_prod_back(void const *prod, ...)
{
	va_list	args;

	va_start(args, prod);
	prod_back(prod, args);
	va_end(args);
}

void			print_sym_back(t_symbol const *sym, int const fd)
{
	ft_putstr_fd(sym->name, fd);
	if (sym->prods != NULL)
	{
		ft_putstr_fd(": ", fd);
		s_prod_back(f_lst_first_elem(sym->prods), fd, "");
		f_lstiter_va(advance_list(sym->prods, 1), prod_back, fd, " | ");
	}
}
