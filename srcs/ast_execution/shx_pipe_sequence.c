/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:08:12 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/25 10:08:47 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/pipe_sequence.h"

static int	extend_sequence(void *const simple_command, int prevpipe_read)
{
	int		pipe[2];
	pid_t	father;

	if (!pipe[2])
	{
		father = fork();
		if (father)
		{
			close(prevpipe_read);
			close(pipe[1]);
			if (father == -1 || update_sequence_info(sequence_info, father))
			{
				close(pipe[0]);
				return (-1);
			}
			return (pipe[0]);
		}
		else if (!father)
		{
			close(pipe[0]);
			exit(setup_piped_instance(simple_command, prevpipe_read, pipe[1]));
		}
	}
	return (-1);
}

int			shx_pipe_sequence(struct s_pipe_sequence *const pipe_sequence)
{
	int		job_id;

	children = NULL;
	if (pipe_sequence != NULL)
	{
		job_id = create_job();
		if (0 <= job_id)
			return (pipe_sequence(pipe_sequence));
		else if (job_id == -1)
		carry_over = (simple_commands->next != NULL) ? 0 : -1;
		while (simple_commands->next != NULL)
		{
			carry_over = extend_sequence(simple_commands->content,
					carry_over, &children);
			if (carry_over == -1)
				return (-1);
			simple_commands = simple_commands->next;
		}
		return(end_sequence(simple_commands->content, carry_over,
					&children));
	}
	return (-1);
}
