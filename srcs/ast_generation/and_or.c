/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 11:15:56 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/and_or.h"
#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include "ast_generation.h"
#include <stdlib.h>

void	*create_and_or(void const *lex_value)
{
	struct s_container	*container;
	struct s_sh_and_or	and_or;

	(void)lex_value;
	and_or.sequence = NULL;
	container = new_container(&and_or, &destroy_and_or, sizeof(and_or),
			e_ast_container_label_and_or);
	return (container);
}

static t_bool	extend_and_or(struct s_sh_and_or *const and_or,
		struct s_container *const pipeline_container)
{
	struct s_and_or_logic	*new;
	struct s_and_or_logic	*tmp;

	if (pipeline_container != NULL && pipeline_container->content != NULL
			&& (new = (struct s_and_or_logic *)malloc(sizeof(*new))) != NULL)
	{
		new->logic = e_logic_none;
		new->pipeline = pipeline_container->content;
		pipeline_container->content = NULL;
		new->next = NULL;
		tmp = and_or->sequence;
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			and_or->sequence = new;
		return (TRUE);
	}
	else
		return (FALSE);
}

static t_bool	set_logic(struct s_and_or_logic *logic,
		enum e_ast_container_label label)
{
	while (logic->next != NULL)
		logic = logic->next;
	if (label == e_ast_container_label_and_if)
		logic->logic = e_logic_and;
	else if (label == e_ast_container_label_or_if)
		logic->logic = e_logic_or;
	else
		return (FALSE);
	return (TRUE);
}

t_bool			give_and_or(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_sh_and_or	*and_or;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		and_or = ((struct s_container*)construct)->content;
		sub = sub_construct;
		if (and_or != NULL)
		{
			if (sub->label == e_ast_container_label_pipeline)
				ret = extend_and_or(and_or, sub);
			else
				ret = set_logic(and_or->sequence, sub->label);
			if (ret == TRUE)
				destroy_container((void**)&sub);
		}
	}
	return (ret);
}

static void	destroy_and_or_sequence(void **sequence_loc)
{
	struct s_and_or_logic	*sequence;
	struct s_and_or_logic	*todel;

	if (sequence_loc != NULL)
	{
		sequence = *sequence_loc;
		while (sequence != NULL)
		{
			todel = sequence;
			sequence = sequence->next;
			if (todel->pipeline != NULL)
				destroy_pipeline(&(todel->pipeline));
			free(todel);
		}
		*sequence_loc = NULL;
	}
}

void	destroy_and_or(void **const and_or_loc)
{
	struct s_sh_and_or		*todel;

	todel = (and_or_loc != NULL) ? (*and_or_loc) : (NULL);
	if (todel != NULL)
	{
		destroy_and_or_sequence((void**)&(todel->sequence));
		free(todel);
		*and_or_loc = NULL;
	}
}
