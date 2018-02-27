/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_stack_ressources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:47:24 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/24 10:47:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_defs.h"
#include "sym_interface.h"
#include <assert.h>
#include <stdlib.h>

void				destroy_construct(t_exec_construct **to_destroy)
{
	t_exec_construct	*construct;

	assert(to_destroy != NULL);
	construct = *to_destroy;
	if (construct != NULL)
	{
		construct->functions = NULL;
		construct->remaining_symbols = 0;
		construct->real = NULL;
		free(construct);
		*to_destroy = NULL;
	}
}

t_exec_construct	*create_construct(t_exec const *exec_functions)
{
	t_exec_construct	*new_construct;

	assert(exec_functions != NULL);
	new_construct = malloc(sizeof(*new_construct));
	if (new_construct != NULL)
	{
		new_construct->functions = exec_functions;
		new_construct->remaining_symbols = 0;
		new_construct->real = NULL;
	}
	return (new_construct);
}

/*
** Intented to destroy symbols in the exec stack that have not be given to their
** parent, except the meta construct, which does not belong to the exec_stack.
*/

static void			destroy_construct_in_stack(t_exec_construct **to_destroy)
{
	t_exec_construct	*construct;

	construct = *to_destroy;
	if (construct != construct->real)
	{
		construct->functions->destroy(&construct->real);
		destroy_construct(to_destroy);
	}
}

void				clean_exec_struct(void **exec_struct)
{
	destroy_construct_in_stack((t_exec_construct**)exec_struct);
}
