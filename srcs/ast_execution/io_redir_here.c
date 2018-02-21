/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_here.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:39:16 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/20 21:47:16 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	io_redir_here(struct s_sh_io_redirect const *io_redir,
		t_list **const fd_backups)
{
	int	ret;

	if (io_redir != NULL && fd_backups != NULL && io_redir->target != NULL)
	ret = io_redir_file(io_redir, fd_backups);
	unlink(io_redir->target);
	return (1);
}
