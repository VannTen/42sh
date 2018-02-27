/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:07:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/17 15:40:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_interface.h"
#include "libft.h"
#include "test_interface.h"
#include <unistd.h>

static char const	*prod_str[] = {"TYPE_1 TYPE_2", "TYPE_1, TYPE_2"};

t_bool	test(t_prod **prods, __attribute__((unused))t_symbol **symbol, ...)
{
	int			my_pipe[2];
	char		buf[100];

	pipe(my_pipe);
	print_prod(prods[0], my_pipe[1]);
	buf[read(my_pipe[0], buf, 50)] = '\0';
	close(my_pipe[0]);
	close(my_pipe[1]);
	return (ft_strequ(prod_str[1], buf));
}

int		main(void)
{
	RET_TEST(test_sym_prod(prod_str, 1, 0, test));
}
