/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:31:29 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 23:12:48 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_ast.h"
#include "heredoc_creation.h"

static int	create_redir_list_heredocs(t_lst *redir_list)
{
	t_lst *const			redir_list_start = redir_list;
	struct s_sh_io_redirect	*io_redirect;
	char					*path;

	while (redir_list)
	{
		io_redirect = (void*)get_lst_elem(redir_list, 0);
		if (io_redirect->type == e_sh_io_type_here)
		{
			path = create_heredoc(io_redirect->target, io_redirect->variant);
			if (!path)
			{
				unlink_redir_list_heredocs(redir_list_start, redir_list);
				return (1);
			}
			else
			{
				ft_strdel(&io_redirect->target);
				io_redirect->target = path;
			}
		}
		redir_list = advance_list(redir_list, 1);
	}
	return (0);
}

static int	create_pipe_sequence_heredocs(
		struct s_sh_pipe_sequence *pipe_sequence)
{
	t_lst						*simple_commands;
	struct s_sh_simple_command	*simple_command;

	if (pipe_sequence)
	{
		simple_commands = pipe_sequence->simple_commands;
		while (simple_commands)
		{
			simple_command = (void*)get_lst_elem(simple_commands, 0);
			if (create_redir_list_heredocs(simple_command->redirs))
			{
				unlink_simple_commands_heredocs(pipe_sequence->simple_commands,
						simple_commands);
				return (1);
			}
			simple_commands = advance_list(simple_commands, 1);
		}
	}
	return (0);
}

static int	create_and_or_heredocs(struct s_sh_and_or *and_or)
{
	struct s_and_or_logic		*logic;
	struct s_sh_pipe_sequence	*pipe_sequence;

	if (and_or)
	{
		logic = and_or->sequence;
		while (logic)
		{
			if (logic->pipeline)
			{
				pipe_sequence = logic->pipeline->pipe_sequence;
				if (create_pipe_sequence_heredocs(pipe_sequence))
				{
					unlink_and_or_logic_heredocs(and_or->sequence, logic);
					return (1);
				}
			}
			logic = logic->next;
		}
	}
	return (0);
}

int	create_all_heredocs(struct s_sh_program *program)
{
	t_lst	*and_or_sequence;

	if (program && program->complete_command && program->complete_command->list)
	{
		and_or_sequence = program->complete_command->list->and_or_sequence;
		while (and_or_sequence)
		{
			if (create_and_or_heredocs((void*)get_lst_elem(and_or_sequence, 0)))
			{
				unlink_and_or_sequence_heredocs(
						program->complete_command->list->and_or_sequence,
						and_or_sequence);
				return (1);
			}
			and_or_sequence = advance_list(and_or_sequence, 1);
		}
	}
	return (0);
}
