/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:38:51 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 10:52:19 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	delete_char(t_input *input)
{
	int	cursor_pos;
	int	i;

	if (input->cursor_pos == input->buffer_len)
		return ;
	ft_strcpy(input->buffer + input->cursor_pos,
				input->buffer + input->cursor_pos + 1);
	cursor_pos = input->cursor_pos;
	apply_termcaps("vi");
	handle_home(input);
	apply_termcaps("sc");
	apply_termcaps("ce");
	if (input->buffer_len > input->term->first_line_len)
	{
		apply_termcaps("do");
		apply_termcaps("cd");
	}
	apply_termcaps("rc");
	display_buffer(input, 0);
	i = --input->buffer_len;
	while (i-- > cursor_pos)
		handle_arrow_left(input);
	apply_termcaps("ve");
}

int			handle_backspace(t_input *input)
{
	if (input->cursor_pos > 0)
	{
		handle_arrow_left(input);
		delete_char(input);
	}
	return (0);
}

int			handle_delete(t_input *input)
{
	delete_char(input);
	return (0);
}
