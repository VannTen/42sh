/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_aggregate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:03:03 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:45:20 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "redirection.h"

int	io_redir_aggregate(struct s_sh_io_redirect const *io_redir,
		t_lst **const fd_backups_loc)
{
	int	io_number;
	int	target_fd;

	if (io_redir && fd_backups_loc
			&& (io_number = str_to_fd(io_redir->ionum)) != -1
			&& (target_fd = str_to_fd(io_redir->target)) != -1
			&& backup_filedescriptor(io_number, fd_backups_loc)
			&& !saved_filedescriptor_conflict(target_fd, *fd_backups_loc))
	{
		if (dup2(target_fd, io_number) != -1)
			return (0);
	}
	ft_dprintf(2, "42sh: error in aggregate redirection.\n");
	return (1);
}
