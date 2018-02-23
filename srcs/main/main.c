/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:38:49 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/23 17:16:41 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	display_tokens(t_token *tokens)
{
	while (tokens)
	{
		ft_printf("[%s] ==> type = %d\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
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

/*size_t	get_token_id(void const *token)
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

static int	error_messages(t_input *input, const int ret)
{
	(ret == EVENT_NOT_FOUND) ?
			dprintf(STDERR_FILENO, "42sh: Event not found\n") : 0;
	if (ret == MALLOC_FAIL)
	{
		init_buffers(input);
		dprintf(STDERR_FILENO, "42sh: Memory allocation failed."
				" Aborting process routine\n");
	}
	if (ret == INPUT_TOO_LONG)
	{
		dprintf(STDERR_FILENO, "42sh: Input is too long."
							" Aborting process routine!\n");
		init_buffers(input);
		input->cursor_pos = 0;
	}
	return (0);
}

int			main(int argc, char **argv, char **environ)
{
	t_bsh	*bsh;
	int		ret;
	/*t_parser	*parser;
	//parser = generate_parser(g_grammar, tokens_name, exec_rules, get_token_id);*/
	bsh = shell_init(environ, argc, argv);
	(bsh->interactive) ? init_termcaps(bsh) : 0;
	while (42)
	{
		reset_lexer(&bsh->lexer);
		if ((ret = readline_process(&bsh->input, &bsh->lexer,
						&bsh->history, bsh->interactive)) == EVENT_NOT_FOUND
						|| ret == MALLOC_FAIL || ret == INPUT_TOO_LONG)
		{
			error_messages(&bsh->input, ret);
			continue ;
		}
		if (lexer(&bsh->lexer, bsh->input.buffer) == MALLOC_FAIL)
			continue ;
		//if (bsh->interactive)
			if (update_history(&bsh->history, &bsh->input) == MALLOC_FAIL)
				continue ;
		display_history(&bsh->history);
		//execute_construct(parser, "PROGRAM", &bsh->lexer.tokens[0], take_token);
	}
	return (0);
}
