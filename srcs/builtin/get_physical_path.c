/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_physical_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:52:33 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/23 13:45:39 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "shell_errmsg.h"
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>

static char	const	*get_home_dir(t_env *env)
{
	char const	*home_dir;

	home_dir = shell_getvar(env, "HOME");
	if (home_dir == NULL)
	{
		ft_putstr_fd("42sh: cd: HOME not set.\n", 2);
		return (NULL);
	}
	return (home_dir);
}

static t_bool		eligible_target(char const *str)
{
	struct stat	stat_buf;

	if (!stat(str, &stat_buf) && S_ISDIR(stat_buf.st_mode)
			&& !access(str, X_OK))
		return (TRUE);
	else
		return (FALSE);
}

static char			*test_one(char const *prefix, size_t prefix_len,
		char const *name, size_t const name_len)
{
	char			*str;
	t_bool const	add_slash = 0 < prefix_len && prefix[prefix_len - 1] != '/';

	if ((str = ft_strnew(prefix_len + name_len + (add_slash ? 2 : 1))) == NULL)
		shell_errmsg(e_shell_errmsg_alloc, __FUNCTION__);
	else
	{
		ft_strncpy(str, prefix, prefix_len);
		if (add_slash)
			str[prefix_len] = '/';
		ft_strncpy(str + prefix_len + (add_slash ? 1 : 0), name, name_len);
		str[prefix_len + (add_slash ? 1 : 0) + name_len] = 0;
		if (eligible_target(str))
			return (str);
		ft_strdel(&str);
	}
	return (NULL);
}

static char			*cdpath_search(char const *const name, t_env *env)
{
	char const	*cdpath;
	char const	*end;
	char		*str;
	size_t		name_len;

	if (!name || !env || !(cdpath = shell_getvar(env, "CDPATH")))
		return (NULL);
	name_len = ft_strlen(name);
	while (*cdpath == ':')
		cdpath += 1;
	while (*cdpath != 0)
	{
		if ((end = ft_strchr(cdpath, ':')) == NULL)
			end = ft_strchr(cdpath, 0);
		if ((str = test_one(cdpath, end - cdpath, name, name_len)) != NULL)
			return (str);
		cdpath = end + (*end != 0);
		while (*cdpath == ':')
			cdpath += 1;
	}
	return (NULL);
}

int					get_physical_path(char const *directory,
		char **const curpath_loc, t_env *env)
{
	if (directory == NULL && (directory = get_home_dir(env)) == NULL)
		return (1);
	else if (!ft_strcmp(directory, "-")
			&& (directory = shell_getvar(env, "OLDPWD")) == NULL)
	{
		ft_putstr_fd("42sh: cd: OLDPWD not set\n", 2);
		return (1);
	}
	if (directory[0] == '/'
			|| (directory[0] == '.' && ft_strchr("/", directory[1]))
			|| (!ft_strncmp(directory, "..", 2)
				&& ft_strchr("/", directory[2]))
			|| !(*curpath_loc = cdpath_search(directory, env)))
		*curpath_loc = ft_strdup(directory);
	if (*curpath_loc == NULL)
	{
		shell_errmsg(e_shell_errmsg_alloc, "cd");
		return (1);
	}
	return (0);
}
