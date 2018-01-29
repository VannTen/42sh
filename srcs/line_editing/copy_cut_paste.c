/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:32:04 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/21 14:15:44 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			copy_selection(t_input *input)
{
	if (input->pivot < 0)
		return (0);
	ft_strdel(&input->buf_copy);
	if (input->cursor_pos > input->pivot)
	{
		if (!(input->buf_copy = ft_strndup(input->buffer + input->pivot,
				input->cursor_pos - input->pivot + 1)))
			ft_error_msg("Malloc failed");
	}
	else if (input->cursor_pos < input->pivot)
	{
		if (!(input->buf_copy = ft_strndup(input->buffer + input->cursor_pos,
					input->pivot - input->cursor_pos)))
			ft_error_msg("Malloc failed");
	}
	else if (!(input->buf_copy = ft_strndup(input->buffer + input->pivot, 1)))
		ft_error_msg("Malloc failed");
	if (!ft_strcmp(input->read_buffer, CTRL_F))
		switch_input_state(input);
	return (0);
}

static void	cut_from_buffer(t_input *input)
{
	if (input->cursor_pos > input->pivot)
		ft_strcpy(input->buffer + input->pivot,
				input->buffer + input->cursor_pos + 1);
	else
		ft_strcpy(input->buffer + input->cursor_pos,
				input->buffer + input->pivot);
	input->buffer_len -= ft_strlen(input->buf_copy);
	ft_memset(input->buffer + input->buffer_len, 0,
			input->buffer_size - input->buffer_len);
}

int			cut_selection(t_input *input)
{
	int	i;
	int	cursor;

	cursor = input->cursor_pos;
	copy_selection(input);
	cut_from_buffer(input);
	switch_input_state(input);
	tputs(tgetstr("me", NULL), 1, ft_putchar_termcaps);
	handle_home(input);
	if (input->buffer_len + (int)ft_strlen(input->buf_copy) >
			input->term->first_line_len)
	{
		tputs(tgetstr("sc", NULL), 1, ft_putchar_termcaps);
		tputs(tgetstr("nw", NULL), 1, ft_putchar_termcaps);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_termcaps);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_termcaps);
	}
	tputs(tgetstr("ce", NULL), 1, ft_putchar_termcaps);
	display_buffer(input, 0);
	i = input->buffer_len;
	while (i-- > cursor)
		handle_arrow_left(input);
	return (0);
}

int			paste_selection(t_input *input)
{
	int	len;

	if (input->buf_copy)
	{
		len = ft_strlen(input->buf_copy);
		while (input->buffer_len + len > input->buffer_size)
			if (realloc_buffer(input) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		ft_memmove((char*)input->buffer + input->cursor_pos + len,
				(char*)input->buffer + input->cursor_pos,
				input->buffer_len - input->cursor_pos);
		ft_memcpy(input->buffer + input->cursor_pos, input->buf_copy, len);
		input->buffer_len += len;
		display_line(input, input->cursor_pos + len);
	}
	return (0);
}
