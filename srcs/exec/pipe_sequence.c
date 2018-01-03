/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:08:24 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 12:56:09 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static void	close_pipes_fds(t_pipes *pipes)
{
	int	i;

	i = -1;
	while (++i < pipes->nb_pipes)
	{
		close(pipes->pipes_fd[i][READ]);
		close(pipes->pipes_fd[i][WRITE]);
	}
}

static void	pipes_loop(t_bsh *bsh, t_exec **exec, int *pid, int *k)
{
	int	i;

	i = -1;
	while (++i <= bsh->pipes->nb_pipes)
	{
		(*exec)->cmd = expand_words(bsh->exp, *exec);
		expand_filenames(bsh->exp, *exec);
		if ((pid[*k] = fork()) < 0)
			ft_error_msg("Fork failed\n");
		if (!pid[(*k)++])
		{
			connect_processes_pipes(bsh->pipes, i);
			close_pipes_fds(bsh->pipes);
			if (((*exec)->is_builtin = cmd_is_builtin((*exec)->cmd)) > -1)
			{
				launch_builtin(bsh, *exec, 0);
				exit(bsh->exit_status);
			}
			else
				run_binary(*exec, bsh->env, 0);
		}
		if (i < bsh->pipes->nb_pipes)
			*exec = (*exec)->next;
	}
}

void		pipe_sequence(t_exec **exec, t_pipes *pipes)
{
	int		i;
	int		*pid;
	int		k;
	t_bsh	*bsh;

	bsh = get_bsh();
	k = 0;
	create_pipes(pipes);
	if (!(pid = (int*)malloc((pipes->nb_pipes + 1) * sizeof(int))))
		ft_error_msg("Malloc failed\n");
	pipes_loop(bsh, exec, pid, &k);
	close_pipes_fds(bsh->pipes);
	reset_signals();
	i = 0;
	while (i <= k)
		waitpid(pid[i++], &bsh->exit_status, 0);
	set_signals();
	ft_memdel((void**)&pid);
}
