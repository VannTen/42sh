/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:54:08 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/21 17:03:05 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clear_all_history(t_history *history)
{
	int	i;

	i = -1;
	while (++i < history->len)
		ft_strdel(&history->history[i]);
	history->len = 0;
	history->current = 0;
	return (0);
}
