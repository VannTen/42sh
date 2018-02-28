/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:55:29 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/28 15:19:43 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		restore_custom_attr(t_term *term)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term->custom_attr) == -1)
		ft_dprintf(STDERR_FILENO, "42sh: Unable to set custom attributes");
	return (0);
}

int		init_termcaps(t_bsh *bsh)
{
	char	*termtype;
	int		ret;

	ret = 0;
	if (!(termtype = ft_getenv(bsh->env.env_list, "TERM")->value))
		ret = ft_dprintf(STDERR_FILENO, "Missing TERM variable");
	else if (tgetent(NULL, termtype) < 1)
		ret = ft_dprintf(STDERR_FILENO, "42sh: Tgetent failed\n");
	else if (tcgetattr(STDIN_FILENO, &bsh->term.initial_attr) == -1)
		ret = ft_dprintf(STDERR_FILENO, "42sh: Unable to get term attributes");
	else if (tcgetattr(STDIN_FILENO, &bsh->term.custom_attr) == -1)
		ret = ft_dprintf(STDERR_FILENO, "42sh: Unable to get term attributes");
	else
	{
		bsh->term.custom_attr.c_lflag &= ~(ICANON | ECHO);
		bsh->term.custom_attr.c_cc[VMIN] = 1;
		bsh->term.custom_attr.c_cc[VTIME] = 0;
		if (tcsetattr(STDIN_FILENO, TCSANOW, &bsh->term.custom_attr) == -1)
			ret = ft_dprintf(STDERR_FILENO, "42sh: Unable to set custom"
					"attributes\n");
	}
	if (ret)
		exit(EXIT_FAILURE);
	return (0);
}

int		restore_initial_attr(t_term *term)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term->initial_attr) == -1)
		ft_dprintf(STDERR_FILENO, "42sh: Unable to reset initial attributes");
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
