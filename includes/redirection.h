/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:02:11 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:53:01 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "libft.h"
# include "shell_ast/io_redirect.h"
# include "s_fd_backup.h"

typedef int	(*t_io_redirect_ft)(struct s_sh_io_redirect const *io_redirect,
		t_lst **fd_backups);

int	io_redir_aggregate(struct s_sh_io_redirect const *io_redirect,
		t_lst **fd_backups_loc);
int	io_redir_file(struct s_sh_io_redirect const *io_redirect,
		t_lst **fd_backups_loc);
int	io_redir_here(struct s_sh_io_redirect const *io_redirect,
		t_lst **fd_backups_loc);

int	backup_filedescriptor(int fd, t_lst **fd_backups_loc);
int	saved_filedescriptor_conflict(int fd, t_lst *fd_backups);

int	str_to_fd(char const *str);

#endif
