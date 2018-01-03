/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_restore_fds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:36:59 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/18 15:40:07 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void	save_fds(int *saved_fd)
{
	if ((saved_fd[0] = dup(STDIN)) < 0)
		ft_error_msg("Dup failed\n");
	if ((saved_fd[1] = dup(STDOUT)) < 0)
		ft_error_msg("Dup failed\n");
	if ((saved_fd[2] = dup(STDERR)) < 0)
		ft_error_msg("Dup failed\n");
}

void	restore_fds(int *saved_fd)
{
	dup2(saved_fd[0], STDIN);
	dup2(saved_fd[1], STDOUT);
	dup2(saved_fd[2], STDERR);
}
