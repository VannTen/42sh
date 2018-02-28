/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:40:46 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 18:19:57 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "redirection.h"

int	io_redir_file(struct s_sh_io_redirect const *const io_redir,
		t_lst **const fd_backups_loc)
{
	int	ret;
	int	io_number;
	int	target_fd;

	ret = -1;
	if (!io_redir || !fd_backups_loc)
		ft_dprintf(STDERR_FILENO, "42sh: %s: invalid parameters.\n",
				__FUNCTION__);
	else if (((io_number = str_to_fd(io_redir->ionum)) != -1)
		&& !backup_filedescriptor(io_number, fd_backups_loc))
	{
		target_fd = open(io_redir->target, io_redir->flags, io_redir->mode);
		if (target_fd != -1)
		{
			ret = dup2(target_fd, io_number);
			if (ret == -1)
				ft_dprintf(STDERR_FILENO, "42sh: %s: redirection failed.\n",
						io_redir->target);
			close(target_fd);
		}
		else
			ft_dprintf(STDERR_FILENO, "42sh: %s: failed to open file.\n",
					io_redir->target);
	}
	return (ret == -1);
}
