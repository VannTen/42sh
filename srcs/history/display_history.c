/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:26:05 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 14:56:04 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	display_history(t_history *history, char *arg)
{
	int	i;
	int	num;

	i = 0;
	if (arg)
	{
		if (!ft_str_isdigit(arg) || !arg[0])
		{
			ft_dprintf(STDERR_FILENO, "42sh: history: %s: numeric "
						"argument required\n", arg);
			return (1);
		}
		if ((ft_strlen(arg) > 10
				|| (ft_strlen(arg) == 10 && ft_strcmp(arg, INT_MAX_STR)))
				&& ft_atoi(arg))
			i = 0;
		else if ((num = ft_atoi(arg)) < history->len)
			i = history->len - num;
	}
	while (history->history[i])
	{
		ft_printf("%5d  %s\n", i + 1, history->history[i]);
		i++;
	}
	return (0);
}
