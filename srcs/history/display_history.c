/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:26:05 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 13:07:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

int	display_history(t_history history)
{
	int	i;

	i = -1;
	while (history.history[++i])
		ft_printf("%5d  %s\n", i + 1, history.history[i]);
	return (0);
}
