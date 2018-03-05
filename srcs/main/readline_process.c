/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:31:00 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/05 13:11:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	remove(t_input *input)
{
	if (!ft_strcmp(input->buf_tmp, "\\\n"))
		ft_memset(input->buf_tmp, '\0', 2);
}

static int	remove_backslash_nl(t_input *input, t_lexer *lexer)
{
	int	i;

	i = 0;
	clear_tokens(&lexer->tokens[0]);
	input->buf_tmp = input->buffer;
	remove(input);
	if (!(input->buffer = ft_strnew(input->buffer_size)))
		return (MALLOC_FAIL);
	lexer->input = input->buf_tmp;
	while (*(lexer->input))
	{
		get_event(lexer);
		lexer->state = g_lexer[lexer->state][lexer->event].new_state;
		if (*(lexer->input) == '\\' && *(lexer->input + 1) == '\n'
				&& lexer->state != QUOTE && lexer->state != COMMENT
				&& *(lexer->input + 2) != '\0')
			lexer->input += 2;
		else
			input->buffer[i++] = *(lexer->input++);
	}
	ft_strdel(&input->buf_tmp);
	reset_lexer(lexer);
	return (0);
}

static int	loop_while_unclosed_quotes(t_lexer *lex, t_input *input,
										int interct)
{
	while (lex->state != INIT)
	{
		clear_tokens(&lex->tokens[0]);
		input->buf_tmp = input->buffer;
		if (!(input->buffer = ft_strnew(input->buffer_size)))
			return (MALLOC_FAIL);
		(interct) ? display_basic_prompt(input) : 0;
		if (getline(input, interct, UNCLOSED_QUOTES, &lex->state) == MALLOC_FAIL
		|| lexer(lex, input->buffer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		while ((int)ft_strlen(input->buf_tmp)
					+ input->buffer_len > input->buffer_size)
			if (realloc_buffer(input) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		ft_swap((void**)&input->buffer, (void**)&input->buf_tmp);
		ft_strcat(input->buffer, input->buf_tmp);
		ft_strdel(&input->buf_tmp);
		input->buffer_len = ft_strlen(input->buffer);
	}
	return (0);
}

static int	get_complete_line_to_buffer(t_lexer *lex, t_input *input,
								const int is_interactive)
{
	int	ret;

	reset_buffer(input);
	if ((ret = getline(input, is_interactive, REGULAR_INPUT,
					&lex->state)) == MALLOC_FAIL
			|| lexer(lex, input->buffer) == MALLOC_FAIL || ret == END_OF_FILE)
		return (ret);
	if ((ret = loop_while_unclosed_quotes(lex, input,
					is_interactive)) == MALLOC_FAIL || ret == END_OF_FILE)
		return (ret);
	return (remove_backslash_nl(input, lex));
}

int			readline_process(t_input *input, t_lexer *lexer, t_history *history,
							const int interact)
{
	int			ret;
	t_string	exp_input;

	(interact) ? print_prompt(input, BOLD_CYAN) : 0;
	if ((ret = get_complete_line_to_buffer(lexer, input,
					interact)) == MALLOC_FAIL || ret == END_OF_FILE)
		return (ret);
	if (!interact)
		return (0);
	if (init_exp_input(&exp_input, input->buffer_size) == MALLOC_FAIL)
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
	if ((input->buffer_len > 0 && input->buffer[input->buffer_len - 1] != '\n')
			|| !input->buffer_len)
		input->buffer[input->buffer_len++] = '\n';
	return (0);
}
