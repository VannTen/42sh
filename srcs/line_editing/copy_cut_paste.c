/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:32:04 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/28 13:13:27 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		copy_selection(t_input *input)
{
	if (input->pivot < 0)
		return (0);
	ft_strdel(&input->buf_copy);
	if (input->cursor_pos > input->pivot)
	{
		if (!(input->buf_copy = ft_strndup(input->buffer + input->pivot,
				input->cursor_pos - input->pivot)))
			return (MALLOC_FAIL);
	}
	else if (input->cursor_pos < input->pivot)
	{
		if (!(input->buf_copy = ft_strndup(input->buffer + input->cursor_pos,
					input->pivot - input->cursor_pos)))
			return (MALLOC_FAIL);
	}
	else if (!(input->buf_copy = ft_strndup(input->buffer + input->pivot, 1)))
		return (MALLOC_FAIL);
	switch_input_state(input);
	return (0);
}

void	cut_from_buffer(t_input *input, const int cursor,
							const int pivot, const size_t len)
{
	if (cursor > pivot)
		ft_strcpy(input->buffer + pivot,
				input->buffer + cursor);
	else if (cursor < pivot)
		ft_strcpy(input->buffer + cursor,
				input->buffer + pivot);
	else
		ft_strcpy(input->buffer + cursor,
				input->buffer + cursor + 1);
	input->buffer_len -= len;
	ft_memset(input->buffer + input->buffer_len, 0,
			input->buffer_size - input->buffer_len);
}

int		cut_selection(t_input *input)
{
	int	i;
	int	cursor;

	cursor = input->cursor_pos;
	copy_selection(input);
	cut_from_buffer(input, input->cursor_pos, input->pivot,
							ft_strlen(input->buf_copy));
	switch_input_state(input);
	tputs(tgetstr("me", NULL), 1, putchar_termcaps);
	handle_home(input);
	clear_lines(input, input->buf_copy);
	tputs(tgetstr("ce", NULL), 1, putchar_termcaps);
	display_buffer(input, 0);
	i = input->buffer_len;
	while (i-- > cursor)
		handle_arrow_left(input);
	return (0);
}

int		paste_str_in_buffer(const char *str, t_input *input)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		while (input->buffer_len + len > input->buffer_size)
			if (realloc_buffer(input) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		ft_memmove((char*)input->buffer + input->cursor_pos + len,
				(char*)input->buffer + input->cursor_pos,
				input->buffer_len - input->cursor_pos);
		ft_memcpy(input->buffer + input->cursor_pos, str, len);
		input->buffer_len += len;
	}
	return (0);
}

int		paste_selection_buffer(t_input *input)
{
	if (input->buf_copy)
	{
		if (paste_str_in_buffer(input->buf_copy, input) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		display_line(input, input->cursor_pos + ft_strlen(input->buf_copy));
	}
	return (0);
}
