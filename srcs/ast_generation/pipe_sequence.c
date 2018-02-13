/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 13:24:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_generation.h"
#include "shell_ast/pipe_sequence.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "bool_interface.h"
#include <stdlib.h>

void	*create_pipe_sequence(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_pipe_sequence	pipe_sequence;

	(void)lex_value;
	pipe_sequence->simple_commands = NULL;
	container = new_container(&pipe_sequence, sizeof(pipe_sequence), e_ast_container_label_pipe_sequence);
	return (container);
}

t_bool	give_pipe_sequence(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_sh_pipe_sequence	*pipe_sequence;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		pipe_sequence = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_simple_command)
			ret = add_simple_command(pipe_sequence, sub);
		else if (sub->label == e_ast_container_label_pipe)
			ret = TRUE;
		if (ret == TRUE)
			delete_container(&sub, NULL);
	}
	return (ret);
}

void	delete_pipe_sequence(struct s_sh_pipe_sequence **const pipe_sequence_loc)
{
	struct s_sh_pipe_sequence	*todel;

	todel = (pipe_sequence_loc != NULL) ? (*pipe_sequence_loc) : (NULL);
	if (todel != NULL)
	{
		f_lstdel(&(todel->simple_command), &delete_simple_command);
		free(todel)
		pipe_sequence_loc = NULL;
	}
}
