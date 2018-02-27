/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:45:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 16:48:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_bool	non_terminal_symbol_works(t_symbol const *symbol)
{
	int			pipes[2];
	int			result;
	const char	expected_result[] =
		"\nstatic t_symbol\t*create_hhhh(void)\n" "{\n"
		"\tt_symbol\t*new;\n\n"
		"\tnew = malloc(sizeof(t_symbol));\n"
		"\tif (new != NULL)\n" "\t{\n"
		"\t\tnew->type = HHHH;\n"
		"\t\tnew->productions = malloc(sizeof(t_symbol_type*) * (3 + 1));\n"
		"\t\tif (new->productions != NULL)\n\t\t{\n"
		"\t\t\tnew->productions[0] = generate_one_production(1, DEI_TT);\n"
		"\t\t\tnew->productions[1] = generate_one_production(2, UHDE, IUHDE);\n"
		"\t\t\tnew->productions[2] = generate_one_production(1, DESDE);\n"
		"\t\t\tnew->productions[3] = NULL;\n\t\t}\n\t\telse\n"
		"\t\t\tdestroy_symbol(&new);\n"
		"\t}\n"
		"\treturn (new);\n" "}\n";

	pipe(pipes);
	print_sym_initializer(symbol, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	result = ft_str_fd_cmp(expected_result, pipes[READ_END]);
	close(pipes[READ_END]);
	return (result == 0);
}

static t_bool	terminal_symbol_works(t_symbol const *symbol)
{
	int			pipes[2];
	int			result;
	const char	expected_result[] =
		"\nstatic t_symbol\t*create_hhhher(void)\n"
		"{\n"
		"\tt_symbol\t*new;\n\n"
		"\tnew = malloc(sizeof(t_symbol));\n"
		"\tif (new != NULL)\n"
		"\t{\n"
		"\t\tnew->type = HHHHER;\n"
		"\t\tnew->productions = NULL;\n"
		"\t}\n"
		"\treturn (new);\n"
		"}\n";

	pipe(pipes);
	print_sym_initializer(symbol, pipes[WRITE_END]);
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
