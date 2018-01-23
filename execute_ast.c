/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:38:09 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/22 17:09:36 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast.h"
#include "shell_pipe_sequence.h"

int			setup_piped_instance(void *const simple_command, int read_fd,
		int write_fd)
{
	if ((read_fd != 0 && dup2(read_fd, 0) == -1)
			|| (write_fd != 1 && dup2(write_fd, 1) == -1))
	{
		ft_putstr_fd("21sh: failed to redirect to pipe.\n", 2);
		return (-1);
	}
	set_child(simple_command);
	return (shx_simple_command(simple_command));
}

/*
** -----------------------------------------------------------------------------
*/

int			end_sequence(void *const simple_command, int prevpipe_read)
{
	pid_t	father;

	if (prevpipe_read == -1)
		return (shx_simple_command(simple_command));
	if (0 < (father = fork()))
		waitpid(father, );
	else if (!father)
		exit(setup_piped_instance(simple_command, prevpipe_read));
	else if (father == -1)
		return (-1);
}

/*
** -----------------------------------------------------------------------------
*/

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
	t_list	*children;
	t_list	*simple_commands;
	int		carry_over;

	children = NULL;
	if (pipe_sequence != NULL)
	{
		simple_commands = pipe_sequence->simple_commands;
		if (simple_commands != NULL)
		{
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
		return (0);
	}
	return (-1);
}

/*
** -----------------------------------------------------------------------------
*/

int	shx_and_or_list(struct s_and_or *const and_or)
{
	t_list	*tmp;
	int		ret;

	if (and_or != NULL)
	{
		tmp = and_or->pipe_sequences;
		while (tmp != NULL)
		{
			ret = shx_pipe_sequence(tmp->content);
			if (tmp->next != NULL && continue_logic(tmp->next->content, ret))
				tmp = tmp->next->next;
			else
				break;
		}
		return (ret);
	}
	else
		return (-1);
}

/*
** -----------------------------------------------------------------------------
*/

int	shx_program(struct s_program *const program)
{
	t_list	*and_or_list;
	int		ret;

	if (program != NULL)
	{
		and_or_list = program->and_or_list;
		while (and_or_list != NULL)
		{
			ret = shx_and_or_list(and_or_list->content);
			and_or_list = and_or_list->next;
		}
		return (ret);
	}
	else
		return (-1)
}
