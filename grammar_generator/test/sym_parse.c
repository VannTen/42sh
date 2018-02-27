/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:05:20 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 16:09:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "prods_interface.h"
#include "libft.h"
#include "test_interface.h"
#include <stdarg.h>
#include <stdlib.h>


static t_bool	test_sym_parse(
		__attribute__((unused))t_prod **prods,
		t_symbol **sym,
		...)
{
	va_list	args;

	va_start(args, sym);
	return ((get_prod_nb(sym[0]) == 4)
			&& sym[1] == NULL
			&& fifo_len(va_arg(args, t_fifo*)) == 1
			&& fifo_len(va_arg(args, t_fifo*)) == 5
			&& ft_strequ(get_name(sym[0]), "HHHH"));
}

/*
** Fifth token is EOF
*/

int				main(void)
{
	const char	*symbol[] = {
		"DEI_TT",
		"UHDE IUHDE",
		"DESDE",
		"\nHHHH \n\t  : DEI_TT | UHDE IUHDE     \t| DESDE|",
		"\t\n\t" };

	return (test_sym_prod(symbol, 3, 2, test_sym_parse) ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
