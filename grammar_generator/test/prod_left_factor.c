/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_left_factor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:12:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 17:45:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "left_factor_implem.h"
#include "prods_interface.h"
#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>

static t_bool	test_prod_str(char const *str, t_prod const *prod)
{
	int		pipes[2];
	t_bool	result;

	pipe(pipes);
	print_prod_back(prod, pipes[WRITE_END]);
	close(pipes[WRITE_END]);
	result = ft_str_fd_cmp(str, pipes[READ_END]) == 0;
	close(pipes[READ_END]);
	if (!result)
	{
		print_prod_back(prod, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (result);
}

static t_bool	test_lfact(t_prod **prods, t_symbol **syms, ...)
{
	t_lst		*prods_lst;
	t_left_fac	sym_ref;
	t_prod		*prod;
	char const	result_prod[] = "A B C SYM_TEST_0" LEFT_FAC_SUFFIX;
	t_bool		result;

	sym_ref.sym = syms[0];
	sym_ref.index = 0;
	sym_ref.sym_left_factored = NULL;
	prods_lst = array_to_lst_index(prods, 3);
	prod = prod_group_left_factor(prods_lst, 3, &sym_ref);
	result = test_prod_str(result_prod, prod);
	destroy_prod(&prod);
	f_lstdel(&sym_ref.sym_left_factored, iter_del_sym_not_prod);
	return (result);
}

int				main(void)
{
	char const	*sym[] = {
		"A B C D",
		"A B C E",
		"A B C",
		"SYM_TEST:"
	};

	RET_TEST(test_sym_prod(sym, 3, 1, test_lfact));
}
