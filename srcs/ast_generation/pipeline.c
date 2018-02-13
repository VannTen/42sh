/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 13:03:36 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/pipeline.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "bool_interface.h"
#include <stdlib.h>

void	*create_pipeline(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_pipeline	pipeline;

	(void)lex_value;
	pipeline->pipe_sequence = NULL;
	pipeline->bang = FALSE;
	container = new_container(pipeline, sizeof(pipeline), e_ast_container_label_pipeline);
	return (container);
}

static t_bool	add_pipe_sequence(struct s_sh_pipeline *const pipeline,
		struct s_container *const pipe_sequence_container)
{
	if (pipeline != NULL && pipe_sequence_container != NULL
			&& pipeline->pipe_sequence == NULL
			&& pipe_sequence_container->content != NULL)
	{
		pipeline->pipe_sequence = pipe_sequence_container->content;
		pipe_sequence_container->content = NULL;
		return (TRUE);
	}
	return (FALSE);
}

t_bool			give_pipeline(void *construct, void *sub_construct)
{
	struct s_container		*sub;
	struct s_sh_pipeline	*pipeline;
	t_bool					ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		pipeline = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_pipe_sequence)
			ret = add_pipe_sequence(pipeline, sub);
		else if (sub->label == e_ast_container_label_bang)
		{
			pipeline->bang = TRUE;
			ret = TRUE;
		}
		else if (sub->label == e_ast_container_label_pipeline_preop)
			ret = TRUE;
		if (ret == TRUE)
			delete_container(&sub, NULL);
	}
	return (ret);
}

void	delete_pipeline(struct s_sh_pipeline **const pipeline_loc)
{
	struct s_sh_pipeline	*todel;

	todel = (pipeline_loc != NULL) ? (*pipeline_loc) : (NULL);
	if (todel != NULL)
	{
		delete_pipe_sequence(&(todel->pipe_sequence));
		free(todel)
		pipeline_loc = NULL;
	}
}
