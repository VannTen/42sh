/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:19:38 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/31 16:41:07 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "history.h"

static void	go_to_beg_line(t_input *input)
{
	handle_home(input);
	reset_buffer(input);
	tputs(tgetstr("cr", NULL), 1, putchar_termcaps);
	tputs(tgetstr("cd", NULL), 1, putchar_termcaps);
}

static void	init_search(t_input *input)
{
	go_to_beg_line(input);
	ft_putstr_fd("History Search> ", STDERR);
	input->term->prompt_len = 16;
	input->term->cursor_col = 17;
	input->term->first_line_len = input->term->width - 16;
	if (wait_for_input(input, HISTORY_SEARCH) == UNEXPECTED_EOF)
	{
		go_to_beg_line(input);
		print_prompt(input, BOLD_CYAN);
		exit_ctrl_d(input);
	}
	input->buffer[--input->buffer_len] = '\0';
}

int			handle_history_search(t_input *input)
{
	int	i;

	init_search(input);
	if (input->buffer_len > 0)
	{
		i = input->history->len - 1;
		while (i >= 0)
		{
			if (ft_strstr(input->history->history[i], input->buffer))
			{
				go_to_beg_line(input);
				print_prompt(input, BOLD_CYAN);
				input->history->current = i;
				cp_history_to_buffer(input);
				input->type = REGULAR_INPUT;
				return (0);
			}
			i--;
		}
	}
	go_to_beg_line(input);
	print_prompt(input, BOLD_CYAN);
	input->type = REGULAR_INPUT;
	return (0);
}
