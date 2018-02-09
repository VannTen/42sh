/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:39:03 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/09 15:47:37 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clear_lines(t_input *input, const char *str)
{
	if (input->buffer_len + (int)ft_strlen(str) > input->term->first_line_len)
	{
		tputs(tgetstr("sc", NULL), 1, putchar_termcaps);
		tputs(tgetstr("nw", NULL), 1, putchar_termcaps);
		tputs(tgetstr("cd", NULL), 1, putchar_termcaps);
		tputs(tgetstr("rc", NULL), 1, putchar_termcaps);
	}
	return (0);
}
