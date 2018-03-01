/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_sigint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:52:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 16:52:26 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	readline_sigint(int sigid)
{
	t_bsh	*bsh;

	(void)sigid;
	bsh = get_shell_data();
	reset_buffer(&bsh->input);
	tputs(tgetstr("me", NULL), 1, putchar_termcaps);
	if (bsh->input.buf_tmp)
		ft_memset(bsh->input.buf_tmp, 0, ft_strlen(bsh->input.buf_tmp));
	if (bsh->input.type == HISTORY_SEARCH)
		go_to_beg_line(&bsh->input);
	if (bsh->input.type != HISTORY_SEARCH)
		write(STDIN_FILENO, "\n", 1);
	bsh->input.pivot = -1;
	bsh->input.state = STANDARD;
	bsh->input.type = REGULAR_INPUT;
	bsh->history.current = bsh->history.len;
	reset_lexer(&bsh->lexer);
	print_prompt(&bsh->input, BOLD_CYAN);
}
