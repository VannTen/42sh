/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:42:41 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:45:50 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int		dup_fds(int fd, int redir_fd)
{
	if (redir_fd > 4863)
	{
		ft_putendl_fd("bsh : Bad file descriptor", STDERR);
		return (1);
	}
	if (dup2(fd, redir_fd) < 0)
	{
		ft_putendl_fd("dup2 failed\n", STDERR);
		return (1);
	}
	return (0);
}

int		redir_great(t_redir *redir)
{
	int	fd;

	fd = 0;
	(redir->fd == -1) ? redir->fd = STDOUT : 0;
	if (!access(redir->filename, F_OK) &&
			check_access_writing(redir->filename))
		return (1);
	if ((fd = open(redir->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
		return (1);
	if (dup_fds(fd, redir->fd))
		return (1);
	close(fd);
	return (0);
}

int		redir_dgreat(t_redir *redir)
{
	int	fd;

	fd = 0;
	(redir->fd == -1) ? redir->fd = STDOUT : 0;
	if (!access(redir->filename, F_OK) &&
			check_access_writing(redir->filename))
		return (1);
	if ((fd = open(redir->filename, O_CREAT | O_WRONLY | O_APPEND, 0644)) < 0)
	{
		ft_putendl_fd("Open failed", STDERR);
		return (1);
	}
	if (dup_fds(fd, redir->fd))
		return (1);
	close(fd);
	return (0);
}

int		redir_less(t_redir *redir)
{
	int	fd;

	fd = 0;
	(redir->fd == -1) ? redir->fd = STDIN : 0;
	if (check_access_exist(redir->filename) ||
			check_access_reading(redir->filename))
		return (1);
	if ((fd = open(redir->filename, O_RDONLY, 0644)) < 0)
	{
		ft_putendl_fd("Open failed\n", STDERR);
		return (1);
	}
	if (dup_fds(fd, redir->fd))
		return (1);
	close(fd);
	return (0);
}
