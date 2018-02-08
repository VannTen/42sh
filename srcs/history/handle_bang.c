/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:43:04 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/05 11:22:14 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	get_cmd_num(t_history *history, t_string *exp_input, const int num)
{
	char	*s;

	if (num < 0)
		if (!(s = search_in_history_by_num(history, num)))
			return (1);
	if (num > 0)
		if (!(s = search_in_history_by_num(history, num - 1)))
			return (1);
	if (num == 0)
		return (1);
	ft_strcat(exp_input->str, s);
	exp_input->len += ft_strlen(s);
	return (0);
}

static int	get_cmd_str(t_history *history, t_string *exp_input, char **input,
						char *s)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	if (!(tmp = ft_strchr(s, ' ')))
	{
		(ft_strchr(s, '\n')) ? s[ft_strlen(s) - 1] = '\0' : 0;
		if (!(tmp = search_in_history_by_str(history, s)))
			return (1);
		tmp2 = s;
	}
	else
	{
		tmp2 = ft_strndup(s, tmp - s);
		if (!(tmp = search_in_history_by_str(history, tmp2)))
			return (1);
	}
	len = ft_strlen(tmp);
	if (exp_input->len + len > exp_input->size)
		if (ft_realloc_str(exp_input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strcat(exp_input->str, tmp);
	exp_input->len += len;
	(*input) += ft_strlen(tmp2);
	return (0);
}

int			handle_bang(t_history *history, char **input, t_string *exp_input)
{
	char	*s;
	int		num;

	s = *input + 1;
	if (*s == '0' || ft_strchr("|&<>;", *s))
		return (EVENT_NOT_FOUND);
	else if (*s == '!')
	{
		if (get_cmd_num(history, exp_input, history->len) == 1)
			return (EVENT_NOT_FOUND);
		(*input)++;
	}
	else if (ft_isdigit(*s) || (*s == '-' && ft_isdigit(*(s + 1))))
	{
		num = ft_atoi(s);
		if (get_cmd_num(history, exp_input, num) == 1)
			return (EVENT_NOT_FOUND);
		(*input) += ft_nb_digit_base(num, 10);
	}
	else if (*s == '\0')
		exp_input->str[exp_input->len++] = '!';
	else if (get_cmd_str(history, exp_input, input, s) == 1)
		return (EVENT_NOT_FOUND);
	return (0);
}
