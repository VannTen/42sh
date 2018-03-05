/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_all_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:00:19 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 22:36:33 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_ast.h"
#include <unistd.h>

void	unlink_redir_list_heredocs(t_lst *redir_lst, t_lst *endpoint)
{
	struct s_sh_io_redirect	*io_redirect;

	while (redir_lst && redir_lst != endpoint)
	{
		io_redirect = (void*)get_lst_elem(redir_lst, 0);
		if (io_redirect && io_redirect->type == e_sh_io_type_here)
			unlink(io_redirect->target);
		redir_lst = advance_list(redir_lst, 1);
	}
}

void	unlink_simple_commands_heredocs(t_lst *simple_command_lst,
		t_lst *endpoint)
{
	struct s_sh_simple_command	*simple_command;

	while (simple_command_lst && simple_command_lst != endpoint)
	{
		simple_command = (void*)get_lst_elem(simple_command_lst, 0);
		if (simple_command)
			unlink_redir_list_heredocs(simple_command->redirs, NULL);
		simple_command_lst = advance_list(simple_command_lst, 1);
	}
}

void	unlink_and_or_logic_heredocs(struct s_and_or_logic *logic,
		struct s_and_or_logic *endpoint)
{
	while (logic && logic != endpoint)
	{
		if (logic->pipeline && logic->pipeline->pipe_sequence)
			unlink_simple_commands_heredocs(
					logic->pipeline->pipe_sequence->simple_commands, NULL);
		logic = logic->next;
	}
}

void	unlink_and_or_sequence_heredocs(t_lst *and_or_sequence, t_lst *endpoint)
{
	struct	s_sh_and_or	*and_or;

	while (and_or_sequence && and_or_sequence != endpoint)
	{
		and_or = (void*)get_lst_elem(and_or_sequence, 0);
		if (and_or)
			unlink_and_or_logic_heredocs(and_or->sequence, NULL);
		and_or_sequence = advance_list(and_or_sequence, 1);
	}
}
