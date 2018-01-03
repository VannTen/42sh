/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:56:16 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:17:22 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		append_history(t_history *history, char *cmd, int cmd_len)
{
	t_dlst	*hist;

	hist = ft_dlstnew(cmd, cmd_len + 1);
	ft_dlstadd(&history->head, hist);
	if (history->end == NULL)
		history->end = history->head;
	history->len++;
	history->current = NULL;
}

static char	*get_pw_dir(void)
{
	struct passwd	*pw;

	if (!(pw = (struct passwd*)getpwuid(getuid())))
		ft_error_msg("Getpwuid failed\n");
	return (pw->pw_dir);
}

static void	import_history_from_file(t_history *history)
{
	char	*line;

	while (get_next_line(history->fd, &line) > 0)
	{
		append_history(history, line, ft_strlen(line) + 1);
		ft_strdel(&line);
		history->len++;
	}
}

t_history	*init_history(void)
{
	t_history	*history;

	if (!(history = (t_history*)malloc(sizeof(t_history))))
		ft_error_msg("Malloc failed\n");
	history->head = NULL;
	history->end = NULL;
	history->current = NULL;
	history->len = 0;
	if (!(history->hist_file = ft_strnjoin(get_pw_dir(), 2, "/",
					".21sh_history")))
		exit(EXIT_FAILURE);
	if ((history->fd = open(history->hist_file, O_CREAT | O_RDWR | O_APPEND,
					0644)) < 0)
		ft_error_msg("Open failed\n");
	import_history_from_file(history);
	close(history->fd);
	return (history);
}
