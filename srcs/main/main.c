/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:38:49 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/26 17:16:54 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <unistd.h>

void	display_tokens(t_token *tokens)
{
	while (tokens)
	{
		ft_printf("[%s] ==> %zu\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
}

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
	char *limit;

	limit = input->buffer + input->buffer_len;
	reset_buffer(input);
	if (wait_for_input(input, REGULAR_INPUT) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (lexer(lex, input->buffer) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	while (lex->state != INIT)
	{
		clear_tokens(&lex->tokens[0]);
		input->buf_tmp = input->buffer;
		if (!(input->buffer = ft_strnew(input->buffer_size)))
			return (MALLOC_FAIL);
		display_basic_prompt(input);
		if (wait_for_input(input, REGULAR_INPUT) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		if (lexer(lex, input->buffer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		input->buffer = ft_strjoin_free(input->buf_tmp, input->buffer, 3);
		input->buffer_len = ft_strlen(input->buffer);
		input->buffer_size = input->buffer_len;
	}
	remove_backslash_nl(input, lex);
	return (0);
}

static int	update_history(t_history *history, t_input *input)
{
	int	i;

	i = -1;
	input->buffer[--input->buffer_len] = '\0';
	while (input->buffer[++i])
	{
		if (input->buffer[i] == '\n')
			input->buffer[i] = ' ';
	}
	if (input->buffer_len > 0 && (!history->len ||
				ft_strcmp(input->buffer, history->history[history->len - 1])))
		if (add_cmd_to_history(history, input->buffer))
			return (MALLOC_FAIL);
	return (0);
}

static int	readline_process(t_input *input, t_lexer *lexer, t_history *history)
{
	int		ret;
	t_string	exp_input = {ft_strnew(input->buffer_size), 0,
							input->buffer_size};

	print_prompt(input, BOLD_CYAN);
	if (get_line(lexer, input) == MALLOC_FAIL)
	{
		ft_strdel(&exp_input.str);
		return (MALLOC_FAIL);
	}
	//input->buffer[--input->buffer_len] = '\0';
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

/*static char const	g_grammar[] =
" PROGRAM : COMPLETE_COMMAND NEWLINE"
"| NEWLINE;"
"COMPLETE_COMMAND : LIST SEPARATOR_OP"
"| LIST;"
"LIST : LIST SEPARATOR_OP AND_OR"
"| AND_OR;"
"AND_OR : PIPELINE"
"| AND_OR AND_IF PIPELINE"
"| AND_OR OR_IF PIPELINE;"
"PIPELINE : COMMAND"
"| PIPELINE PIPE COMMAND;"
"COMMAND : CMD_PREFIX CMD_WORD CMD_SUFFIX"
"| CMD_PREFIX CMD_WORD"
"| CMD_PREFIX"
"| CMD_NAME CMD_SUFFIX"
"| CMD_NAME;"
"CMD_NAME : WORD;"
"CMD_WORD : WORD;"
"CMD_PREFIX : IO_REDIRECT"
"| CMD_PREFIX IO_REDIRECT;"
"CMD_SUFFIX : IO_REDIRECT"
"| CMD_SUFFIX IO_REDIRECT"
"| WORD"
"| CMD_SUFFIX WORD;"
"IO_REDIRECT : IO_FILE"
"| IO_NUMBER IO_FILE"
"| IO_HERE"
"| IO_NUMBER IO_HERE;"
"IO_FILE : LESS FILENAME"
"| LESSAND FILENAME"
"| GREAT FILENAME"
"| GREATAND FILENAME"
"| DGREAT FILENAME"
"| CLOBBER FILENAME;"
"FILENAME : WORD;"
"IO_HERE : DLESS HERE_END;"
"HERE_END: WORD;"
"SEPARATOR_OP: AND"
"| SEMI;";

char const			*tokens_name[] = {
	"WORD",
	"NEWLINE",
	"IO_NUMBER",
	"DLESS",
	"DGREAT",
	"LESSAND",
	"GREATAND",
	"LESS",
	"GREAT",
	"AND_IF",
	"OR_IF",
	"SEMI",
	"AND",
	"PIPE",
	"CLOBBER",
	NULL
};

size_t	get_token_id(void const *token)
{
	t_token const *tok;

	tok = token;
	return (tok->type);
}

void	*take_token(void *token_list_address)
{
	t_token **list_address;
	void	*token;

	list_address = token_list_address;
	token = *list_address;
	*list_address = (*list_address)->next;
	return (token);
}

#include "parser_interface.h"*/

int main(int argc, char **argv, char **environ)
{
	t_bsh	*bsh;
	int		ret;
	/*t_parser	*parser;
	t_exec	const		exec_rules[] = {
		{.name = NULL, .create = NULL, .give = NULL}};*/

	(void)argc;
	(void)argv;
	//parser = generate_parser(g_grammar, tokens_name, exec_rules, get_token_id);
	if (!(bsh = (t_bsh*)malloc(sizeof(t_bsh))))
		return (MALLOC_FAIL);
	init_lexer(&bsh->lexer);
	init_history(&bsh->history, 10);
	init_term(&bsh->term);
	init_input(&bsh->input, &bsh->term, &bsh->history);
	init_env(&bsh->env, environ);
	init_termcaps(bsh);
	while (42)
	{
		reset_lexer(&bsh->lexer);
		if ((ret = readline_process(&bsh->input, &bsh->lexer,
						&bsh->history)) == EVENT_NOT_FOUND
						|| ret == MALLOC_FAIL)
		{
			(ret == EVENT_NOT_FOUND) ?
				ft_dprintf(STDERR_FILENO, "bsh: event not found\n") : 0;
			if (ret == MALLOC_FAIL)
				init_buffers(&bsh->input);
			continue ;
		}
		if (lexer(&bsh->lexer, bsh->input.buffer) == MALLOC_FAIL)
			continue ;
		if (update_history(&bsh->history, &bsh->input) == MALLOC_FAIL)
			continue ;
		#ifdef DEBUG
		display_history(bsh->history);
		#endif
		display_tokens(bsh->lexer.tokens[0]);
		reset_lexer(&bsh->lexer);
		//execute_construct(parser, "PROGRAM", &bsh->lexer.tokens[0], take_token);
	}
	return (0);
}
