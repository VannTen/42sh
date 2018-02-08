/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_here.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:39:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/29 13:53:01 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	io_redir_here(struct s_sh_io_redirect const io_redir,
		t_list **const fd_backups)
{
	int	here_fd;

	if (io_redir.target.name != NULL)
		if (!backup_conflict(io_redir.ionum, fd_backups))
		{
			here_fd = open(io_redir.target.name, io_redir.flags, io_redir.mode);
			unlink(io_redir.target.name);
			if (0 <= here_fd)
				if (dup2(here_fd, io_redir.ionum) != -1)
				{
					close(here_fd);
					return (0);
				}
				else
				{
					close(here_fd);
					dup2_errmsg(target_fd, io_redir.ionum);
				}
			else
				open_errmsg(io_redir.target.name, io_redir.flags, io_redir.mode);
		}
		else
			ADD_ERRMSG;
	else
		ADD_ERRMSG;
	return (1);
}
