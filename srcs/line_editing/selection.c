/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:36:10 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 10:49:14 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	switch_input_state(t_input *input)
{
	if (input->state == SELECTION)
		input->state = STANDARD;
	else
		input->state = SELECTION;
	if (input->pivot == -1)
		input->pivot = input->cursor_pos;
	else
	{
		input->pivot = -1;
		apply_termcaps("me");
		display_line(input, input->cursor_pos);
	}
	return (0);
}

int	skip_key(t_input *input)
{
	(void)input;
	return (0);
}

int	select_right(t_input *input)
{
	apply_termcaps("me");
	if (input->cursor_pos != input->buffer_len)
		display_line(input, input->cursor_pos + 1);
	return (0);
}

int	select_left(t_input *input)
{
	apply_termcaps("me");
	if (input->cursor_pos > 0)
		display_line(input, input->cursor_pos - 1);
	return (0);
}
