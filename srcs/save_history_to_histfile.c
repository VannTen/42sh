/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history_to_histfile.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:39:40 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/16 11:48:34 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

int	save_history_to_histfile(t_history *const history)
{
	size_t	i;
	int		fd;

	i = 0;
	if ((fd = open(history->histfile, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		return (1);
	while (i < history->len)
	{
		write(fd, history->history[i], ft_strlen(history->history[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}
