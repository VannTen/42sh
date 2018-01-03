/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:32:52 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:04:49 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static void	fork_and_exec(t_bsh *bsh, t_exec *exec, int offset)
{
	if ((g_pid = fork()) < 0)
		ft_error_msg("Fork failed\n");
	if (!g_pid)
		run_binary(exec, (bsh->mod_env || IS_OPTION(bsh->env_options, 'i')) ?
					bsh->mod_env : bsh->env, offset);
	reset_signals();
	(exec->is_builtin == -1) ? waitpid(g_pid, &bsh->exit_status, 0) : 0;
	bsh->env_index = -1;
	clear_env(&bsh->mod_env);
	set_signals();
}

void		launch_builtin(t_bsh *bsh, t_exec *exec, int offset)
{
	save_fds(bsh->saved_fds);
	bsh->exit_status = run_builtin(exec, offset);
	if (bsh->exit_status != 0)
		bsh->env_index = -1;
	restore_fds(bsh->saved_fds);
	while (bsh->env_index > -1 && exec->cmd[bsh->env_index])
	{
		if ((exec->is_builtin = cmd_is_builtin(exec->cmd +
						bsh->env_index)) == 2)
			launch_builtin(bsh, exec, bsh->env_index);
		else
		{
			exec->is_builtin = -1;
			fork_and_exec(bsh, exec, bsh->env_index);
			return ;
		}
	}
}

void		simple_command(t_bsh *bsh, t_exec *exec)
{
	exec->cmd = expand_words(bsh->exp, exec);
	expand_filenames(bsh->exp, exec);
	if ((exec->is_builtin = cmd_is_builtin(exec->cmd)) > -1)
		launch_builtin(bsh, exec, 0);
	else
		fork_and_exec(bsh, exec, 0);
	bsh->env_index = -1;
	ft_bzero(bsh->env_options, 3);
	clear_env(&bsh->mod_env);
}
