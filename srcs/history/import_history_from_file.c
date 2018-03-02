/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_history_from_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:36:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 13:54:27 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Opens history_file and saves its content to the session's history structure.
*/

int			import_history_from_file(t_history *history)
{
	char	*line;
	int		fd;

	if ((fd = open(history->file, O_CREAT | O_RDONLY | O_APPEND, 0644)) < 0)
	{
		ft_dprintf(STDERR_FILENO, "42sh: opening of history file failed\n");
		return (1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (add_cmd_to_history(history, line) == MALLOC_FAIL)
		{
			clear_all_history(history);
			ft_strdel(&line);
			ft_dprintf(STDERR_FILENO, "42sh: history import failed\n");
			break ;
		}
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
