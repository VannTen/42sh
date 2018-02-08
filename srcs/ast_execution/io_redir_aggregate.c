/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_aggregate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:03:03 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/29 13:37:51 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	io_redir_aggregate(struct s_io_redirection const io_redir,
		t_list **const fd_backups)
{
	if (backup_conflict(io_redir.ionum, &fd_backups)
			|| backup_conflict(io_redir.target.fd, &fd_backups))
		ADD_ERRMSG;
	else
	{
		if (dup2(target_fd, io_redir.ionum) == -1)
			dup2_errmsg(target_fd, io_redir.ionum);
		else
		{
			close(io_redir.target.fd);
			return (0);
		}
	}
	return (1);
}
