/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_eof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:46:47 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 17:31:33 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int		handle_clear_line(t_input *input)
{
	int		cursor_pos;
	char	*buf;

	if (input->buffer_len > 0)
	{
		if (!(buf = ft_strdup(input->buffer + input->cursor_pos)))
			ft_error_msg("Malloc failed\n");
		cursor_pos = input->cursor_pos;
		handle_home(input);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_termcaps);
		ft_bzero(input->buffer, input->buffer_size);
		ft_strcpy(input->buffer, buf);
		free(buf);
		input->buffer_len -= cursor_pos;
		display_line(input, 0);
	}
	return (0);
}

void	exit_ctrl_d(void)
{
	ft_putendl_fd("exit", STDERR);
	save_history_to_hist_file();
	restore_initial_attr(get_bsh()->term);
	exit(0);
}

int		handle_eof(t_input *input)
{
	if (input->buffer_len == 0 && input->type == REGULAR_INPUT)
		exit_ctrl_d();
	if (input->buffer_len == 0 && input->type == HEREDOC_INPUT)
		return (STOP_HEREDOC);
	if (input->buffer_len == 0 && input->type == UNCLOSED_QUOTES)
		return (UNEXPECTED_EOF);
	if (input->buffer_len == 0 && input->type == HISTORY_SEARCH)
		return (UNEXPECTED_EOF);
	return (0);
}
