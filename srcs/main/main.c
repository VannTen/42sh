/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:38:49 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/13 12:58:35 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "color.h"
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
	char *tmp;

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
		tmp = ft_strjoin(input->buf_tmp, input->buffer);
		ft_strdel(&input->buf_tmp);
		ft_strdel(&input->buffer);
		input->buffer = tmp;
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

#include "print_ast.h"
#include "shell_grammar.h"

size_t	get_tok_id(void const *token)
{
	t_token const *tok;

	if (token == tokens_name)
		return (DLESSDASH + 1);
	tok = token;
	return (tok->type);
}

void	*take_token(void *token_list_address)
{
	t_token **list_address;
	void	*token;

	list_address = token_list_address;
	if (*list_address != NULL)
	{
		token = *list_address;
		*list_address = (*list_address)->next;
		return (token);
	}
	else
		return ((void*)tokens_name);
}

#include "parser_interface.h"
#include "parser_defs.h"

static t_bool	test_parser(t_token *list_tokens, t_parser const *parser)
{
	void						*result;
	t_bool						syntax_valid;
	struct s_parse_input		input;

	input.input = &list_tokens;
	input.get_token = take_token;
	input.del_token = no_destroy;
	if (parser == NULL)
		exit(1);
	result = execute_construct(parser, "PROGRAM", &input);
	print_program(STDERR_FILENO, result);
	syntax_valid = result != NULL;
	return (syntax_valid);
}


int main(int argc, char **argv, char **environ)
{
	t_bsh				*bsh;
	int					ret;
	t_parser			*parser;

	(void)argc;
	(void)argv;
	if (!(bsh = (t_bsh*)malloc(sizeof(t_bsh))))
		return (MALLOC_FAIL);
	init_lexer(&bsh->lexer);
	init_history(&bsh->history, 10);
	init_term(&bsh->term);
	init_input(&bsh->input, &bsh->term, &bsh->history);
	init_env(&bsh->env, environ);
	init_termcaps(bsh);
	parser = generate_parser(g_shell_grammar, tokens_name, g_exec_rules, get_tok_id);
	print_grammar_back(STDERR_FILENO, parser->grammar);
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
		ft_dprintf(STDERR_FILENO,
				"\"%s\" : syntax is %svalid\n",
				bsh->input.buffer,
				test_parser(bsh->lexer.tokens[0], parser) ? " " : "not ");
	}
	return (0);
}
