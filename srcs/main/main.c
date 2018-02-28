/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:38:49 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/28 10:58:01 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "g_builtin_array.h"
#include "s_shx_global.h"
#include "execution.h"
#include "print_ast.h"
#include "parser_defs.h"

void		display_tokens(t_token *tokens)
{
	while (tokens)
	{
		ft_printf("[%s] ==> type = %zu\n", tokens->value, tokens->type);
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

static int	error_messages(t_input *input, const int ret)
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
static t_bool	test_parser(t_token *list_tokens, t_parser const *parser,
				t_bsh *bsh)
{
	void					*result;
	t_bool					syntax_valid;
	struct s_parse_input	input;
	struct s_shx_global		global;

	input.input = &list_tokens;
	input.get_token = take_token;
	input.del_token = no_destroy;
	if (parser == NULL)
		exit(1);
	result = execute_construct(parser, "PROGRAM", &input);
	print_program(STDERR_FILENO, result, 0);
	global.env = &(bsh->env);
	global.hashtable = NULL;
	global.latest_ret = 0;
	shx_program(result, &global);
	syntax_valid = result != NULL;
	destroy_program(&result);
	return (syntax_valid);
}

int			sh_loop(t_bsh *bsh)
{
	int		ret;

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
		if (bsh->interactive)
			if (update_history(&bsh->history, &bsh->input) == MALLOC_FAIL)
				continue ;
		test_parser(bsh->lexer.tokens[0], bsh->parser, bsh);
	}
	return (0);
}

int			main(int argc, char **argv, char **environ)
{
	t_bsh	*bsh;

	set_shell_sigmode(e_shell_sigmode_shell);
	bsh = shell_init(environ, argc, argv);
	(bsh->interactive) ? init_termcaps(bsh) : 0;
	sh_loop(bsh);
	return (0);
}
