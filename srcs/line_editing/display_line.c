/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:59:28 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/31 16:40:56 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	enable_video_display(t_input *input, int cursor)
{
	if (cursor > input->pivot)
	{
		if (input->cursor_pos == input->pivot)
			tputs(tgetstr("mr", NULL), 1, putchar_termcaps);
		if (input->cursor_pos == cursor)
			tputs(tgetstr("me", NULL), 1, putchar_termcaps);
	}
	else if (cursor < input->pivot)
	{
		if (input->cursor_pos == cursor)
			tputs(tgetstr("mr", NULL), 1, putchar_termcaps);
		if (input->cursor_pos == input->pivot)
			tputs(tgetstr("me", NULL), 1, putchar_termcaps);
	}
	else
		tputs(tgetstr("me", NULL), 1, putchar_termcaps);
}

void		display_buffer(t_input *input, int cursor)
{
	int	i;

	i = -1;
	while (input->buffer[++i])
	{
		if (input->pivot > -1)
			enable_video_display(input, cursor);
		write(STDIN_FILENO, &input->buffer[i], 1);
		if (input->term->cursor_col == input->term->width)
		{
			tputs(tgetstr("do", NULL), 1, putchar_termcaps);
			input->term->cursor_col = 0;
		}
		input->cursor_pos++;
		input->term->cursor_col++;
	}
}

void		display_line(t_input *input, int cursor)
{
	int	i;

	handle_home(input);
	display_buffer(input, cursor);
	i = input->buffer_len;
	while (i-- > cursor)
		handle_arrow_left(input);
}
