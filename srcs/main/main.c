/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:15:06 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/05 19:16:17 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"
#include "stdio.h"

/*void	display_tokens(t_token *tk)
{
	t_token	*t;

	t = tk;
	while (t)
	{
		if (t->next)
			ft_printf("[%s] ->", t->token);
		else
			ft_printf("[%s]", t->token);
		t = t->next;
	}
	ft_printf("\n");
}*/

static void	connect_tokens(t_bsh *bsh)
{
	bsh->tokens[0] = bsh->lexer->token_list[0];
	bsh->tokens[1] = bsh->lexer->token_list[1];
	bsh->lexer->token_list[0] = NULL;
	bsh->lexer->token_list[1] = NULL;
}

static void	start_process(t_bsh *bsh)
{
	int		ret;

	ret = 0;
	lexer(bsh->lexer, bsh->input->buffer, INIT);
	connect_tokens(bsh);
	ret = parser(&(bsh->exec), bsh->tokens[0], SAVE_EXEC);
	if (ret == UNCLOSED_QUOTES || ret == END_IS_OP)
	{
		if (bsh->interactive)
		{
			if (handle_unclosed_quotes(bsh->lexer, bsh->input, &ret,
						bsh->tokens) == CATCH_SIGINT)
				return ;
			bsh->tokens[1]->pushed = 0;
			if (ret == ACCEPTED)
				ret = parser(&(bsh->exec), bsh->tokens[0], SAVE_EXEC);
		}
		else
			ft_printf("Missing quotes or end of input is an operator\n");
	}
	/*display_tokens(bsh->tokens[0]);*/
	add_cmd_to_history(bsh);
	(ret == ACCEPTED && bsh->exec) ? execution(bsh) : 0;
}

static int	file_input(t_bsh *bsh)
{
	int			len;
	char		*line;
	struct stat	stat;

	len = 0;
	if (fstat(STDIN, &stat) < 0)
		ft_error_msg("fstat failed");
	if (S_ISDIR(stat.st_mode))
		ft_putendl_fd("bsh: stdin: Is a directory", STDERR);
	else
	{
		while (get_next_line(STDIN, &line) > 0)
		{
			len = ft_strlen(line);
			while (bsh->input->buffer_size < len)
				realloc_buffer(bsh->input);
			ft_strcpy(bsh->input->buffer, line);
			bsh->input->buffer[len] = '\n';
			start_process(bsh);
			ft_bzero(bsh->input->buffer, len);
			clear_token_list(&bsh->tokens[0]);
			clear_exec(&(bsh->exec));
			ft_strdel(&line);
		}
	}
	return (bsh->exit_status);
}

int			main(int argc, char **argv, char **environ)
{
	t_bsh	*bsh;

	(void)argc;
	(void)argv;
	bsh = shell_init(environ);
	if (!(bsh->interactive = isatty(STDIN)))
		return (file_input(bsh));
	else
	{
		init_termcaps(bsh->term);
		while (42)
		{
			ft_bzero(bsh->input->buffer, bsh->input->buffer_len);
			get_term_size(bsh->term);
			bsh->input->buffer_len = 0;
			print_prompt(bsh->term, BOLD_CYAN);
			wait_for_input(bsh->input, REGULAR_INPUT);
			start_process(bsh);
			clear_token_list(&bsh->tokens[0]);
			clear_exec(&(bsh->exec));
		}
	}
	restore_initial_attr(bsh->term);
	return (0);
}
