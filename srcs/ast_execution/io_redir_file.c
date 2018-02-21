/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:40:46 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/19 12:09:05 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	io_redir_file(struct s_sh_io_redirect const *const io_redir,
		t_list **const fd_backups)
{
	int	target_fd;

	if (valid_parameters(io_redir, fd_backups))
	{
		target_fd = open(io_redir.target.name, io_redir.flags, io_redir.mode);
		if (target_fd == -1)
			open_errmsg(io_redir.target.name, io_redir.flags, io_redir.mode);
		else if (dup2(target_fd, io_redir.ionum) == -1)
		{
			dup2_errmsg(target_fd, io_redir.ionum);
			close(target_fd);
		}
		else
		{
			close(target_fd);
			return (0);
		}
	}
	return (1);
}
