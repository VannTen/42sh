/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:39:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/21 17:54:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		set_history_to_null(t_history *history)
{
	history->history = NULL;
	history->file = NULL;
	history->current = 0;
	history->len = 0;
	history->size = 0;
}

int			init_history(t_history *history, int size)
{
	char	*home_dir;

	if (size < 0 || size > DEFAULT_HISTSIZE)
		size = DEFAULT_HISTSIZE;
	if (!(history->history = (char**)malloc(sizeof(char*) * (size + 1))))
		return (MALLOC_FAIL);
	ft_memset(history->history, 0, (size + 1) * sizeof(char*));
	if (!(home_dir = get_home_dir()))
		return (MALLOC_FAIL);
	if (!(history->file = ft_strnjoin(home_dir, 2, "/", ".42sh_history")))
	{
		ft_strdel(&home_dir);
		return (MALLOC_FAIL);
	}
	history->current = 0;
	history->len = 0;
	history->size = size;
	import_history_from_file(history);
	return (0);
}
