/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_search_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:27:45 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/12 18:34:47 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_list	*open_path_dirs(t_comp *comp, char **paths)
{
	t_list		*matches[2];
	t_list		*tmp;
	int			i;

	i = -1;
	tmp = NULL;
	matches[0] = NULL;
	while (paths[++i])
	{
		tmp = open_and_read_directory(comp, paths[i]);
		if (!matches[0] && tmp)
		{
			matches[0] = tmp;
			matches[1] = tmp;
		}
		else if (tmp)
			matches[1]->next = tmp;
		while (tmp && matches[1]->next)
			matches[1] = matches[1]->next;
	}
	return (matches[0]);
}

int				completion_search_path(t_comp *comp)
{
	t_env		*env;
	t_env_list	*path;
	char		**paths;

	env = &get_shell_data()->env;
	if (!(path = ft_getenv(env->env_list, "PATH")))
		return (1);
	if (!(paths = ft_strsplit(path->value, ':')))
		return (MALLOC_FAIL);
	comp->matches = open_path_dirs(comp, paths);
	ft_free_string_tab(&paths);
	return (0);
}
