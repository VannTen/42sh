/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:04:25 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/14 10:42:47 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Function adds parameter COMMAND to the existing history.
*/

int	add_cmd_to_history(t_history *history, char *const command)
{
	if (history->len < history->size)
	{
		if (!(history->history[history->len] = ft_strdup(command)))
			return (MALLOC_FAIL);
		history->len++;
		history->current++;
	}
	else if (history->size > 0)
	{
		ft_strdel(&history->history[0]);
		ft_memmove((char**)(history->history), (char**)(history->history + 1),
				(history->len - 1) * sizeof(char*));
		if (!(history->history[history->len - 1] = ft_strdup(command)))
			return (MALLOC_FAIL);
	}
	return (0);
}
