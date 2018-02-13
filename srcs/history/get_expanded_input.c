/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:11:05 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/12 16:34:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	check_bang_is_expandable(const int state, const char *c,
									const char *input)
{
	if (*c == '!'
			&& *(c + 1) != ' '
			&& *(c + 1) != '\n'
			&& (c == input || *(c - 1) != '\\')
			&& state != QUOTE
			&& state != COMMENT)
		return (1);
	return (0);
}

int			get_expanded_input(t_lexer *lexer, t_history *history, char *input,
								t_string *exp_input)
{
	lexer->input = input;
	while (*(lexer->input))
	{
		get_event(lexer);
		lexer->state = g_lexer[lexer->state][lexer->event].new_state;
		if (exp_input->len >= exp_input->size)
			if (realloc_str(exp_input) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		if (check_bang_is_expandable(lexer->state, lexer->input, input))
		{
			if (handle_bang(history,
						&lexer->input,
						exp_input) == EVENT_NOT_FOUND)
				return (EVENT_NOT_FOUND);
		}
		else
			exp_input->str[exp_input->len++] = *(lexer->input);
		lexer->input++;
	}
	lexer->state = INIT;
	lexer->event = 0;
	return (0);
}
