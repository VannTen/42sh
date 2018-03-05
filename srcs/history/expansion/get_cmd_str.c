/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:52:45 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/14 15:43:03 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	fuck_norm(t_history *history, char **tmp, char **tmp2, char **s)
{
	*tmp = *s;
	while (ft_isalnum(**tmp))
		(*tmp)++;
	if (**tmp == '\n')
	{
		(ft_strchr(*s, '\n')) ? (*s)[ft_strlen(*s) - 1] = '\0' : 0;
		if (!(*tmp = search_in_history_by_str(history, *s)))
			return (1);
		*tmp2 = *s;
	}
	else
	{
		if (!(*tmp2 = ft_strndup(*s, *tmp - *s)))
			return (MALLOC_FAIL);
		if (!(*tmp = search_in_history_by_str(history, *tmp2)))
		{
			ft_strdel(tmp2);
			return (1);
		}
	}
	return (0);
}

int			get_cmd_str(t_history *history, t_string *exp_input, char **input,
						char *s)
{
	char	*tmp;
	char	*tmp2;
	int		len;
	int		ret;

	if ((ret = fuck_norm(history, &tmp, &tmp2, &s) == 1))
		return (1);
	if (ret == MALLOC_FAIL)
		return (MALLOC_FAIL);
	len = ft_strlen(tmp);
	while (exp_input->len + len > exp_input->size)
		if (realloc_str(exp_input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strcat(exp_input->str, tmp);
	exp_input->len += len;
	(*input) += ft_strlen(tmp2);
	(tmp2 != s) ? ft_strdel(&tmp2) : 0;
	return (0);
}
