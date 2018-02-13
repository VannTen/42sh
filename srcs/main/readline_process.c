/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:31:00 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/13 12:56:19 by bjanik           ###   ########.fr       */
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

static int	get_line(t_lexer *lex, t_input *input)
{
	reset_buffer(input);
	if (wait_for_input(input, REGULAR_INPUT) == MALLOC_FAIL
					|| lexer(lex, input->buffer) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	while (lex->state != INIT)
	{
		clear_tokens(&lex->tokens[0]);
		input->buf_tmp = input->buffer;
		if (!(input->buffer = ft_strnew(input->buffer_size)))
			return (MALLOC_FAIL);
		display_basic_prompt(input);
		if (wait_for_input(input, UNCLOSED_QUOTES) == MALLOC_FAIL
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

static int	init_exp_input(t_string *exp_input, const int size)
{
	if (!(exp_input->str = ft_strnew(size)))
		return (MALLOC_FAIL);
	exp_input->len = 0;
	exp_input->size = size;
	return (0);
}

int			readline_process(t_input *input, t_lexer *lexer, t_history *history)
{
	int			ret;
	t_string	exp_input;

	if (init_exp_input(&exp_input, input->buffer_size) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	print_prompt(input, BOLD_CYAN);
	if (get_line(lexer, input) == MALLOC_FAIL)
	{
		ft_strdel(&exp_input.str);
		return (MALLOC_FAIL);
	}
	if ((ret = get_expanded_input(lexer, history, input->buffer, &exp_input)))
	{
		ft_strdel(&exp_input.str);
		return (ret);
	}
	else
	{
		ft_strdel(&input->buffer);
		input->buffer = exp_input.str;
	}
	input->buffer_len = ft_strlen(input->buffer);
	if (input->buffer[input->buffer_len - 1] != '\n')
		input->buffer[input->buffer_len++] = '\n';
	return (0);
}
