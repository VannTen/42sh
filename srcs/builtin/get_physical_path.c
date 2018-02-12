/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_physical_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:52:33 by ble-berr          #+#    #+#             */
/*   Updated: 2018/01/22 13:40:55 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	const	*get_home_dir(void)
{
	char const	*home_dir;

	home_dir = shell_getenv("HOME");
	if (home_dir == NULL)
	{
		ft_putstr_fd("21sh: cd: HOME not set.\n", 2);
		return (NULL);
	}
	return (home_dir);
}

/*
** The function returns true upon allocation failure to put an end to parsing.
** The allocation error message is expected to be displayed by builtin_cd.
*/

static int			combine(char const *directory, char const *prepath,
		size_t prepath_len, char **const path_loc)
{
	size_t const	directory_len = ft_strlen(directory);

	*path_loc = (char*)malloc((prepath_len + directory_len + 2) * sizeof(char));
	if (*path_loc == NULL)
		return (1);
	ft_strcpy(*path_loc, prepath);
	(*path_loc)[prepath_len] = '/';
	ft_strcpy(*path_loc + prepath_len + 1, directory);
	(*path_loc)[prepath_len + directory_len + 1] = 0;
	if (access(*path_loc, F_OK))
	{
		ft_strdel(path_loc);
		return (0);
	}
	return (1);
}

static char			*parse_cdpath(char const *directory)
{
	char const	*cdpath;
	char const	*tmp;
	char		*path;

	if ((cdpath = shell_getenv("CDPATH")) == NULL)
		return (ft_strdup(directory));
	while (cdpath[0] == ':')
		cdpath += 1;
	while ((tmp = ft_strchr(cdpath, ':')) != NULL)
	{
		if (tmp - cdpath < PATH_MAX
				&& combine(directory, cdpath, tmp - cdpath, &path))
			return (path);
		else
			ft_putstr_fd("21sh: cd: a component of CDPATH is larger than "
					"PATH_MAX and could not be checked.\n", 2);
		cdpath = tmp;
		while (cdpath[0] == ':')
			cdpath += 1;
	}
	if (!combine(directory, cdpath, ft_strlen(cdpath), &path))
		path = ft_strdup(directory);
	return (path);
}

int					get_physical_path(char const *directory,
		char **const curpath_loc)
{
	if (directory == NULL && (directory = get_home_dir()) == NULL)
		return (1);
	else if (!ft_strcmp(directory, "-")
			&& (directory = shell_getenv("OLDPWD")) == NULL)
	{
		ft_putstr_fd("21sh: cd: OLDPWD not set\n", 2);
		return (1);
	}
	if (directory[0] == '/'
			|| (directory[0] == '.' && ft_strchr("/", directory[1]))
			|| (!ft_strncmp(directory, "..", 2)
				&& ft_strchr("/", directory[1])))
		*curpath_loc = ft_strdup(directory);
	else
		*curpath_loc = parse_cdpath(directory);
	if (*curpath_loc == NULL)
	{
		shell_errmsg(e_shell_errmsg_alloc, "cd");
		return (1);
	}
	return (0);
}
