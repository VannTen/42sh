/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_cmd_from_history.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:55:16 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 15:18:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	remove_cmd_from_history(t_history *history, const int offset)
{
	if (offset < 1 || offset > history->len)
		return (1);
	ft_strdel(&history->history[offset - 1]);
	ft_memmove((char**)history->history + offset - 1,
				(char**)history->history + offset, (history->len - offset) *
				sizeof(char*));
	history->len--;
	history->history[history->len] = NULL;
	return (0);
}
