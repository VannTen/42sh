/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:49:09 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/06 11:39:43 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "execution.h"
#include "print_ast.h"
#include "parser_defs.h"
#include "heredoc_creation.h"
#include <errno.h>

void			display_tokens(t_token *tokens)
{
	while (tokens)
	{
		ft_printf("[%s] ==> type = %zu\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
}

static int		update_history(t_history *history, t_input *input)
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
		add_cmd_to_history(history, input->buffer);
	return (0);
}

static int		error_messages(t_input *input, const int ret)
{
	(ret == EVENT_NOT_FOUND) ?
			ft_dprintf(STDERR_FILENO, "42sh: Event not found\n") : 0;
	if (ret == MALLOC_FAIL)
	{
		init_buffers(input);
		ft_dprintf(STDERR_FILENO, "42sh: Memory allocation failed."
				" Aborting process routine\n");
	}
	if (ret == INPUT_TOO_LONG)
	{
		ft_dprintf(STDERR_FILENO, "42sh: Input is too long."
							" Aborting process routine!\n");
		init_buffers(input);
		input->cursor_pos = 0;
	}
	return (0);
}

static void	parse_and_execute(t_token *list_tokens, t_parser const *parser)
{
	void					*result;
	struct s_parse_input	input;
	void					*bad_token;

	input.input = &list_tokens;
	input.get_token = take_token;
	input.del_token = no_destroy;
	if (parser == NULL)
		exit(1);
	errno = 0;
	result = execute_construct(parser, "PROGRAM", &input, &bad_token);
	if (result == NULL && errno == 0)
		ft_dprintf(STDERR_FILENO,
				"42sh: syntax error near unexpected token %s\n",
				g_tokens_name[get_tok_id(bad_token)]);
	shx_program(result);
	destroy_program(&result);
}

int				sh_loop(t_bsh *bsh)
{
	int		ret;

	while (getppid() != 1)
	{
		reset_lexer(&bsh->lexer);
		if ((ret = readline_process(&bsh->input, &bsh->lexer,
						&bsh->history, bsh->interactive)) == EVENT_NOT_FOUND
						|| ret == MALLOC_FAIL || ret == INPUT_TOO_LONG)
		{
			error_messages(&bsh->input, ret);
			continue ;
		}
		if (ret == END_OF_FILE)
			break ;
		if (lexer(&bsh->lexer, bsh->input.buffer) == MALLOC_FAIL)
			continue ;
		if (bsh->interactive)
			update_history(&bsh->history, &bsh->input);
		parse_and_execute(bsh->lexer.tokens[0], bsh->parser);
	}
	return (0);
}
