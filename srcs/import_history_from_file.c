/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_history_from_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:36:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/16 11:48:37 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

/*
** Returns HOME directory.
*/

static char	*get_pw_dir(void)
{
	struct passwd	*pw;

	if (!(pw = (struct passwd*)getpwuid(getuid())))
		return (NULL);
	return (pw->pw_dir);
}

/*
** Opens history_file and saves its content to the session's history structure.
*/

int			import_history_from_file(t_history *history)
{
	char	*line;
	int		fd;

	if (!(history->histfile = ft_strnjoin(get_pw_dir(), 2, "/",
											".42sh_history")))
		return (1);
	if ((fd = open(history->hist_file, O_CREAT | O_RDWR |O_APPEND, 0644)) < 0)
		return (2);
	while (get_next_line(fd, &line) > 0 && history->len <= history->size)
	{
		add_cmd_to_history(history, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
