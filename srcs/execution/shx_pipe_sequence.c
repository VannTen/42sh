/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:08:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:46:44 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"

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
		struct s_shx_global *const global)
{
	t_lst	*next;
	pid_t	father;

	next = advance_list(sequence, 1);
	dup2(pipe_in, 0);
	if (pipe_in != 0)
		close(pipe_in);
	if (next != NULL)
		pipe_in = setup_next_pipe();
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
		(void)spawn_pipe(next, pipe_in, global);
	wait_for_instance(father, (next == NULL), global);
	return (0);
}

int			shx_pipe_sequence(struct s_sh_pipe_sequence *const pipe_sequence,
		struct s_shx_global *const global)
{
	if (pipe_sequence != NULL)
		spawn_pipe(pipe_sequence->simple_commands, 0, global);
	return (0);
}
