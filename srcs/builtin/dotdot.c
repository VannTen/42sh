/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotdot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:53:57 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/15 11:37:48 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	prev_component_index(char const *curpath, size_t index)
{
	while (0 < index && curpath[index] != '/')
		index -= 1;
	while (0 < index && curpath[index] == '/')
		index -= 1;
	if (index == 0)
		return (0);
	while (0 < index && curpath[index] != '/')
		index -= 1;
	if (curpath[index] == '/')
		index += 1;
	return (index);
}

static int		component_is_dir(char *curpath, size_t index)
{
	struct stat	component_stat;
	char		tmp;
	int			ret;

	ret = 1;
	while (!ft_strchr("/", curpath[index]))
		index += 1;
	tmp = curpath[index];
	curpath[index] = 0;
	if (lstat(curpath, &component_stat))
	{
		ft_putstr_fd("42sh: cd -L: call to lstat() failed.\n", 2);
		ret = 0;
	}
	else if (!(component_stat.st_mode & S_IFDIR))
		ret = 0;
	curpath[index] = tmp;
	return (ret);
}

int				dotdot(char *curpath, size_t *const index_loc)
{
	size_t	index;
	size_t	prev;

	index = *index_loc;
	if (ft_strncmp(curpath + index, "..", 2)
			|| !ft_strchr("/", curpath[index + 2]))
		return (0);
	prev = prev_component_index(curpath, index);
	if (prev == index
			|| (prev == 0 && (curpath[0] == '/'))
			|| !ft_strncmp(curpath + prev, "../", 3))
		return (0);
	if (!component_is_dir(curpath, prev))
	{
		ft_putstr_fd("42sh: cd: A component of the path is not a directory.\n",
				2);
		return (-1);
	}
	index += 2 + (curpath[index + 2] != 0);
	while (curpath[index] == '/')
		index += 1;
	ft_memmove(curpath + prev, curpath + index, ft_strlen(curpath + index) + 1);
	*index_loc = prev;
	return (1);
}
