/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:08:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 11:48:52 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/pipe_sequence.h"

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
	if (pipe[1] != 1)
	{
		dup2(pipe[1], 1);
		close(pipe[1]);
	}
	return (pipe[0]);
}

static int	spawn_pipe(t_list	*sequence, int pipe_in,
		struct s_shx_global *const global)
{
	t_bool const	last_pipe = (sequence->next == NULL);
	pid_t			father;

	dup2(pipe_in, 0);
	if (pipe_in != 0)
		close(pipe_in);
	if (!last_pipe)
		pipe_in = setup_next_pipe();
	father = fork();
	if (father == -1)
		return (1);
	else if (!father)
	{
		close(pipe_in);
		mark_as_child(sequence->content);
		exit(shx_simple_command(sequence->content, global));
	}
	(void)spawn_pipe(sequence->next, pipe_in, global);
	wait_for_instance(father, last_pipe, global);
	return (0);
}

int			shx_pipe_sequence(struct s_sh_pipe_sequence *const pipe_sequence,
		struct s_shx_global *const global)
{
	t_list	*sequence;

	if (pipe_sequence != NULL)
	{
		sequence = pipe_sequence->simple_commands;
		if (sequence == NULL)
			return (0);
		else if (sequence->next == NULL)
			global.latest_ret = shx_simple_command(sequence->content, global);
		else
			return(spawn_pipe(sequence, 0, global));
	}
	return (0);
}
