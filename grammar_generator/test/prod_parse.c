/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:26:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 16:58:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

/*
** Test that the parsing of a prod correctly create "pending symbols", which
** shall be defined later, if they are not yet defined in the "added_symbol"
** list
*/

static t_bool		test_prod_parse(t_prod **prods, t_symbol **syms, ...)
{
	va_list	args;
	va_start(args, syms);

	return (get_prod_len(prods[0]) == 0
				&& get_prod_len(prods[1]) == 0
				&& get_prod_len(prods[2]) == 0
				&& fifo_len(va_arg(args, t_fifo*)) == 2
				&& fifo_len(va_arg(args, t_fifo*)) == 3);
}

/*
** Third token is EOF
*/

int					main(void)
{
	char const	*str[] = {"   ", "" , "\t\n", "TERM_1 TER", "TERM_7",
	"TERM_7:TERM_1 TERM_7 | TERM_7 TERM_1|",
	"TERM_4:|TERM_7" };

	return (test_sym_prod(str, ARRAY_LENGTH(str) - 2, 2, test_prod_parse) ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
