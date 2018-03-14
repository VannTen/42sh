/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:39:03 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 11:02:43 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	go_to_beg_line(t_input *input)
{
	handle_home(input);
	reset_buffer(input);
	apply_termcaps("cr");
	apply_termcaps("cd");
}

int		clear_lines(t_input *input, const char *str)
{
	if (input->buffer_len + (int)ft_strlen(str) > input->term->first_line_len)
	{
		apply_termcaps("sc");
		apply_termcaps("nw");
		apply_termcaps("cd");
		apply_termcaps("rc");
	}
	return (0);
}
