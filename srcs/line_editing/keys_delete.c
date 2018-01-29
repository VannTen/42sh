/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:38:51 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/21 15:55:11 by bjanik           ###   ########.fr       */
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
	handle_home(input);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_termcaps);
	tputs(tgetstr("ce", NULL), 1, ft_putchar_termcaps);
	if (input->buffer_len > input->term->first_line_len)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar_termcaps);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_termcaps);
	}
	tputs(tgetstr("rc", NULL), 1, ft_putchar_termcaps);
	display_buffer(input, 0);
	i = --input->buffer_len;
	while (i-- > cursor_pos)
		handle_arrow_left(input);
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
