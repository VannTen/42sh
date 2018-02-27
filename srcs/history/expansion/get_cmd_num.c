/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:50:56 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/14 11:22:13 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	get_cmd_num(t_history *history, t_string *exp_input, const int num)
{
	char	*s;
	int		len;

	if (num < 0)
		if (!(s = search_in_history_by_num(history, num)))
			return (1);
	if (num > 0)
		if (!(s = search_in_history_by_num(history, num - 1)))
			return (1);
	if (num == 0)
		return (1);
	len = ft_strlen(s);
	while (exp_input->len + len > exp_input->size)
		if (realloc_str(exp_input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strcat(exp_input->str, s);
	exp_input->len += len;
	return (0);
}
