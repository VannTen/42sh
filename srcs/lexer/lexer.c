/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:22:54 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/14 15:42:44 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

const char				g_op_char[MAX_OP_CHAR + 1] = "><&|;-!";
const char				*g_op_list[MAX_TOKENS + 1] = {
	NULL,
	NULL,
	NULL,
	"<<",
	">>",
	"<&",
	">&",
	"<",
	">",
	"&&",
	"||",
	";",
	"&",
	"|",
	">|",
	"<>",
	"<<-",
	"!",
	NULL,
};

static inline int	skip_char(t_lexer *lexer)
{
	(void)lexer;
	return (0);
}

const t_transition	g_lexer[MAX_STATE][MAX_EVENT] = {
	{{STD, skip_char},
		{DQUOTE, append_char},
		{QUOTE, append_char},
		{STD, append_char},
		{STD, NULL},
		{NWLINE, NULL},
		{COMMENT, NULL},
		{STD, append_char},
		{STD, handle_backslash}},

	{{DQUOTE, append_char},
		{STD, append_char},
		{DQUOTE, append_char},
		{DQUOTE, append_char},
		{DQUOTE, append_char},
		{DQUOTE, append_char},
		{DQUOTE, append_char},
		{DQUOTE, append_char},
		{DQUOTE, handle_backslash}},

	{{QUOTE, NULL},
		{QUOTE, append_char},
		{STD, append_char},
		{QUOTE, append_char},
		{QUOTE, append_char},
		{QUOTE, append_char},
		{QUOTE, append_char},
		{QUOTE, append_char},
		{QUOTE, append_char}},

	{{STD, append_char},
		{DQUOTE, append_char},
		{QUOTE, append_char},
		{STD, get_operator},
		{STD, delimitate_token},
		{NWLINE, end_of_input},
		{COMMENT, skip_char},
		{STD, append_char},
		{STD, handle_backslash}},

	{{NWLINE, NULL},
		{NWLINE, NULL},
		{NWLINE, NULL},
		{NWLINE, NULL},
		{NWLINE, NULL},
		{NWLINE, NULL},
		{NWLINE, NULL},
		{NWLINE, NULL},
		{NWLINE, NULL}},

	{{COMMENT, NULL},
		{COMMENT, skip_char},
		{COMMENT, skip_char},
		{COMMENT, skip_char},
		{COMMENT, skip_char},
		{NWLINE, end_of_input},
		{COMMENT, skip_char},
		{COMMENT, skip_char},
		{COMMENT, skip_char}}
};

int					handle_backslash(t_lexer *lexer)
{
	if (is_operator(lexer->current_token) > 0)
		if (delimitate_token(lexer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	if (is_operator(lexer->current_token) == -1)
	{
		if (lexer->token_len + 2 >= lexer->token_size)
			if (realloc_current_token(lexer) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		lexer->current_token[lexer->token_len++] = *(lexer->input);
		lexer->input++;
		lexer->current_token[lexer->token_len++] = *(lexer->input);
	}
	return (0);
}

int					reset_lexer(t_lexer *lexer)
{
	clear_tokens(&lexer->tokens[0]);
	lexer->tokens[1] = NULL;
	lexer->state = INIT;
	lexer->event = 0;
	ft_bzero(lexer->current_token, lexer->token_size);
	lexer->token_len = 0;
	lexer->input = NULL;
	return (0);
}

int					lexer(t_lexer *lexer, char *input)
{
	lexer->input = input;
	lexer->event = 0;
	if (lexer->state != INIT)
		get_event(lexer);
	while (lexer->state != NWLINE && *(lexer->input) != '\0')
	{
		if (g_lexer[lexer->state][lexer->event].p_transit(lexer) == MALLOC_FAIL)
		{
			reset_lexer(lexer);
			return (MALLOC_FAIL);
		}
		(lexer->state != INIT) ? lexer->input++ : 0;
		lexer->state = g_lexer[lexer->state][lexer->event].new_state;
		get_event(lexer);
	}
	if (delimitate_token(lexer) == MALLOC_FAIL)
	{
		reset_lexer(lexer);
		return (MALLOC_FAIL);
	}
	lexer->input = NULL;
	(lexer->state == NWLINE) ? lexer->state = INIT : 0;
	return (0);
}
