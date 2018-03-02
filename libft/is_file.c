/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:20:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/06/01 16:57:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool_interface.h"
#include <sys/stat.h>

t_bool	is_dir(const char *path)
{
	struct stat	file_infos;

	return (stat(path, &file_infos) != -1
			&& S_ISDIR(file_infos.st_mode) != 0);
}

t_bool	is_regfile(const char *path)
{
	struct stat	file_infos;

	return (stat(path, &file_infos) != -1
			&& S_ISREG(file_infos.st_mode) != 0);
}
