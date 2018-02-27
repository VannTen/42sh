/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saved_filedescriptor_conflict.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 08:34:38 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:52:21 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_fd_backup.h"

t_bool	saved_filedescriptor_conflict(int fd, t_lst *fd_backups)
{
	struct s_fd_backup	*fd_backup;
	int					new_save;

	if (0 <= fd)
		while (fd_backups)
		{
			fd_backup = (void*)get_lst_elem(fd_backups, 0);
			if (fd_backup->save == fd)
			{
				new_save = dup(fd_backup->save);
				if (new_save != -1)
				{
					close(fd_backup->save);
					fd_backup->save = new_save;
					return (TRUE);
				}
			}
		}
	return (FALSE);
}
