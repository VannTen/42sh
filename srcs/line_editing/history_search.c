/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:19:38 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/03 13:51:32 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	exit_history_search_mode(t_input *input)
{
	go_to_beg_line(input);
	print_prompt(input, BOLD_CYAN);
}

static int	init_search(t_input *input)
{
	int	ret;

	go_to_beg_line(input);
	ft_putstr_fd("History Search> ", STDERR_FILENO);
	input->term->prompt_len = 16;
	input->term->cursor_col = 17;
	input->term->first_line_len = input->term->width - 16;
	if ((ret = (wait_for_input(input, HISTORY_SEARCH) == UNEXPECTED_EOF)))
	{
		exit_history_search_mode(input);
		exit_ctrl_d(input);
	}
	else if (ret == CATCH_SIGINT)
		return (ret);
	input->buffer[--input->buffer_len] = '\0';
	return (0);
}

int			handle_history_search(t_input *input)
{
	int	i;

	if (init_search(input) == CATCH_SIGINT)
		return (CATCH_SIGINT);
	if (input->buffer_len > 0)
	{
		i = input->history->len - 1;
		while (i >= 0)
		{
			if (ft_strstr(input->history->history[i], input->buffer))
			{
				exit_history_search_mode(input);
				input->history->current = i;
				cp_history_to_buffer(input);
				input->type = REGULAR_INPUT;
				return (0);
			}
			i--;
		}
	}
	exit_history_search_mode(input);
	input->type = REGULAR_INPUT;
	return (0);
}
