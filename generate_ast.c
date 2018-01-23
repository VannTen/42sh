/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:33:52 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/19 12:03:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast.h"

static void	split_one(t_list **const split_loc, t_list **const elem_loc)
{
	t_list	*tmp;

	if (split_loc != NULL && elem_loc != NULL && *elem_loc != NULL)
	{
		tmp = *elem_loc;
		*elem_loc = tmp->next;
		tmp->next = *split_loc;
		*split_loc = tmp;
	}
}

t_list		*split_list(t_list **const lst_loc, int (*ft)(t_list *elem))
{
	t_list	*lst;
	t_list	*split;

	split = NULL;
	if (lst_loc != NULL)
	{
		lst = *lst_loc;
		while (lst != NULL && ft(lst))
			split_one(&split, &lst);
		*lst_loc = lst;
		if (lst != NULL)
			while (lst->next != NULL)
				if (ft(lst->next))
					split_one(&split, &(lst->next));
				else
					lst = lst->next;
		if (split != NULL)
			ft_lstrev(split);
	}
	return (split);
}

/*
** -----------------------------------------------------------------------------
*/

void	*astgen_program(t_list **const lst_loc)
{
	struct s_program	*program;
	t_list				*and_or_list;

	if (lst_loc != NULL)
	{
		program = malloc(sizeof(struct s_program));
		if (program != NULL)
		{
			and_or_list = split_list(lst_loc, &contains_and_or);
			program->and_or_list = and_or_list;
			ft_lstdel(lst_loc, del_token);
			*lst_loc = NULL
		}
		return (program);
	}
	else
		return (NULL);
}

void	*astgen_and_or(t_list **const lst_loc)
{
	struct s_and_or	*and_or;
	t_list			*linebreak_list;

	if (lst_loc != NULL)
	{
		and_or = malloc(sizeof(struct s_and_or));
		if (and_or != NULL)
		{
			linebreak_list = split_list(lst_loc, &contains_linebreak);
			and_or->pipe_sequences = *lst_loc;
			ft_lstdel(&linebreak_list, &del_linebreak);
			*lst_loc = NULL;
		}
		return (and_or);
	}
	else
		return (NULL);
}

void	*astgen_pipe_sequence(t_list **const lst_loc)
{
	struct s_pipe_sequence	*pipe_sequence;
	t_list					simple_commands;

	if (lst_loc != NULL)
	{
		pipe_sequence = malloc(sizeof(struct s_pipe_sequence));
		if (pipe_sequence != NULL)
		{
			simple_commands = split_list(lst_loc, &contains_simple_command);
			pipe_sequence->simple_commands = simple_commands;
			ft_lstdel(lst_loc, &del_token);
		}
	}
	else
		return (NULL);
}

void	*astgen_simple_command(t_list **const lst_loc)
{
	struct s_simple_command	*simple_command;
	t_list					*tmp;

	if (lst_loc)
}
