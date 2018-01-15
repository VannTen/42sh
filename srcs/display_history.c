/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:26:05 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/15 15:41:00 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

int	display_history(t_history history)
{
	size_t	i;

	i = 0;
	while (i < history.len)
	{
		ft_printf("%5d  %s\n", i + 1, history.history[i]);
		i++;
	}
	return (0);
}
