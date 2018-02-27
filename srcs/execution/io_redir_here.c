/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_here.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:39:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:48:51 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "redirection.h"

int	io_redir_here(struct s_sh_io_redirect const *io_redir,
		t_lst **const fd_backups_loc)
{
	int	ret;

	if (io_redir != NULL && io_redir->target != NULL)
	{
		ret = io_redir_file(io_redir, fd_backups_loc);
		(void)unlink(io_redir->target);
		return (ret);
	}
	else
		return (42);
}
