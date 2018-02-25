/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:32:04 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 07:22:32 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_errmsg.h"
#include "env.h"
#include <unistd.h>

static char	*test_one(char const *start, char const *end, char const *name,
		size_t const name_len)
{
	char	*str;

	if ((str = ft_strnew((end - start) + name_len + (end[-1] != '/'))) == NULL)
		shell_errmsg(e_shell_errmsg_alloc, __FUNCTION__);
	else
	{
		ft_strncpy(str, start, end - start);
		if (end[-1] != '/')
			str[end - start] = '/';
		ft_strcat(str, name);
		if (!access(str, F_OK))
			return (str);
		ft_strdel(&str);
	}
	return (NULL);
}

static char		*path_search(char const *const name, char const *path)
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
		if ((str = test_one(path, end, name, name_len)) != NULL)
			return (str);
		path = end + (*end != 0);
	}
	return (NULL);
}

char			*sh_path_search(t_env *env, char *name)
{
	char	*path_val;

	path_val = shell_getenv(env, name);
	if (path_val != NULL)
		return (path_search(name, path_val));
	return (NULL);
}
