/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:55:18 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 10:55:52 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "history.h"

void		reset_buffer(t_input *input)
{
	ft_memset(input->buffer, 0, input->buffer_size);
	input->buffer_len = 0;
	input->cursor_pos = 0;
}

int			cursor_on_last_line(t_input *input)
{
	int		i;

	i = 0;
	while (input->cursor_pos + i < input->buffer_len &&
		input->term->cursor_col + i < input->term->width)
		i++;
	if (input->cursor_pos + i == input->buffer_len)
		return (1);
	return (0);
}

int			handle_reg_char(t_input *input, char c)
{
	if (input->state == STANDARD)
	{
		if (input->buffer_len == input->buffer_size)
			if (realloc_buffer(input) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		if (input->cursor_pos == input->buffer_len)
			input->buffer[input->cursor_pos] = c;
		else
		{
			ft_memmove((char*)input->buffer + input->cursor_pos + 1,
			(char*)input->buffer + input->cursor_pos,
			ft_strlen(input->buffer + input->cursor_pos));
			input->buffer[input->cursor_pos] = c;
		}
		input->buffer_len++;
		display_line(input, input->cursor_pos + 1);
	}
	return (0);
}

void		cp_history_to_buffer(t_input *input)
{
	char	*str;
	int		len;

	str = input->history->history[input->history->current];
	ft_bzero(input->buffer, input->buffer_size);
	if (!str)
		return ;
	handle_home(input);
	len = ft_strlen(str);
	while (len > input->buffer_size)
		realloc_buffer(input);
	ft_strcpy(input->buffer, str);
	input->buffer_len = ft_strlen(input->buffer);
	display_buffer(input, 0);
	apply_termcaps("sc");
	apply_termcaps("nw");
	apply_termcaps("cd");
	apply_termcaps("rc");
}
