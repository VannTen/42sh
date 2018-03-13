/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_previous_characters.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:32:13 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/13 12:33:52 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	swap_previous_characters(t_input *input)
{
	char	tmp;

	if (input->cursor_pos > 1)
	{
		tmp = input->buffer[input->cursor_pos - 1];
		input->buffer[input->cursor_pos - 1] =
					input->buffer[input->cursor_pos - 2];
		input->buffer[input->cursor_pos - 2] = tmp;
	}
	display_line(input, input->cursor_pos);
	return (0);
}
