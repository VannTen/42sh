/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_io_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:29:27 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:28:09 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "bleberr_macros.h"

int	shx_io_redirect(struct s_sh_io_redirect *io_redirect, t_lst **fd_backups)
{
	t_io_redirect_ft const	io_redirect_fts[] = {
		&io_redir_file, &io_redir_here, &io_redir_aggregate
	};

	if (io_redirect && 0 <= io_redirect->type
			&& (size_t)io_redirect->type < ARRLEN(io_redirect_fts))
		return (io_redirect_fts[io_redirect->type](io_redirect, fd_backups));
	else
		return (42);
}
