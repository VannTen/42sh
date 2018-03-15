/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:32:04 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/15 15:23:40 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_errmsg.h"
#include "env.h"
#include <unistd.h>

static char	*test_one(char const *prefix, size_t prefix_len, char const *name,
		size_t const name_len)
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
		if (!access(str, F_OK))
			return (str);
		ft_strdel(&str);
	}
	return (NULL);
}

char		*path_search(char const *const name, char const *path)
{
	char const	*end;
	char		*str;
	size_t		name_len;

	if (path == NULL || name == NULL)
		return (NULL);
	name_len = ft_strlen(name);
	while (*path == ':')
		path += 1;
	while (*path != 0)
	{
		if ((end = ft_strchr(path, ':')) == NULL)
			end = path + ft_strlen(path);
		if ((str = test_one(path, end - path, name, name_len)) != NULL)
			return (str);
		path = end + (*end != 0);
		while (*path == ':')
			path += 1;
	}
	return (NULL);
}

char		*sh_path_search(t_env *env, char *name)
{
	char	*path_val;

	path_val = shell_getvar(env, "PATH");
	if (path_val != NULL)
		return (path_search(name, path_val));
	return (NULL);
}
