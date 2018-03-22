/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_sigint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:52:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/22 15:19:38 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		g_sigint_detected = 0;

void	readline_sigint(int sigid)
{
	t_bsh *const	bsh = get_shell_data();

	(void)sigid;
	g_sigint_detected = 1;
	if (bsh->input.type == HISTORY_SEARCH)
	{
		go_to_beg_line(&bsh->input);
		apply_termcaps("up");
	}
	apply_termcaps("me");
	if (bsh->input.buf_tmp)
		ft_memset(bsh->input.buf_tmp, 0, ft_strlen(bsh->input.buf_tmp));
	if (bsh->input.type != HISTORY_SEARCH)
	{
		handle_end(&bsh->input);
		write(STDERR_FILENO, "\n", 1);
	}
	reset_buffer(&bsh->input);
	bsh->input.pivot = -1;
	bsh->input.state = STANDARD;
	reset_completion_data(&bsh->input.comp);
	(bsh->input.type != HEREDOC_INPUT) ? reset_lexer(&bsh->lexer) : 0;
	bsh->input.type = REGULAR_INPUT;
	bsh->history.current = bsh->history.len;
	bsh->exit_status = 1;
}
