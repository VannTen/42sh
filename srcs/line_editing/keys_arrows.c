/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:12:58 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/21 17:45:27 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	handle_arrow_left(t_input *input)
{
	if (input->cursor_pos > 0)
	{
		if (input->term->cursor_col == 1)
		{
			tputs(tgetstr("up", NULL), 1, ft_putchar_termcaps);
			tputs(tgoto(tgetstr("RI", NULL), 0, input->term->width), 1,
					ft_putchar_termcaps);
			input->term->cursor_col = input->term->width;
		}
		else
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_termcaps);
			input->term->cursor_col--;
		}
		input->cursor_pos--;
	}
	return (0);
}

int	handle_arrow_right(t_input *input)
{
	if (input->cursor_pos < input->buffer_len)
	{
		if (input->term->cursor_col == input->term->width)
		{
			tputs(tgetstr("do", NULL), 1, ft_putchar_termcaps);
			input->term->cursor_col = 1;
		}
		else
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar_termcaps);
			input->term->cursor_col++;
		}
		input->cursor_pos++;
	}
	return (0);
}

int	handle_arrow_up(t_input *input)
{
//	ft_printf("{%d}\n", input->history->current);
	if (input->history->current == 0)
		return (0);
	else
		input->history->current--;
	if (input->history->current != -1)
		cp_history_to_buffer(input);
	return (0);
}

int	handle_arrow_down(t_input *input)
{
	//ft_printf("{%d}\n", input->history->current);
	if (input->history->current != input->history->len)
	{
		input->history->current++;
		if (input->history->current != input->history->len)
			cp_history_to_buffer(input);
		else
		{
			handle_home(input);
			tputs(tgetstr("sc", NULL), 1, ft_putchar_termcaps);
			tputs(tgetstr("nw", NULL), 1, ft_putchar_termcaps);
			tputs(tgetstr("cd", NULL), 1, ft_putchar_termcaps);
			tputs(tgetstr("rc", NULL), 1, ft_putchar_termcaps);
			ft_bzero(input->buffer, input->buffer_size);
			input->buffer_len = 0;
			input->cursor_pos = 0;
			input->term->cursor_col = input->term->prompt_len + 1;
		}
	}
	return (0);
}
