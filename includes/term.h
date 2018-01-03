/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:58:09 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 11:52:55 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H
# include "term.h"
# include "termios.h"
# define MAX_PROMPT_SIZE 256

typedef struct termios	t_termios;

typedef struct		s_term
{
	char			prompt[MAX_PROMPT_SIZE + 1];
	int				prompt_len;
	int				width;
	int				height;
	int				first_line_len;
	int				cursor_col;
	int				cursor_row;
	t_termios		initial_attr;
	t_termios		custom_attr;
}					t_term;

t_term				*init_term(void);
int					init_termcaps(t_term *term);
int					restore_initial_attr(t_term *term);
int					restore_custom_attr(t_term *term);
void				get_term_size(t_term *term);
void				get_prompt(t_term *term);
void				print_prompt(t_term *term, char *color);
void				display_basic_prompt(t_term *term);
#endif
