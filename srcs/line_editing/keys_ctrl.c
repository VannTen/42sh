/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:33:58 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/22 15:32:10 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		handle_ctrl_down(t_input *input)
{
	if (input->cursor_pos + input->term->width < input->buffer_len)
	{
		apply_termcaps("do");
		if (input->term->cursor_col != 1)
			tputs(tgoto(tgetstr("RI", NULL), 0, input->term->cursor_col - 1),
			1, putchar_termcaps);
		input->cursor_pos += input->term->width;
	}
	else
		handle_end(input);
	return (0);
}

int		handle_ctrl_up(t_input *input)
{
	int	nb;

	nb = input->term->prompt_len - input->term->cursor_col + 1;
	if (input->cursor_pos >= input->term->first_line_len)
	{
		apply_termcaps("up");
		if (input->term->cursor_col <= input->term->prompt_len &&
			input->cursor_pos < input->term->first_line_len +
			input->term->width)
		{
			tputs(tgoto(tgetstr("RI", NULL), 0, nb), 1, putchar_termcaps);
			input->cursor_pos = 0;
			input->term->cursor_col = input->term->prompt_len + 1;
		}
		else
			input->cursor_pos -= input->term->width;
	}
	return (0);
}

int		handle_ctrl_right(t_input *input)
{
	if (input->cursor_pos != input->buffer_len)
	{
		while (ft_isprint(input->buffer[input->cursor_pos]))
		{
			handle_arrow_right(input);
			if (input->buffer[input->cursor_pos] == ' ' &&
			input->buffer[input->cursor_pos - 1] != ' ')
				break ;
		}
	}
	return (0);
}

int		handle_ctrl_left(t_input *input)
{
	if (input->cursor_pos)
	{
		while (ft_isprint(input->buffer[input->cursor_pos]) ||
		!input->buffer[input->cursor_pos])
		{
			handle_arrow_left(input);
			if (!input->cursor_pos
					|| (input->buffer[input->cursor_pos] != ' '
					&& input->buffer[input->cursor_pos - 1] == ' '))
				break ;
		}
	}
	return (0);
}

int		handle_clear_screen(t_input *input)
{
	int	i;
	int	cursor_pos;

	cursor_pos = input->cursor_pos;
	apply_termcaps("cl");
	if (input->type == REGULAR_INPUT)
		print_prompt(input);
	else if (input->type == HISTORY_SEARCH)
		ft_putstr_fd("History search> ", STDERR_FILENO);
	else if (input->type == HEREDOC_INPUT)
		ft_putstr_fd("heredoc> ", STDERR_FILENO);
	else
		ft_putstr_fd("> ", STDERR_FILENO);
	input->cursor_pos = 0;
	input->term->cursor_col = input->term->prompt_len + 1;
	display_buffer(input, 0);
	i = input->buffer_len;
	while (i-- > cursor_pos)
		handle_arrow_left(input);
	return (0);
}
