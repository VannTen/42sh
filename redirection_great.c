/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_great.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:11:21 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/24 16:10:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	redirection_great(int const ionum, union u_redirection_target const target,
		t_list *fd_backups)
{
	int	target_fd;

	if (ionum < 0 || target.name == NULL)
		return (1);
	if (backup_conflict(ionum))
	{
		ADD_ERRMSG;
		return (1);
	}
	if ((target_fd = open(target.name, REDIR_GREAT_OFLAGS)) == -1)
	{
		ADD_ERRMSG;
		return (1);
	}
	if (dup2(target_fd, ionum) == -1)
	{
		ADD_ERRMSG;
		return (1);
	}
	close(target_fd);
	return (0);
}
