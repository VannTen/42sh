/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonical_path_internals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:54:59 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 16:43:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_defs.h"
#include "unix_files_interface.h"
#include "bool_interface.h"
#include "string_interface.h"

t_bool	valid_path_component(char *path, size_t index)
{
	t_bool	path_is_valid;

	path[index] = '\0';
	path_is_valid = is_dir(path);
	path[index] = '/';
	return (path_is_valid);
}

void	delete_dot(char *path)
{
	size_t	index;
	char	*copy;

	index = 0;
	copy = path;
	while (path[index] != '\0')
	{
		while (((index == 0 && path == copy) || path[index - 1] == '/')
				&& ft_strncmp("./", path + index, 2) == 0)
			path += 2;
		if (path[index + 1] == '\0' && path[index] == '.'
				&& (index == 0 || path[index - 1] == '/'))
			path += 1;
		copy[index] = path[index];
		if (copy[index] == '\0')
			break ;
		index++;
	}
	copy[index] = '\0';
}

t_bool	should_delete(const char *path, size_t index, size_t index_previous)
{
	return (index_previous != index
			&& !path_component_are_equal("..", path + index_previous)
			&& !is_root_component(path, index_previous));
}

char	*delete_parent_ref(char *path)
{
	size_t	index;
	size_t	index_previous;

	index = advance_nbr_path_comp(path, 1);
	while (path[index] != '\0')
	{
		if (path_component_are_equal("..", path + index))
		{
			index_previous = get_previous_component(path, index);
			if (should_delete(path, index, index_previous))
			{
				if (valid_path_component(path, index - 1))
				{
					ft_strcpy(path + index_previous, path + index +
							advance_nbr_path_comp(path + index, 1));
					index = index_previous;
					continue ;
				}
				else
					return (NULL);
			}
		}
		index += advance_nbr_path_comp(path + index, 1);
	}
	return (path);
}

void	delete_unneeded_slash(char *path)
{
	char	*copy;
	size_t	index;

	index = 0;
	copy = path;
	while (path[index] == '/' && index < 2)
		index++;
	while (path[index] != '\0')
	{
		while (path[index] == '/')
			path++;
		while (path[index] != '/' && path[index] != '\0')
		{
			copy[index] = path[index];
			index++;
		}
		copy[index] = path[index];
		if (path[index] == '/')
			index++;
	}
	index--;
	while (copy[index] == '/' && index != 0)
		index--;
	if (copy[index] != '/' && copy[index] != '\0')
		copy[index + 1] = '\0';
}
