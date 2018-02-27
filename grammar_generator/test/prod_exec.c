/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:17:21 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 15:17:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "test_interface.h"

static char const	*g_prod[] = {
	"SYM_1 SYM_2",
	"SYM_3 A B C",
	"E T O",
};

static t_bool	test_prod_exec(
		t_prod **prod,
		__attribute__((unused))t_symbol **sym,
		...)
{
	t_lst	*stack;
	t_bool	result;

	stack = NULL;
	result = add_prod_to_stack(prod[0], &stack)
		&& f_lst_len(stack) == 2
		&& ft_strequ(get_name(get_lst_elem(stack, 0)), "SYM_1")
		&& ft_strequ(get_name(get_lst_elem(stack, 1)), "SYM_2")
		&& add_prod_to_stack(prod[1], &stack)
		&& f_lst_len(stack) == 6
		&& ft_strequ(get_name(get_lst_elem(stack, 0)), "SYM_3")
		&& ft_strequ(get_name(get_lst_elem(stack, 1)), "A")
		&& ft_strequ(get_name(get_lst_elem(stack, 2)), "B")
		&& ft_strequ(get_name(get_lst_elem(stack, 3)), "C")
		&& add_prod_to_stack(prod[2], &stack)
		&& f_lst_len(stack) == 9
		&& ft_strequ(get_name(get_lst_elem(stack, 0)), "E")
		&& ft_strequ(get_name(get_lst_elem(stack, 1)), "T")
		&& ft_strequ(get_name(get_lst_elem(stack, 2)), "O");
	f_lstdel(&stack, no_destroy);
	return (result);
}

int		main(void)
{
	RET_TEST(test_sym_prod(g_prod, ARRAY_LENGTH(g_prod), 0, test_prod_exec));
}
