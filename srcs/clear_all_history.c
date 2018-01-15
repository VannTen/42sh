/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:54:08 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/15 19:12:07 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

int	clear_all_history(t_history *history)
{
	size_t	i;

	i = 0;
	while (i < history->len)
		ft_strdel(&history->history[i++]);
	history->len = 0;
	history->current = 0;
	return (0);
}
