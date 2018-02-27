/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:53:17 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/24 13:53:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_interface.h"
#include "exec_interface.h"
#include "exec_construct_interface.h"
#include "libft.h"

static void	*create(__attribute__((unused))void const *value)
{
	int	*i;

	i = malloc(sizeof(*i));
	if (i != NULL)
		*i = 0;
	return (i);
}

static void	*tok_create(void const *value)
{
	int	*i;
	int	const *j;

	i = malloc(sizeof(*i));
	j = value;
	if (i != NULL)
	{
		*i =  *j;
	}
	return (i);
}

static t_bool	give(void *parent, void *child)
{
	int	*i;
	int	*j;

	i = parent;
	j = child;
	*i += *j;
	free(child);
	return (TRUE);
}

static t_bool	test_put_one_prod_in_stack(
		t_exec const *functions,
		size_t const *lengths)
{
	t_lst				*stack;
	size_t				index;
	t_exec_construct	*meta_construct;
	int					*final_result;
	int					i = 4;

	stack = NULL;
	index = 0;
	meta_construct = create_init_meta_construct();
	f_lstpush(meta_construct, &stack);
	while (test_one_construct_transition(&stack,
			 	functions[index].create != NULL ? &functions[index] : NULL,
				lengths[index],
				functions[index].create == tok_create ? &i : NULL)
			&& get_lst_elem(stack, 0) != meta_construct)
		index++;
	final_result = extract_top_symbol_value(&meta_construct);
	(void)f_lstpop(&stack);
	if (final_result != NULL)
		i = *final_result;
	free(final_result);
	return (i == 8);
}

int	main(void)
{
	t_exec const		functions[] = {
		{.create = create, .give = give},
		{.create = create, .give = give},
		{.create = create, .give = give},
		{.create = NULL},
		{.create = create, .give = give},
		{.create = tok_create},
		{.create = tok_create}
	};
	size_t const		prod_lengths[] =
	{2, 0, 1, 1, 2, 0, 0};

	RET_TEST(test_put_one_prod_in_stack(functions, prod_lengths));
}
