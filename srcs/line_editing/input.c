/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:55:18 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/22 16:52:18 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		reset_buffer(t_input *input)
{
	ft_bzero(input->buffer, input->buffer_size);
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
	if (input->buffer_len == input->buffer_size)
		realloc_buffer(input);
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
	return (0);
}

void		cp_history_to_buffer(t_input *input)
{
	char	*str;

	str = input->history->current->data;
	ft_bzero(input->buffer, input->buffer_size);
	handle_home(input);
	ft_strcpy(input->buffer, str);
	input->buffer_len = ft_strlen(input->buffer);
	display_buffer(input, 0);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_termcaps);
	tputs(tgetstr("nw", NULL), 1, ft_putchar_termcaps);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_termcaps);
	tputs(tgetstr("rc", NULL), 1, ft_putchar_termcaps);
}
