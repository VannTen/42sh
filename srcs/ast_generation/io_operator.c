/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 13:24:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/io_operator.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "bool_interface.h"
#include <stdlib.h>

void	*create_io_operator(void const *lex_value)
{
	struct s_container	*container;

	(void)lex_value;
	container = new_container(NULL, 0, e_ast_container_label_io_operator);
	return (container);
}

t_bool	give_io_operator(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_container	*top;

	if (construct != NULL && sub_construct != NULL)
	{
		top = construct;
		sub = sub_construct;
		if (is_redir_label(sub->label))
		{
			top->content = sub;
			return (FALSE);
		}
	}
	return (FALSE);
}

void	delete_io_operator(void **const io_operator_loc)
{
	struct s_container	*todel;

	todel = (io_operator_loc != NULL) ? (*io_operator_loc) : (NULL);
	if (todel != NULL)
	{
		delete_container(&(todel->content), NULL);
		free(todel)
		io_operator_loc = NULL;
	}
}
