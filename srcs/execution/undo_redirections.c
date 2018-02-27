/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:40:44 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:06:46 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_fd_backup.h"

static void	restore_filedescriptor(struct s_fd_backup const *const fd_backup)
{
	if (fd_backup)
	{
		if (fd_backup->save == -1)
			close(fd_backup->origin);
		else if (dup2(fd_backup->save, fd_backup->origin) == -1)
			ft_dprintf(2, "42sh: failed to restore filedescriptor %i.\n",
					fd_backup->origin);
	}
}

void		undo_redirections(t_lst **const fd_backups_loc)
{
	t_lst	*fd_backups;

	if (fd_backups_loc)
	{
		fd_backups = *fd_backups_loc;
		while (fd_backups)
		{
			restore_filedescriptor((void*)get_lst_elem(fd_backups, 0));
			fd_backups = advance_list(fd_backups, 1);
		}
		f_lstdel(fd_backups_loc, &ft_memdel);
	}
}
