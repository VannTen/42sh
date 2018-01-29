/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:40:44 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/24 11:07:35 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	load_fd_backup(struct s_fd_backup const *const fd_backup)
{
	if (fd_backup->save == -1)
		close(fd_backup->origin);
	else if (dup2(save, origin) == -1)
		ft_dprintf(2, "42sh: failed to restore redirected fd %i.\n");
	return ;
}

void		undo_redirections(t_list **const fd_backups_loc)
{
	t_list	*fd_backups;

	if (fd_backups_loc != NULL)
	{
		fd_backups = *fd_backups_loc;
		while (fd_backup != NULL)
		{
			load_fd_backup(fd_backup->content);
			fd_backup = fd_backup->next;
		}
		ft_lstdel(fd_backups_loc, &free);
	}
	return ;
}
