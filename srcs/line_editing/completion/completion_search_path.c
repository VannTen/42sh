/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_search_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:27:45 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/03 14:44:31 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		completion_search_path(t_comp *comp)
{
	t_env		*env;
	t_env_list	*path;
	t_list		*matches[2];
	t_list		*tmp;
	char		**paths;
	int			i;

	env = &get_shell_data()->env;
	if (!(path = ft_getenv(env->env_list, "PATH")))
		return (1);
	if (!(paths = ft_strsplit(path->value, ':')))
		return (MALLOC_FAIL);
	i = -1;
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
	comp->matches = matches[0];
	ft_free_string_tab(&paths);
	return (0);
}
