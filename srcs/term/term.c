/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:55:29 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/27 13:15:49 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		restore_custom_attr(t_term *term)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term->custom_attr) == -1)
		ft_dprintf(STDERR_FILENO, "Unable to set custom attributes");
	return (0);
}

int		init_termcaps(t_bsh *bsh)
{
	char	*termtype;

	if (!(termtype = ft_getenv(bsh->env.env_list, "TERM")->value))
		ft_dprintf(STDERR_FILENO, "Missing $TERM variable");
	if (tgetent(NULL, termtype) < 1)
		ft_dprintf(STDERR_FILENO, "tgetent failed\n");
	if (tcgetattr(STDIN_FILENO, &bsh->term.initial_attr) == -1)
		ft_dprintf(STDERR_FILENO, "Unable to get terminal attributes");
	if (tcgetattr(STDIN_FILENO, &bsh->term.custom_attr) == -1)
		ft_dprintf(STDERR_FILENO, "Unable to get terminal attributes");
	bsh->term.custom_attr.c_lflag &= ~(ICANON | ECHO);
	bsh->term.custom_attr.c_cc[VMIN] = 1;
	bsh->term.custom_attr.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &bsh->term.custom_attr) == -1)
		ft_dprintf(STDERR_FILENO, "Unable to set custom attributes");
	return (0);
}

int		restore_initial_attr(t_term *term)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term->initial_attr) == -1)
		ft_dprintf(STDERR_FILENO, "Unable to reset initial attributes");
	return (0);
}

void	get_term_size(t_term *term)
{
	struct winsize	winsize;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &winsize);
	term->width = winsize.ws_col;
}

int		init_term(t_term *term)
{
	term->prompt_len = 0;
	term->cursor_row = 0;
	term->cursor_col = 0;
	get_term_size(term);
	get_prompt(term);
	return (0);
}
