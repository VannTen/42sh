/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_str_in_history.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:59:31 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/24 12:32:09 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static int	ft_abs(int const number)
{
	return (number < 0 ? -number : number);
}

char		*search_in_history_by_num(t_history *history, const int number)
{
	if (ft_abs(number) > history->len)
		return (NULL);
	if (number < 0)
		return (history->history[history->len + number]);
	return (history->history[number]);
}

char		*search_in_history_by_str(t_history *history, const char *str)
{
	int		i;
	size_t	len_str;

	if (!str)
		return (NULL);
	len_str = ft_strlen(str);
	i = -1;
	while (history->history[++i])
	{
		if (ft_strstr(history->history[i], str))
			return (history->history[i]);
	}
	return (NULL);
}
