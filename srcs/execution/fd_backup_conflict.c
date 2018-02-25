/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_backup_conflict.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:10:42 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/24 16:22:00 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	conflict_found(int const fd, struct s_fd_backup const *const backup)
{
	if (backup != NULL)
		return ((backup->save == fd));
	else
		return (0);
}

static int	solve_conflict(struct s_fd_backup *const backup)
{
	int	new_save;

	new_save = dup(backup->save);
	if (0 <= new_save)
	{
		close(backup_save);
		backup->save = new_save;
		return (0);
	}
	else
	{
		ADD_ERRMSG;
		return (1);
	}
}

int			fd_backup_conflict(int const fd, t_list *fd_backups)
{
	while (fd_backups != NULL)
		if (conflict_found(fd, fd_backups->content))
			return (solve_conflict(fd_backups->content));
		else
			fd_backups = fd_backups->next;
	return (0);
}
