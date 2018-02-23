/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:31:00 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/23 17:52:41 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	remove_backslash_nl(t_input *input, t_lexer *lexer)
{
	int	i;

	i = 0;
	clear_tokens(&lexer->tokens[0]);
	input->buffer[--input->buffer_len] = '\0';
	input->buf_tmp = input->buffer;
	if (!(input->buffer = ft_strnew(input->buffer_size)))
		return (MALLOC_FAIL);
	lexer->input = input->buf_tmp;
	while (*(lexer->input))
	{
		get_event(lexer);
		lexer->state = g_lexer[lexer->state][lexer->event].new_state;
		if (*(lexer->input) == '\\'
				&& *(lexer->input + 1) == '\n'
				&& lexer->state != QUOTE
				&& lexer->state != COMMENT)
			lexer->input += 2;
		else
			input->buffer[i++] = *(lexer->input++);
	}
	input->buffer[input->buffer_len++] = '\n';
	ft_strdel(&input->buf_tmp);
	return (0);
}

static int	get_line(t_input *input, const int interactive, int mode)
{
	char	*line;
	size_t	len;
	int		ret;

	if (interactive == 1)
	{
		if (wait_for_input(input, mode) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	else
	{
		if ((ret = get_next_line(input->fd, &line)) > 0)
		{
			len = ft_strlen(line);
			while (len + 1 >= input->buffer_size)
				if (realloc_buffer(input) == MALLOC_FAIL)
					return (MALLOC_FAIL);
			ft_strcpy(input->buffer, line);
			input->buffer[len] = '\n';
			input->buffer_len = len + 1;
			ft_strdel(&line);
		}
		else if (ret < 0)
			exit(EXIT_FAILURE);
		else
			exit(0);
	}
}

static int	get_line_to_buffer(t_lexer *lex, t_input *input,
								const int interactive)
{
	reset_buffer(input);
	if (get_line(input, interactive, REGULAR_INPUT) == MALLOC_FAIL
					|| lexer(lex, input->buffer) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	while (lex->state != INIT)
	{
		clear_tokens(&lex->tokens[0]);
		input->buf_tmp = input->buffer;
		if (!(input->buffer = ft_strnew(input->buffer_size)))
			return (MALLOC_FAIL);
		display_basic_prompt(input);
		if (get_line(input, interactive, UNCLOSED_QUOTES) == MALLOC_FAIL
		|| lexer(lex, input->buffer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		while ((int)ft_strlen(input->buf_tmp)
							+ input->buffer_len > input->buffer_size)
			if (realloc_buffer(input) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		ft_swap((void**)&input->buffer, (void**)&input->buf_tmp);
		strcat(input->buffer, input->buf_tmp);
		ft_strdel(&input->buf_tmp);
		input->buffer_len = ft_strlen(input->buffer);
	}
	remove_backslash_nl(input, lex);
	return (0);
}

static int	init_exp_input(t_string *exp_input, const int size,
							const int interactive)
{
	if (interactive)
		if (!(exp_input->str = ft_strnew(size)))
			return (MALLOC_FAIL);
	exp_input->len = 0;
	exp_input->size = size;
	return (0);
}

int			readline_process(t_input *input, t_lexer *lexer, t_history *history,
							const int interact)
{
	int			ret;
	t_string	exp_input;

	(interact) ? print_prompt(input, BOLD_CYAN) : 0;
	if (get_line_to_buffer(lexer, input, interact) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (!interact)
		return (0);
	if (init_exp_input(&exp_input, input->buffer_size, interact) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if ((ret = get_expanded_input(lexer, history, input->buffer, &exp_input)))
	{
		ft_strdel(&exp_input.str);
		return (ret);
	}
	ft_strdel(&input->buffer);
	input->buffer = exp_input.str;
	input->buffer_len = ft_strlen(input->buffer);
	input->buffer_size = exp_input.size;
	if (input->buffer[input->buffer_len - 1] != '\n')
		input->buffer[input->buffer_len++] = '\n';
	return (0);
}
