/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:03:29 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 14:50:19 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_error.h"
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>

static int	bad_component(char *path, char *start, char *end)
{
	char const	original_end_char = *end;
	struct stat	stat_buf;
	int			ret;

	ret = 0;
	*end = 0;
	if (!ret && NAME_MAX < ft_strlen(start))
		ret = ENAMETOOLONG;
	if (!ret && access(path, F_OK))
		ret = ENOENT;
	if (!ret && access(path, X_OK))
		ret = EACCES;
	if (!stat(path, &stat_buf))
	{
		if (!S_ISDIR(stat_buf.st_mode))
			ret = ENOTDIR;
	}
	*end = original_end_char;
	return (ret);
}

static int	sh_path_components_error(char *path)
{
	char	*component_start;
	char	*component_end;
	int		ret;

	if (path)
	{
		component_start = path;
		while (*component_start == '/')
			component_start += 1;
		component_end = ft_strchr(component_start, '/');
		while (component_end)
		{
			if ((ret = bad_component(path, component_start, component_end)))
				return (ret);
			component_start = component_end + 1;
			while (*component_start == '/')
				component_start += 1;
			component_end = ft_strchr(component_start, '/');
		}
	}
	return (0);
}

int			sh_path_error(char const *path)
{
	char	path_buf[PATH_MAX + 1];
	size_t	path_len;

	if (!path)
		return (EFAULT);
	path_len = ft_strlen(path);
	if (PATH_MAX < path_len)
		return (ENAMETOOLONG);
	ft_strncpy(path_buf, path, path_len);
	path_buf[path_len] = 0;
	return (sh_path_components_error(path_buf));
}
