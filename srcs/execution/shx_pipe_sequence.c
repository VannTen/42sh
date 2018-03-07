/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:08:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/07 12:45:46 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include "shell.h"
#include "redirection.h"

static t_bool	stdfd(int pipe_buf[2])
{
	pipe_buf[0] = STDIN_FILENO;
	pipe_buf[1] = STDOUT_FILENO;
	return (TRUE);
}

static pid_t	create_child(int pipe_in, int pipe_buf[2],
		struct s_sh_simple_command *simple_command, t_bool last_command)
{
	pid_t const	father = fork();

	if (!father)
	{
		close(pipe_buf[0]);
		dup2(pipe_in, STDIN_FILENO);
		if (pipe_in != STDIN_FILENO)
			close(pipe_in);
		dup2(pipe_buf[1], STDOUT_FILENO);
		if (pipe_buf[1] != STDOUT_FILENO)
			close(pipe_buf[1]);
		if (simple_command)
			simple_command->child = TRUE;
		exit(shx_simple_command(simple_command));
	}
	else
	{
		if (pipe_in != STDIN_FILENO)
			close(pipe_in);
		if (!last_command)
			close(pipe_buf[1]);
		return (father);
	}
}

static int		spawn_pipe(t_lst *sequence, int pipe_in)
{
	int		pipe_buf[2];
	t_lst	*next;
	pid_t	father;

	next = advance_list(sequence, 1);
	if (next != NULL ? !pipe(pipe_buf) : stdfd(pipe_buf))
	{
		father = create_child(pipe_in, pipe_buf,
				(void*)get_lst_elem(sequence, 0), next == NULL);
		if (0 < father)
		{
			if (next != NULL)
				spawn_pipe(next, pipe_buf[0]);
			wait_for_instance(father, (next == NULL));
			return (0);
		}
		else
		{
			close(pipe_buf[0]);
			ft_dprintf(2, "42sh: failed to fork.\n");
		}
	}
	else
		ft_dprintf(2, "42sh: failed to pipe.\n");
	return (42);
}

int				shx_pipe_sequence(
		struct s_sh_pipe_sequence *const pipe_sequence)
{
	t_lst	*sequence;

	if (pipe_sequence && (sequence = pipe_sequence->simple_commands))
	{
		if (1 < f_lst_len(sequence))
			spawn_pipe(sequence, STDIN_FILENO);
		else
			shx_simple_command((void*)get_lst_elem(sequence, 0));
	}
	return (0);
}
