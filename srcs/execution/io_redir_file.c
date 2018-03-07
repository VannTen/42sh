/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redir_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:40:46 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/07 11:30:04 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "sh_error.h"
#include "shell_macros.h"
#include "redirection.h"
#include "shell.h"

static int	get_target_fd(struct s_sh_io_redirect const *const io_redir)
{
	t_bsh *const	bsh = get_shell_data();
	char			*filename;
	int				target_fd;
	int				flags;

	if (bsh && io_redir->target)
		filename = expanded_str(&bsh->exp, io_redir->target, NOT_HERE_END_EXP);
	else
		filename = NULL;
	if (filename)
	{
		flags = io_redir->flags;
		if (io_redir->type == e_sh_io_type_file && io_redir->variant
				&& ft_getenv(bsh->env.env_list, "noclobber"))
			flags |= O_EXCL;
		target_fd = open(filename, flags, io_redir->mode);
		if (target_fd == -1)
			ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", SH_NAME, filename,
					sh_errstr(errno));
		ft_strdel(&filename);
		return (target_fd);
	}
	else
		return (-1);
}

int			io_redir_file(struct s_sh_io_redirect const *const io_redir,
		t_lst **const fd_backups_loc)
{
	int	ret;
	int	io_number;
	int	target_fd;

	ret = -1;
	if (!io_redir || !fd_backups_loc)
		ft_dprintf(STDERR_FILENO, "42sh: %s: invalid parameters.\n",
				__FUNCTION__);
	else if (((io_number = str_to_fd(io_redir->ionum)) != -1)
		&& !backup_filedescriptor(io_number, fd_backups_loc))
	{
		target_fd = get_target_fd(io_redir);
		if (target_fd != -1)
		{
			ret = dup2(target_fd, io_number);
			if (ret == -1)
				ft_dprintf(STDERR_FILENO, "42sh: %s: redirection failed.\n",
						io_redir->target);
			close(target_fd);
		}
	}
	return (ret == -1);
}
