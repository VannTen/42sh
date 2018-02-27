/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:38:54 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:30:53 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "execution.h"
#include "s_fd_backup.h"

int							apply_redirections(t_lst *redirection_list,
		t_lst **const fd_backups)
{
	struct s_sh_io_redirect	*io_redirect;

	while (redirection_list != NULL)
	{
		io_redirect = (void*)get_lst_elem(redirection_list, 0);
		if (shx_io_redirect(io_redirect, fd_backups) == 0)
			redirection_list = advance_list(redirection_list, 1);
		else
			return (1);
	}
	return (0);
}
