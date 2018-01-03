/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:14:03 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 14:20:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

#define PIPE_MAX 65536

static int	pipe_too_short(void)
{
	ft_putstr_fd("Pipe too short\n", STDERR);
	return (1);
}

int			redir_heredoc(t_redir *redir)
{
	t_list	*here_data;
	int		total;

	here_data = redir->heredoc_input[0];
	total = 0;
	if (pipe(redir->heredoc_pipe))
		ft_error_msg("Pipe failed");
	while (here_data)
	{
		if (total + here_data->content_size < PIPE_MAX)
		{
			write(redir->heredoc_pipe[WRITE], here_data->content,
				here_data->content_size);
			total += here_data->content_size;
			here_data = here_data->next;
		}
		else
			return (pipe_too_short());
	}
	if (dup2(redir->heredoc_pipe[READ], STDIN) < 0)
		return (1);
	close(redir->heredoc_pipe[WRITE]);
	close(redir->heredoc_pipe[READ]);
	return (0);
}
