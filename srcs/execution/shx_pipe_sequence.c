/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:08:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/22 15:36:37 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include "shell.h"
#include "redirection.h"
#include "shx_pipe_sequence.h"

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

static int		continue_sequence(t_lst *next, int pipe_in, int child_pid)
{
	int	ret;

	if (next != NULL)
	{
		ret = spawn_pipe(next, pipe_in);
		wait_for_instance(child_pid);
	}
	else
		ret = wait_for_instance(child_pid);
	return (ret);
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
			return (continue_sequence(next, pipe_buf[0], father));
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
	t_lst			*sequence;
	int				ret;

	if (pipe_sequence && (sequence = pipe_sequence->simple_commands))
	{
		if (1 < f_lst_len(sequence))
			ret = spawn_pipe(sequence, STDIN_FILENO);
		else
			ret = shx_simple_command((void*)get_lst_elem(sequence, 0));
		return (ret);
	}
	return (0);
}
