/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:37:22 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/06 11:26:15 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_defs.h"
#include "libft.h"
#include <assert.h>

static t_bool			put_on_stack(
		void const *value,
		t_lst **exec_stack,
		t_exec const *functions,
		size_t const prod_len)
{
	t_exec_construct	*current;
	t_exec_construct	*new_child;

	if (functions != NULL)
	{
		new_child = create_construct(functions);
		if (new_child != NULL)
		{
			new_child->real = functions->create(value);
			if (new_child->real == NULL
					|| NULL == f_lstpush(new_child, exec_stack))
				destroy_construct(&new_child);
		}
		current = new_child;
	}
	else
		current = (void*)get_lst_elem(*exec_stack, 0);
	if (current != NULL)
		current->remaining_symbols += prod_len;
	return (current != NULL);
}

static t_bool			consume_stack(t_lst **exec_stack)
{
	t_exec_construct	*child;
	t_exec_construct	*parent;

	assert(*exec_stack != NULL);
	while (get_remaining_symbols(get_lst_elem(*exec_stack, 0)) == 0)
	{
		child = f_lstpop(exec_stack);
		parent = (void*)get_lst_elem(*exec_stack, 0);
		if (*exec_stack == NULL)
			break;
		if (!parent->functions->give(parent->real, child->real))
		{
			clean_exec_struct((void**)&child);
			break ;
		}
		destroy_construct(&child);
	}
	return (*exec_stack == NULL
			|| get_remaining_symbols(get_lst_elem(*exec_stack, 0)) != 0);
}

static t_bool			put_one_prod_in_stack(
		void const *value,
		t_lst **exec_stack,
		t_exec const *functions,
		size_t const prod_len)
{
	t_exec_construct	*current;

	current = (void*)get_lst_elem(*exec_stack, 0);
	current->remaining_symbols--;
	return (put_on_stack(value, exec_stack, functions, prod_len)
			&& consume_stack(exec_stack));
}

t_bool					put_token_in_stack(
		void const *value,
		t_lst **exec_stack,
		t_exec const *functions)
{
	return (put_one_prod_in_stack(value, exec_stack, functions, 0));
}

t_bool					put_sym_in_stack(
		t_lst **exec_stack,
		t_exec const *functions,
		size_t const prod_len)
{
	return (put_one_prod_in_stack(NULL, exec_stack, functions, prod_len));
}
