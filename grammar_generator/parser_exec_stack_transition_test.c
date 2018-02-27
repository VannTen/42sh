/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_stack_transition_test.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:07:08 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/25 18:07:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_interface.h"
#include "exec_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <assert.h>

static t_bool	zero_left(void *construct, va_list args)
{
	if (get_remaining_symbols(construct) == 0)
	{
		(*(va_arg(args, size_t*)))++;
		return (TRUE);
	}
	else
		return (FALSE);
}

/*
** Aka : token, or empty_production
*/

static t_bool	test_no_len_prod(t_lst **exec_stack,
		size_t const last_count,
		size_t const final_last_count,
		size_t const *stack)
{
	t_exec_construct const *current;

	current = get_lst_elem(*exec_stack, 0);
	if (last_count == 1)
		return (stack[STACK_SIZE]
				== f_lst_len(*exec_stack) + stack[TERMINATED_CONSTRUCT]
				&& get_remaining_symbols(current) == final_last_count);
	else
		return (get_remaining_symbols(current) == last_count - 1);
}

static t_bool	test_len_prod_concrete(
		t_lst **stack,
		size_t const stack_size,
		size_t const prod_len,
		size_t const last_count)
{
	t_exec_construct const *current;
	t_exec_construct const *previous;

	current = get_lst_elem(*stack, 0);
	previous = get_lst_elem(*stack, 1);
	return (stack_size + 1 == f_lst_len(*stack)
			&& get_remaining_symbols(current) == prod_len
			&& get_remaining_symbols(previous) == last_count - 1);
}

static t_bool	test_len_prod_abstract(
		t_lst **stack,
		size_t const stack_size,
		size_t const prod_len,
		size_t const last_count)
{
	t_exec_construct const *current;

	current = get_lst_elem(*stack, 0);
	return (stack_size == f_lst_len(*stack)
			&& get_remaining_symbols(current) == prod_len + last_count - 1);
}

/*
** stack_size[1] is number of construct that shall be terminated after the
** transition
*/

t_bool	test_one_construct_transition(
		t_lst **stack,
		t_exec const *functions,
		size_t const prod_len,
		void const *value)
{
	size_t	stack_size[2];
	size_t	last_elem_count;
	size_t	final_last_elem_count;

	stack_size[STACK_SIZE] = f_lst_len(*stack);
	last_elem_count = get_remaining_symbols(get_lst_elem(*stack, 0));
	assert(stack_size[STACK_SIZE] >= 1 && last_elem_count > 0);
	stack_size[TERMINATED_CONSTRUCT] = 1;
	f_lstiterr_va(advance_list(*stack, 1),
			zero_left, &stack_size[TERMINATED_CONSTRUCT]);
	final_last_elem_count = stack_size[STACK_SIZE] > 1 ?
		get_remaining_symbols(get_lst_elem(*stack, stack_size[1])) : 0;
	if (value == NULL)
		put_sym_in_stack(stack, functions, prod_len);
	else
		put_token_in_stack(value, stack, functions);
	if (prod_len == 0)
		return (test_no_len_prod(stack, last_elem_count, final_last_elem_count,
					stack_size));
	else
		return ((functions != NULL ?
				test_len_prod_concrete :
				test_len_prod_abstract)
				(stack, stack_size[STACK_SIZE], prod_len, last_elem_count));
}
