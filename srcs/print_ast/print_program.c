/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:18:03 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/14 10:38:48 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast.h"
#include "io_redirect_settings.h"
#include "bleberr_macros.h"
#include "libft.h"
#include "print_ast.h"

t_bool		io_cmp(struct s_io_param *a,
		struct s_sh_io_redirect *b)
{
	if (a != NULL && b != NULL
			&&a->type == b->type
			&& a->flags == b->flags
			&& a->mode == b->mode
			&& a->variant == b->variant)
		return (TRUE);
	else
		return (FALSE);
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
	while (i < ARRLEN(refs) && io_cmp(refs + i, io_redirect))
		i += 1;
	return (opstr_array[i]);
}

void	print_io_redirect(int fd, struct s_sh_io_redirect *io_redirect, int depth,
		char const *const depth_padding)
{
	char const	*opstr;

	ft_dprintf(fd, "%.*sio_redirect: %s\n", depth, depth_padding,
			io_redirect ? "OK" : "NULL");
	opstr = deduce_op(io_redirect);
	ft_dprintf(fd, "%.*s%s %s %s\n", depth + 1, depth_padding, io_redirect->ionum, opstr,
			io_redirect->target);
}

void	print_simple_command(int fd, struct s_sh_simple_command *simple_command, int depth,
		char const *const depth_padding)
{
	t_lst	*list;
	void	*content;

	ft_dprintf(fd, "%.*ssimple_command: %s has %zu args\n", depth, depth_padding,
			simple_command ? "OK" : "NULL", simple_command->argc);
	if (simple_command != NULL)
	{
		list = simple_command->arglist;
		while (list != NULL)
		{
			content = (void*)f_lst_first_elem(list);
			ft_dprintf(fd, "%.*s%s\n", depth + 1, depth_padding,
					(content != NULL) ? content : "NULL");
			list = advance_list(list, 1);
		}
		list = simple_command->redirs;
		while (list != NULL)
		{
			print_io_redirect(fd, (void*)f_lst_first_elem(list), depth + 1,
				depth_padding);
			list = advance_list(list, 1);
		}
	}
}

void	print_pipe_sequence(int fd, struct s_sh_pipe_sequence *pipe_sequence, int depth,
		char const *const depth_padding)
{
	t_lst	*sequence;

	ft_dprintf(fd, "%.*spipe_sequence: %s\n", depth, depth_padding,
			pipe_sequence ? "OK" : "NULL");
	if (pipe_sequence != NULL)
	{
		sequence = pipe_sequence->simple_commands;
		while (sequence != NULL)
		{
			print_simple_command(fd, (void*)f_lst_first_elem(sequence), depth + 1,
				depth_padding);
			sequence = advance_list(sequence, 1);
		}
	}
}

void	print_pipeline(int fd, struct s_sh_pipeline *pipeline, int depth,
		char const *const depth_padding)
{
	ft_dprintf(fd, "%.*spipeline: %s", depth, depth_padding,
			pipeline ? "OK" : "NULL\n");
	if (pipeline != NULL)
	{
		ft_dprintf(fd, " %sBang\n", pipeline->bang ? "" : "no");
		print_pipe_sequence(fd, pipeline->pipe_sequence, depth + 1,
				depth_padding);
	}
}

void	print_and_or(int fd, struct s_sh_and_or *and_or, int depth,
		char const *const depth_padding)
{
	struct s_and_or_logic	*logic;
	char const				*str;

	ft_dprintf(fd, "%.*sand_or: %s\n", depth, depth_padding,
			and_or ? "OK" : "NULL");
	if (and_or != NULL)
	{
		logic = and_or->sequence;
		while (logic != NULL)
		{
			print_pipeline(fd, logic->pipeline, depth + 1,
				depth_padding);
			if (logic->logic == e_logic_and)
				str = "&&";
			else if (logic->logic == e_logic_or)
				str = "||";
			else
				str = "INVALID";
			ft_dprintf(fd, "%.*slogic: %s\n", depth + 1, depth_padding,
					str);
			logic = logic->next;
		}
	}
}

void	print_lst(int fd, struct s_sh_list *list, int depth,
		char const *const depth_padding)
{
	t_lst	*sequence;

	ft_dprintf(fd, "%.*slist: %s\n", depth, depth_padding,
			list ? "OK" : "NULL");
	if (list != NULL)
	{
		sequence = list->and_or_sequence;
		while (sequence != NULL)
		{
			print_and_or(fd, (void*)f_lst_first_elem(sequence), depth + 1,
				depth_padding);
			sequence = advance_list(sequence, 1);
		}
	}
}

void	print_complete_command(int fd,
		struct s_sh_complete_command *complete_command, int depth,
		char const *const depth_padding)
{
	ft_dprintf(fd, "%.*scomplete_command: %s\n", depth, depth_padding,
			complete_command ? "OK" : "NULL");
	if (complete_command != NULL)
		print_lst(fd, complete_command->list, depth + 1,
				depth_padding);
}

void	print_complete_commands(int fd,
		struct s_sh_complete_commands *complete_commands, int depth,
		char const *const depth_padding)
{
	t_lst	*sequence;

	ft_dprintf(fd, "%.*scomplete_commands: %s\n", depth, depth_padding,
			complete_commands ? "OK" : "NULL");
	if (complete_commands)
	{
		sequence = complete_commands->sequence;
		while (sequence != NULL)
		{
			print_complete_commands(fd, (void*)f_lst_first_elem(sequence), depth + 1,
				depth_padding);
			sequence = advance_list(sequence, 1);
		}
	}
}

void	print_program(int fd, struct s_sh_program *program, int depth)
{
	char	depth_padding[MAX_AST_DEPTH + 1];

	ft_memset(depth_padding, '|', MAX_AST_DEPTH);
	depth_padding[MAX_AST_DEPTH] = 0;
	ft_dprintf(fd, "%.*sprogram: %s\n", depth, depth_padding,
			program ? "OK" : "NULL");
	if (program != NULL)
	{
		print_complete_commands(fd, program->complete_commands, depth + 1,
				depth_padding);
	}
}
