/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_history_from_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:36:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/25 17:49:03 by bjanik           ###   ########.fr       */
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
		return (2);
	while (get_next_line(fd, &line) > 0)
	{
		add_cmd_to_history(history, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
