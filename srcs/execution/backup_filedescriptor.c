/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_filedescriptor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 08:29:53 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/04 14:14:02 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_fd_backup.h"
#include "redirection.h"

static struct s_fd_backup	*create_fd_backup(int const fd)
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

int							backup_filedescriptor(int const fd,
		t_lst **const fd_backups)
{
	struct s_fd_backup	*backup;

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
	return (1);
}
