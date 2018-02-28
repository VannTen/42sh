/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history_to_histfile.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:39:40 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/28 15:36:37 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	save_history_to_histfile(t_history *history)
{
	int	i;
	int	fd;

	i = -1;
	if ((fd = open(history->file, O_CREAT | O_WRONLY, 0644)) < 0)
		return (1);
	while (++i < history->len)
	{
		write(fd, history->history[i], ft_strlen(history->history[i]));
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}
