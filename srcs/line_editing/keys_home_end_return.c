/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_home_end_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:16:44 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/09 15:38:48 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	handle_home(t_input *input)
{
	while (input->cursor_pos > 0)
		handle_arrow_left(input);
	if (input->state == SELECTION)
	{
		tputs(tgetstr("sc", NULL), 1, putchar_termcaps);
		display_buffer(input, 0);
		tputs(tgetstr("rc", NULL), 1, putchar_termcaps);
		input->cursor_pos = 0;
		input->term->cursor_col = input->term->prompt_len + 1;
	}
	return (0);
}

int	handle_end(t_input *input)
{
	if (input->state == SELECTION)
	{
		while (input->cursor_pos > 0)
			handle_arrow_left(input);
		display_buffer(input, input->buffer_len);
	}
	else
	{
		while (input->cursor_pos < input->buffer_len)
			handle_arrow_right(input);
	}
	return (0);
}

int	handle_return(t_input *input)
{
	if (input->buffer_len > 0)
	{
		handle_end(input);
		input->cursor_pos = 0;
	}
	input->history->current = input->history->len;
	if (input->buffer_len == input->buffer_size)
		if (realloc_buffer(input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	input->buffer[input->buffer_len++] = '\n';
	return (RETURN);
}
