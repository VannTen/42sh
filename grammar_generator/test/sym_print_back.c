/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:39:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 14:48:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static t_bool	non_terminal_symbol_works(t_symbol const *symbol)
{
	int			pipes[2];
	int			result;
	const char	expected_result[] =
		"HHHH: DEI_TT | UHDE IUHDE | DESDE;\n";

	pipe(pipes);
	print_sym_back(symbol, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	result = ft_str_fd_cmp(expected_result, pipes[READ_END]);
	close(pipes[READ_END]);
	return (result == 0);
}

static t_bool	terminal_symbol_works(t_symbol const *symbol)
{
	int			pipes[2];
	int			result;
	const char	expected_result[] = "HHHHER;\n";

	pipe(pipes);
	print_sym_back(symbol, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	result = ft_str_fd_cmp(expected_result, pipes[READ_END]);
	close(pipes[READ_END]);
	return (result == 0);
}

static t_bool	test(
		__attribute__((unused))t_prod **prods,
		t_symbol **symbols,
		...)
{
	return (non_terminal_symbol_works(symbols[0])
			&& terminal_symbol_works(symbols[1]));
}

int				main(void)
{
	const char	*symbol[] = {
		"HHHH \n\t   : DEI_TT | UHDE IUHDE     \t| DESDE",
		"HHHHER"};
	if (test_sym_prod(symbol, 0, 2, test))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
