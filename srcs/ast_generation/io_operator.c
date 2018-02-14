/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/14 10:07:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/io_operator.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include <stdlib.h>

void	*create_io_operator(void const *lex_value)
{
	struct s_container	*container;

	(void)lex_value;
	container = new_container(NULL, NULL, 0, e_ast_container_label_io_operator);
	return (container);
}

static t_bool	is_operator_label(enum e_ast_container_label const label)
{
	enum e_ast_container_label const	io_operator_labels[] = {
		e_ast_container_label_clobber, e_ast_container_label_great,
		e_ast_container_label_dgreat, e_ast_container_label_greatand,
		e_ast_container_label_lessand, e_ast_container_label_less,
		e_ast_container_label_dless, e_ast_container_label_dlessdash,
		e_ast_container_label_lessgreat
	};
	size_t								i;

	i = 0;
	while (i < sizeof(io_operator_labels) / sizeof(*io_operator_labels))
		if (label == io_operator_labels[i])
			return (TRUE);
		else
			i += 1;
	return (FALSE);
}

t_bool	give_io_operator(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_container	*top;

	if (construct != NULL && sub_construct != NULL)
	{
		top = construct;
		sub = sub_construct;
		if (is_operator_label(sub->label))
		{
			top->content = sub;
			return (TRUE);
		}
	}
	return (FALSE);
}

void	destroy_io_operator(void **const io_operator_loc)
{
	struct s_container	*todel;

	todel = (io_operator_loc != NULL) ? (*io_operator_loc) : (NULL);
	if (todel != NULL)
	{
		destroy_container(&(todel->content));
		free(todel);
		*io_operator_loc = NULL;
	}
}
