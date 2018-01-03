/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:55:29 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/21 14:53:29 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int					restore_custom_attr(t_term *term)
{
	if (tcsetattr(STDIN, TCSANOW, &term->custom_attr) == -1)
		ft_error_msg("Unable to set custom attributes");
	return (0);
}

int					init_termcaps(t_term *term)
{
	char			*termtype;

	if (!(termtype = ft_getenv(get_bsh()->env, "TERM")->var_value))
		ft_error_msg("Missing $TERM variable");
	if (tgetent(NULL, termtype) < 1)
		ft_error_msg("tgetent failed\n");
	if (tcgetattr(STDIN, &term->initial_attr) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(STDIN, &term->custom_attr) == -1)
		exit(EXIT_FAILURE);
	term->custom_attr.c_lflag &= ~(ICANON | ECHO);
	term->custom_attr.c_cc[VMIN] = 1;
	term->custom_attr.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN, TCSANOW, &term->custom_attr) == -1)
		ft_error_msg("Unable to set custom attributes");
	return (0);
}

int					restore_initial_attr(t_term *term)
{
	if (tcsetattr(STDIN, TCSANOW, &term->initial_attr) == -1)
		ft_error_msg("Unable to reset initial attributes");
	return (0);
}

void				get_term_size(t_term *term)
{
	struct winsize	winsize;

	ioctl(STDIN, TIOCGWINSZ, &winsize);
	term->width = winsize.ws_col;
	term->height = winsize.ws_row;
}

t_term				*init_term(void)
{
	t_term			*term;

	if (!(term = (t_term*)malloc(sizeof(t_term))))
		ft_error_msg("Malloc term failed\n");
	term->prompt_len = 0;
	term->cursor_row = 0;
	term->cursor_col = 0;
	get_term_size(term);
	get_prompt(term);
	return (term);
}
