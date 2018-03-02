/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_sigint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:52:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/02 19:59:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		g_sigint_detected = 0;

void	readline_sigint(int sigid)
{
	t_bsh	*bsh;

	(void)sigid;
	g_sigint_detected = 1;
	bsh = get_shell_data();
	if (bsh->input.type == HISTORY_SEARCH)
		go_to_beg_line(&bsh->input);
	reset_buffer(&bsh->input);
	tputs(tgetstr("me", NULL), 1, putchar_termcaps);
	if (bsh->input.buf_tmp)
		ft_memset(bsh->input.buf_tmp, 0, ft_strlen(bsh->input.buf_tmp));
	bsh->input.pivot = -1;
	bsh->input.state = STANDARD;
	bsh->input.type = REGULAR_INPUT;
	bsh->history.current = bsh->history.len;
	reset_lexer(&bsh->lexer);
}
