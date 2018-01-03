/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:50:33 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/21 15:03:58 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

extern const t_builtins	g_builtins[];

int			run_builtin(t_exec *exec, int offset)
{
	t_bsh	*bsh;

	bsh = get_bsh();
	if (handle_redirection(exec))
	{
		bsh->exit_status = 1;
		return (1);
	}
	if (exec->cmd + offset)
	{
		if (bsh->mod_env)
			return (g_builtins[exec->is_builtin].builtin(&bsh->mod_env,
						exec->cmd + offset));
		else
			return (g_builtins[exec->is_builtin].builtin(&bsh->env,
						exec->cmd + offset));
	}
	return (0);
}

static void	get_exit_status(t_bsh *bsh, t_exec *exec)
{
	if (WIFEXITED(bsh->exit_status) && exec->is_builtin == -1)
		bsh->exit_status = WEXITSTATUS(bsh->exit_status);
	else if (WIFSIGNALED(bsh->exit_status) && exec->is_builtin == -1)
		bsh->exit_status = WTERMSIG(bsh->exit_status) + 128;
}

t_exec		*go_to_next_command(t_bsh *bsh, t_exec *exec)
{
	if (exec->cmd_separator == AND_IF && bsh->exit_status)
	{
		while (exec->cmd_separator == AND_IF)
		{
			exec = exec->next;
			while (exec && exec->cmd_separator == PIPE)
				exec = exec->next;
		}
	}
	if (exec->cmd_separator == OR_IF && !bsh->exit_status)
	{
		while (exec->cmd_separator == OR_IF)
		{
			exec = exec->next;
			while (exec && exec->cmd_separator == PIPE)
				exec = exec->next;
		}
	}
	exec = (exec) ? exec->next : exec;
	return (exec);
}

static void	clear_pipes(t_pipes *pipes)
{
	int		i;

	i = -1;
	while (++i < pipes->nb_pipes)
		ft_memdel((void**)&(pipes->pipes_fd[i]));
	ft_memdel((void**)pipes);
	pipes->nb_pipes = 0;
}

void		execution(t_bsh *bsh)
{
	t_exec	*exec;

	exec = bsh->exec;
	if (handle_heredocs(bsh->exec) == CATCH_SIGINT)
		return ;
	(bsh->interactive) ? restore_initial_attr(bsh->term) : 0;
	while (exec)
	{
		if (get_pipes_fd(exec, bsh->pipes))
		{
			pipe_sequence(&exec, bsh->pipes);
			clear_pipes(bsh->pipes);
		}
		else
			simple_command(bsh, exec);
		(exec->is_builtin < 0) ? get_exit_status(bsh, exec) : 0;
		exec = go_to_next_command(bsh, exec);
	}
	(bsh->interactive) ? restore_custom_attr(bsh->term) : 0;
}
