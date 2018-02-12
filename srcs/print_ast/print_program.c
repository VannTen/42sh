/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:18:03 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/12 18:43:22 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast.h"

t_bool		io_redirect_cmp(struct s_sh_io_redirect *a,
		struct s_sh_io_redirect *b)
{
	if (a != NULL && b != NULL
			&&a->type == b->type
			&& a->flags == b->flags
			&& a->mode == b->mode
			&& a->variant == b->variant)
		return (TRUE);
	else
		return (FALSE)
}

char const	*deduce_op(struct s_sh_io_redirect *io_redirect)
{
	struct s_io_param	refs[] = { CLOBBER_PARAM, GREAT_PARAM, DGREAT_PARAM,
		LESSGREAT_PARAM, LESS_PARAM, DLESS_PARAM, DLESSDASH_PARAM,
		GREATAND_PARAM, LESSAND_PARAM };
	char const			*const opstr_array[] = { ">|", ">", ">>", "<>", "<",
		"<<", "<<-", ">&", "<&", "ERROR" };
	size_t				i;

	i = 0;
	while (i < ARRLEN(refs) && io_redirect_cmp(refs + i, io_redirect))
		i += 1;
	return (opstr_array[i]);
}

void	print_io_redirect(int fd, struct s_sh_io_redirect *io_redirect)
{
	char const	*opstr;

	opstr = deduce_op(io_redirect);
	ft_dprintf(fd, "|||||%s %s %s\n", io_redirect->ionum, opstr,
			io_redirect->target);
}

void	print_simple_command(int fd, struct s_sh_simple_command *simple_command)
{
	t_list	*list;

	if (simple_command != NULL)
	{
		ft_dprintf(fd, "|||simple_command: has %zu args\n", simple_command->argc);
		list = simple_command->arglist;
		ft_dprintf(fd, "||||args:\n");
		while (list != NULL)
		{
			ft_dprintf(fd, "|||||%s\n",
					(list->content != NULL) ? list->content : "NULL");
			list = list->next;
		}
		list = simple_command->redirs;
		ft_dprintf(fd, "||||redirs:\n");
		while (list != NULL)
		{
			print_io_redirect(fd, list->content);
			list = list->next;
		}
	}
}

void	print_pipe_sequence(int fd, struct s_sh_pipe_sequence *pipe_sequence)
{
	t_list	*sequence;

	if (pipe_sequence != NULL)
	{
		sequence = pipe_sequence->simple_commands;
		while (sequence != NULL)
		{
			print_simple_command(fd, sequence->content);
			sequence = sequence->next;
		}
	}
}

void	print_pipeline(int fd, struct s_sh_pipeline *pipeline)
{
	if (pipeline != NULL)
	{
		ft_dprintf(fd, "||pipeline: %sbang\n", pipeline->bang ? "" : "no");
		print_pipe_sequence(fd, pipeline->pipe_sequence);
	}
}

void	print_and_or(int fd, struct s_sh_and_or *and_or)
{
	struct s_and_or_logic	*logic;
	char const				*str;

	if (and_or != NULL)
	{
		logic = and_or->logic;
		while (logic != NULL)
		{
			if (logic->logic == e_logic_and)
				str = "&&";
			else if (logic->logic == e_logic_or)
				str = "||";
			else
				str = "ERROR"
			ft_dprintf(fd, "|and_or: %s\n", str);
			print_pipeline(fd, logic->pipeline);
			logic = logic->next;
		}
	}
}

void	print_list(int fd, struct s_sh_list *list)
{
	t_list	*sequence;

	if (list != NULL)
	{
		sequence = list->and_or_sequence;
		while (sequence != NULL)
		{
			print_and_or(fd, sequence->content);
			sequence = sequence->next;
		}
	}
}

void	print_complete_command(int fd,
		struct s_sh_complete_command *complete_command)
{
	ft_dprintf(fd, "complete_command:\n");
	if (complete_command != NULL)
		print_list(fd, complete_command->list);
}

void	print_complete_commands(int fd,
		struct s_sh_complete_commands *complete_commands)
{
	t_list	*sequence;

	if (complete_commands)
	{
		sequence = complete_commands->sequence;
		while (sequence != NULL)
		{
			print_complete_commands(fd, sequence->content);
			sequence = sequence->next;
		}
	}
}

void	print_program(int fd, struct s_sh_program *program)
{
	if (program != NULL)
		print_complete_commands(fd, program->complete_commands);
}
