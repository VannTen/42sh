/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_aggregate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:03:03 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/28 18:19:02 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "redirection.h"

int	io_redir_aggregate(struct s_sh_io_redirect const *io_redir,
		t_lst **const fd_backups_loc)
{
	int	io_number;
	int	target_fd;

	if (!io_redir || !fd_backups_loc)
		ft_dprintf(STDERR_FILENO, "42sh: invalid args in %s.\n", __FUNCTION__);
	else if ((io_number = str_to_fd(io_redir->ionum)) == -1)
		ft_dprintf(STDERR_FILENO, "42sh: %s: bad file descriptor.\n",
				io_redir->ionum);
	else if ((target_fd = str_to_fd(io_redir->target)) == -1
			|| fcntl(target_fd, F_GETFD) == -1)
		ft_dprintf(STDERR_FILENO, "42sh: %s: bad file descriptor.\n",
				io_redir->target);
	else if (backup_filedescriptor(io_number, fd_backups_loc)
			|| saved_filedescriptor_conflict(target_fd, *fd_backups_loc))
		ft_dprintf(STDERR_FILENO, "42sh: failed to backup filedescriptor.\n");
	else if (dup2(target_fd, io_number) == -1)
		ft_dprintf(STDERR_FILENO, "42sh: error in aggregate redirection.\n");
	else
		return (0);
	return (1);
}
