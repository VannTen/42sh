/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:40:46 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:47:29 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "redirection.h"

int	io_redir_file(struct s_sh_io_redirect const *const io_redir,
		t_lst **const fd_backups_loc)
{
	int	io_number;
	int	target_fd;

	if (io_redir && fd_backups_loc
			&& (io_number = str_to_fd(io_redir->ionum)) != -1
			&& backup_filedescriptor(io_number, fd_backups_loc))
	{
		target_fd = open(io_redir->target, io_redir->flags, io_redir->mode);
		if (target_fd != -1)
		{
			if (dup2(target_fd, io_number) != -1)
			{
				close(target_fd);
				return (0);
			}
			close(target_fd);
		}
	}
	ft_dprintf(2, "42sh: error in redirection to %s\n", io_redir->target);
	return (1);
}
