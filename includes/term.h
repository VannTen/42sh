/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:58:09 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/30 14:43:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H
# include <termios.h>
# include <term.h>

# define MAX_PROMPT_SIZE 256

typedef struct termios	t_termios;

typedef struct			s_term
{
	char				prompt[MAX_PROMPT_SIZE + 1];
	int					prompt_len;
	int					width;
	int					first_line_len;
	int					cursor_col;
	int					cursor_row;
	t_termios			initial_attr;
	t_termios			custom_attr;
}						t_term;

int						init_term(t_term *term);
int						restore_initial_attr(t_term *term);
int						restore_custom_attr(t_term *term);
void					get_term_size(t_term *term);
void					resize_term(int sigid);
#endif
