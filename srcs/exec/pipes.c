/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:40:23 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 12:08:47 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

t_pipes	*init_pipes(void)
{
	t_pipes	*pipes;

	if (!(pipes = (t_pipes*)malloc(sizeof(t_pipes))))
		ft_error_msg("Malloc failed\n");
	pipes->pipes_fd = NULL;
	pipes->nb_pipes = 0;
	return (pipes);
}

int		get_pipes_fd(t_exec *exec, t_pipes *pipes)
{
	int	i;

	while (exec && exec->cmd_separator == PIPE)
	{
		exec = exec->next;
		pipes->nb_pipes++;
	}
	i = -1;
	if (pipes->nb_pipes)
	{
		if (!(pipes->pipes_fd = (int**)malloc(sizeof(int*) *
				(pipes->nb_pipes))))
			ft_error_msg("Malloc failed\n");
		while (++i < pipes->nb_pipes)
		{
			if (!(pipes->pipes_fd[i] = (int*)malloc(sizeof(int) * 2)))
				ft_error_msg("Malloc failed\n");
		}
	}
	return (pipes->nb_pipes);
}

void	create_pipes(t_pipes *pipes)
{
	int	i;

	i = -1;
	while (++i < pipes->nb_pipes)
	{
		if (pipe(pipes->pipes_fd[i]) < 0)
			ft_error_msg("Pipe failed\n");
	}
}

void	connect_processes_pipes(t_pipes *pipes, int i)
{
	if (!i)
	{
		if (dup2(pipes->pipes_fd[i][WRITE], STDOUT) < 0)
			ft_error_msg("Dup2 failed\n");
	}
	else if (i < pipes->nb_pipes)
	{
		if (dup2(pipes->pipes_fd[i - 1][READ], STDIN) < 0)
			ft_error_msg("Dup2 failed\n");
		if (dup2(pipes->pipes_fd[i][WRITE], STDOUT) < 0)
			ft_error_msg("Dup2 failed\n");
	}
	else
	{
		if (dup2(pipes->pipes_fd[i - 1][READ], STDIN) < 0)
			ft_error_msg("Dup2 failed\n");
	}
}
