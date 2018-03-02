/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filedescriptor_is_a_backup.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:49:17 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/02 12:59:08 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_fd_backup.h"

t_bool	filedescriptor_is_a_backup(int fd, t_lst *fd_backup_lst)
{
	struct s_fd_backup	*fd_backup;

	if (0 <= fd)
		while (fd_backup_lst)
		{
			fd_backup = (void*)get_lst_elem(fd_backup_lst, 0);
			if (fd_backup)
			{
				if (fd_backup->save != fd)
					fd_backup_lst = advance_list(fd_backup_lst, 1);
				else
					return (TRUE);
			}
		}
	return (FALSE);
}
