/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:08:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/26 11:50:48 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include <fcntl.h>

static int	backup_stdfd(int stdfd_backup[2])
{
	if ((stdfd_backup[0] = dup(0)) != -1 || fcntl(0, F_GETFD) == -1)
	{
		if ((stdfd_backup[1] = dup(1)) != -1 || fcntl(1, F_GETFD) == -1)
			return (0);
		else if (stdfd_backup[0] != -1)
			close(stdfd_backup[0]);
	}
	ft_dprintf(2, "42sh: Unable to backup STDIN and STDOUT.\n");
	return (1);
}

static void	mark_as_child(struct s_sh_simple_command *const simple_command)
{
	if (simple_command != NULL)
		simple_command->child = TRUE;
}

static int	setup_next_pipe(void)
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

static int	spawn_pipe(t_lst *sequence, int pipe_in,
		struct s_shx_global *const global, int stdout_backup)
{
	t_lst	*next;
	pid_t	father;

	next = advance_list(sequence, 1);
	dup2(pipe_in, 0);
	if (pipe_in != 0)
		close(pipe_in);
	next != NULL ? pipe_in = setup_next_pipe() : dup2(stdout_backup, 1);
	father = fork();
	if (father == -1)
		return (1);
	else if (!father)
	{
		close(pipe_in);
		mark_as_child((void*)get_lst_elem(sequence, 0));
		exit(shx_simple_command((void*)get_lst_elem(sequence, 0), global));
	}
	if (next != NULL)
		(void)spawn_pipe(next, pipe_in, global, stdout_backup);
	wait_for_instance(father, (next == NULL), global);
	return (0);
}

int			shx_pipe_sequence(struct s_sh_pipe_sequence *const pipe_sequence,
		struct s_shx_global *const global)
{
	t_lst	*sequence;
	int		stdfd_backup[2];

	if (pipe_sequence && (sequence = pipe_sequence->simple_commands))
	{
		if (1 < f_lst_len(sequence))
		{
			if (backup_stdfd(stdfd_backup) == 0)
			{
				spawn_pipe(sequence, 0, global, stdfd_backup[1]);
				dup2(stdfd_backup[0], 0);
			}
		}
		else
			shx_simple_command((void*)get_lst_elem(sequence, 0), global);
	}
	return (0);
}