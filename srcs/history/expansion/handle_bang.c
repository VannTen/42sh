/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:43:04 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/14 15:01:56 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	expand_hashtag(t_string *exp_input, char **input)
{
	while (exp_input->len * 2 > exp_input->size)
		if (realloc_str(exp_input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	ft_strncat(exp_input->str + exp_input->len, exp_input->str, exp_input->len);
	(*input)++;
	exp_input->len *= 2;
	return (0);
}

static int	expansion_digit(t_history *history, t_string *exp_input,
							const char *s, char **input)
{
	int num;

	num = ft_atoi(s);
	if (get_cmd_num(history, exp_input, num) == 1)
		return (EVENT_NOT_FOUND);
	(*input) += ft_nb_digit_base(num, 10);
	return (0);
}

int			handle_bang(t_history *history, char **input, t_string *exp_input)
{
	char	*s;

	s = *input + 1;
	if (*s == '0' || ft_strchr("|&<>;", *s))
		return (EVENT_NOT_FOUND);
	if (*s == '!')
	{
		if (get_cmd_num(history, exp_input, history->len) == 1)
			return (EVENT_NOT_FOUND);
		(*input)++;
	}
	else if (ft_isdigit(*s) || (*s == '-' && ft_isdigit(*(s + 1))))
	{
		if (expansion_digit(history, exp_input, s, input) == EVENT_NOT_FOUND)
			return (EVENT_NOT_FOUND);
	}
	else if (*s == '#')
	{
		if (expand_hashtag(exp_input, input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	else if (get_cmd_str(history, exp_input, input, s) == 1)
		return (EVENT_NOT_FOUND);
	(*s == '\0') ? exp_input->str[exp_input->len++] = '!' : 0;
	return (0);
}
