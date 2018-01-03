/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:46:36 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:13:27 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static void	append_to_heredoc_data(t_redir *redir, t_list *here_in)
{
	if (redir->heredoc_input[0] == NULL)
	{
		redir->heredoc_input[0] = here_in;
		redir->heredoc_input[1] = here_in;
	}
	else
	{
		redir->heredoc_input[1]->next = here_in;
		redir->heredoc_input[1] = here_in;
	}
}

static int	save_heredoc(t_redir *redir)
{
	t_input	*input;
	t_list	*here_in;

	input = get_bsh()->input;
	while (42)
	{
		display_basic_prompt(input->term);
		if (wait_for_input(input, HEREDOC_INPUT) == STOP_HEREDOC)
			break ;
		if (input->type == REGULAR_INPUT)
			return (CATCH_SIGINT);
		input->buffer[--input->buffer_len] = '\0';
		if (input->buffer_len > 1)
		{
			if (!ft_strcmp(input->buffer, redir->here_end))
				break ;
		}
		input->buffer[input->buffer_len++] = '\n';
		here_in = ft_lstnew(input->buffer, input->buffer_len);
		append_to_heredoc_data(redir, here_in);
	}
	return (0);
}

int			handle_heredocs(t_exec *exec)
{
	t_exec	*ex;
	t_redir	*rd;

	remove_quotes_heredoc(get_bsh()->exp, exec);
	ex = exec;
	while (ex)
	{
		rd = ex->redir_list;
		while (rd)
		{
			if (rd->here_end)
				if (save_heredoc(rd) == CATCH_SIGINT)
					return (CATCH_SIGINT);
			rd = rd->next;
		}
		ex = ex->next;
	}
	return (0);
}

void		close_heredoc_pipes(t_redir *redir)
{
	t_redir	*rd;

	rd = redir;
	while (rd)
	{
		if (rd->type == DLESS)
		{
			close(rd->heredoc_pipe[WRITE]);
			close(rd->heredoc_pipe[READ]);
		}
		rd = rd->next;
	}
}
