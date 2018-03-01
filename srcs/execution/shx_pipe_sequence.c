/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:08:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 16:57:00 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include <fcntl.h>
#include "shell.h"

static int		backup_stdfd(int stdfd_backup[2])
{
	if ((stdfd_backup[0] = dup(STDIN_FILENO)) != -1
			|| fcntl(STDIN_FILENO, F_GETFD) == -1)
	{
		stdfd_backup[1] = stdfd_backup[0] == STDOUT_FILENO ?
			-1 : dup(STDOUT_FILENO);
		if (stdfd_backup[1] != -1
				|| stdfd_backup[0] == STDOUT_FILENO
				|| fcntl(STDOUT_FILENO, F_GETFD) == -1)
			return (0);
		close(stdfd_backup[0]);
	}
	ft_dprintf(2, "42sh: Unable to backup STDIN and STDOUT.\n");
	return (1);
}

static int		setup_next_pipe(void)
{
	int	pipe_buf[2];

	if (pipe(pipe_buf) == -1)
		return (-1);
	if (pipe_buf[1] != 1)
	{
		dup2(pipe_buf[1], 1);
		close(pipe_buf[1]);
	}
	return (pipe_buf[0]);
}

static pid_t	create_child(int pipe_in, int stdfd_backup[2],
		struct s_sh_simple_command *simple_command)
{
	pid_t	father;

	if (!(father = fork()))
	{
		close(pipe_in);
		close(stdfd_backup[0]);
		close(stdfd_backup[1]);
		if (simple_command)
			simple_command->child = TRUE;
		exit(shx_simple_command(simple_command));
	}
	else
	{
		close(STDIN_FILENO);
		return (father);
	}
}

static int		spawn_pipe(t_lst *sequence, int pipe_in, int stdfd_backup[2])
{
	t_lst	*next;
	pid_t	father;

	next = advance_list(sequence, 1);
	dup2(pipe_in, STDIN_FILENO);
	if (pipe_in != STDIN_FILENO)
		close(pipe_in);
	next != NULL ?
		pipe_in = setup_next_pipe() : dup2(stdfd_backup[1], STDOUT_FILENO);
	father = create_child(pipe_in, stdfd_backup,
			(void*)get_lst_elem(sequence, 0));
	if (0 < father)
	{
		if (next != NULL)
			(void)spawn_pipe(next, pipe_in, stdfd_backup);
		wait_for_instance(father, (next == NULL));
		return (0);
	}
	close(pipe_in);
	ft_dprintf(2, "42sh: failed to fork.\n");
	dup2(stdfd_backup[1], STDOUT_FILENO);
	return (42);
}

int				shx_pipe_sequence(
		struct s_sh_pipe_sequence *const pipe_sequence)
{
	t_lst	*sequence;
	int		stdfd_backup[2];

	if (pipe_sequence && (sequence = pipe_sequence->simple_commands))
	{
		if (1 < f_lst_len(sequence))
		{
			if (backup_stdfd(stdfd_backup) == 0)
			{
				spawn_pipe(sequence, 0, stdfd_backup);
				dup2(stdfd_backup[0], 0);
				close(stdfd_backup[0]);
				close(stdfd_backup[1]);
			}
		}
		else
			shx_simple_command((void*)get_lst_elem(sequence, 0));
	}
	return (0);
}
