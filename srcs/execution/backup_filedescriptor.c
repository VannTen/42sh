/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_filedescriptor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 08:29:53 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/07 10:03:43 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_fd_backup.h"
#include "redirection.h"

static struct s_fd_backup	*create_fd_backup(int fd)
{
	struct s_fd_backup	*new_backup;
	int					save;

	if (!fd_is_active(fd))
		save = -1;
	else if ((save = dup(fd)) == -1)
	{
		ft_putstr_fd("42sh: failed to duplicate filedescriptor.\n", 2);
		return (NULL);
	}
	new_backup = (struct s_fd_backup*)malloc(sizeof(*new_backup));
	if (new_backup != NULL)
	{
		new_backup->origin = fd;
		new_backup->save = save;
	}
	else
		ft_putstr_fd("42sh: allocation attempt failed.\n", 2);
	return (new_backup);
}

static struct s_fd_backup	*get_fd_backup(int fd, t_lst *fd_backup_lst)
{
	struct s_fd_backup	*backup;

	while (fd_backup_lst)
	{
		backup = (void*)get_lst_elem(fd_backup_lst, 0);
		if (backup && backup->origin == fd)
			return (backup);
		fd_backup_lst = advance_list(fd_backup_lst, 1);
	}
	return (NULL);
}

int							backup_filedescriptor(int fd,
		t_lst **const fd_backups)
{
	struct s_fd_backup	*backup;

	if (fd_backups)
	{
		if (fd < 0 || filedescriptor_is_a_backup(fd, *fd_backups))
			fd = -1;
		if (fd != -1 && !get_fd_backup(fd, *fd_backups))
		{
			backup = create_fd_backup(fd);
			if (backup != NULL)
			{
				if (f_lstpush(backup, fd_backups))
					return (0);
				else
				{
					free(backup);
					ft_putstr_fd("42sh: allocation attempt failed.\n", 2);
				}
			}
		}
		else
			return (0);
	}
	return (1);
}
