/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_here.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:39:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/07 08:57:58 by ble-berr         ###   ########.fr       */
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
		return (ret);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "42sh: %s: invalid parameters.\n",
				__FUNCTION__);
		return (42);
	}
}
