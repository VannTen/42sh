/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:16:39 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 14:47:47 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_macros.h"
#include "sh_error.h"
#include <unistd.h>
#include <sys/stat.h>

void	chdir_error(char const *path)
{
	struct stat	stat_buf;
	int			sh_errno;

	if (path)
	{
		sh_errno = sh_path_error(path);
		if (!sh_errno && access(path, F_OK))
			sh_errno = ENOENT;
		if (!sh_errno && !lstat(path, &stat_buf))
		{
			if (!S_ISDIR(stat_buf.st_mode))
				sh_errno = ENOTDIR;
		}
		if (!sh_errno && access(path, X_OK))
			sh_errno = EACCES;
		ft_dprintf(STDERR_FILENO, "%s: %s: %s.\n",
				SH_NAME, path, sh_errstr(sh_errno));
	}
}
