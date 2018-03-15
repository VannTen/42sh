/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_physical_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:52:33 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/15 14:23:03 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "shell_errmsg.h"
#include <unistd.h>
#include <limits.h>

static char	const	*get_home_dir(t_env *env)
{
	char const	*home_dir;

	home_dir = shell_getenv(env, "HOME");
	if (home_dir == NULL)
	{
		ft_putstr_fd("42sh: cd: HOME not set.\n", 2);
		return (NULL);
	}
	return (home_dir);
}

/*
** The function returns true upon allocation failure to put an end to parsing.
** The allocation error message is expected to be displayed by builtin_cd.
*/

static char			*combine(char const *directory, char const *prepath,
		size_t prepath_len)
{
	size_t const	directory_len = ft_strlen(directory);
	char			*path;

	path = (char*)malloc((prepath_len + directory_len + 2) * sizeof(char));
	if (path == NULL)
		return (NULL);
	ft_strncpy(path, prepath, prepath_len);
	path[prepath_len] = '/';
	ft_strncpy(path + prepath_len + 1, directory, directory_len);
	path[prepath_len + directory_len + 1] = 0;
	if (access(path, F_OK))
	{
		ft_strdel(&path);
		return (NULL);
	}
	return (path);
}

static char			*parse_cdpath(char const *directory, t_env *env)
{
	char const	*cdpath;
	char const	*tmp;
	char		*path;

	if ((cdpath = shell_getenv(env, "CDPATH")) == NULL)
		return (ft_strdup(directory));
	while (cdpath[0] == ':')
		cdpath += 1;
	while ((tmp = ft_strchr(cdpath, ':')) != NULL)
	{
		if (tmp - cdpath < PATH_MAX)
		{
			if ((path = combine(directory, cdpath, tmp - cdpath)))
				return (path);
		}
		else
			ft_putstr_fd("42sh: cd: a component of CDPATH is larger than "
					"PATH_MAX and could not be checked.\n", 2);
		cdpath = tmp;
		while (cdpath[0] == ':')
			cdpath += 1;
	}
	if (!(path = combine(directory, cdpath, ft_strlen(cdpath))))
		path = ft_strdup(directory);
	return (path);
}

int					get_physical_path(char const *directory,
		char **const curpath_loc, t_env *env)
{
	if (directory == NULL && (directory = get_home_dir(env)) == NULL)
		return (1);
	else if (!ft_strcmp(directory, "-")
			&& (directory = shell_getenv(env, "OLDPWD")) == NULL)
	{
		ft_putstr_fd("42sh: cd: OLDPWD not set\n", 2);
		return (1);
	}
	if (directory[0] == '/'
			|| (directory[0] == '.' && ft_strchr("/", directory[1]))
			|| (!ft_strncmp(directory, "..", 2)
				&& ft_strchr("/", directory[1])))
		*curpath_loc = ft_strdup(directory);
	else
		*curpath_loc = parse_cdpath(directory, env);
	if (*curpath_loc == NULL)
	{
		shell_errmsg(e_shell_errmsg_alloc, "cd");
		return (1);
	}
	return (0);
}
