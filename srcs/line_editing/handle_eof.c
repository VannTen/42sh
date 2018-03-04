/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_eof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:46:47 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/04 18:10:18 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "history.h"

int		handle_clear_line_bf_cursor(t_input *input)
{
	int		cursor_pos;
	char	*buf;

	if (input->buffer_len > 0)
	{
		if (!(buf = ft_strdup(input->buffer + input->cursor_pos)))
			return (MALLOC_FAIL);
		cursor_pos = input->cursor_pos;
		handle_home(input);
		tputs(tgetstr("cd", NULL), 1, putchar_termcaps);
		ft_bzero(input->buffer, input->buffer_size);
		ft_strcpy(input->buffer, buf);
		free(buf);
		input->buffer_len -= cursor_pos;
		display_line(input, 0);
	}
	return (0);
}

int		handle_clear_line_af_cursor(t_input *input)
{
	if (input->buffer_len > 0)
	{
		ft_memset(input->buffer + input->cursor_pos, 0,
				input->buffer_len - input->cursor_pos + 1);
		handle_home(input);
		clear_lines(input, "");
		tputs(tgetstr("ce", NULL), 1, putchar_termcaps);
		display_line(input, input->buffer_len);
		input->buffer_len = input->cursor_pos;
	}
	return (0);
}

void	exit_ctrl_d(t_input *input)
{
	ft_putendl_fd("exit", STDERR_FILENO);
	save_history_to_histfile(input->history);
	restore_initial_attr(input->term);
	exit(0);
}

int		handle_eof(t_input *input)
{
	t_bsh const	*bsh = get_shell_data();

	if (input->buffer_len == 0 && input->type == REGULAR_INPUT)
		exit_ctrl_d(input);
	if (input->buffer_len == 0 && input->type == HEREDOC_INPUT)
		return (STOP_HEREDOC);
	if (input->buffer_len == 0 && input->type == UNCLOSED_QUOTES)
	{
		if (bsh->lexer.state == DQUOTE || bsh->lexer.state == QUOTE)
		{
			ft_dprintf(STDERR_FILENO, "42sh: unexpected EOF while looking for"
				" matching `%c'", bsh->lexer.state == DQUOTE ? '"' : '\'');
			reset_buffer(input);
			reset_lexer(&bsh->lexer);
			ft_bzero(input->buf_tmp, input->buffer_size);
			return (UNEXPECTED_EOF);
		}
		bsh->input.buf_tmp[ft_strlen(bsh->input.buf_tmp) - 1] = '\0';
		bsh->input.buf_tmp[ft_strlen(bsh->input.buf_tmp) - 1] = '\n';
		reset_lexer(&bsh->lexer);
		return (UNEXPECTED_EOF);
	}
	if (input->buffer_len == 0 && input->type == HISTORY_SEARCH)
		return (UNEXPECTED_EOF);
	return (0);
}
