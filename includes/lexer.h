/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:46:10 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:01:22 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "tokens.h"
# define INITIAL_TOKEN_SIZE 512
# define MAX_TOKENS 14
# define MAX_OP_CHAR 5

enum		e_state
{
	INIT,
	DQUOTE,
	QUOTE,
	STD,
	NWLINE,
	COMMENT,
	MAX_STATE,
};

enum		e_event
{
	START,
	EV_DQUOTE,
	EV_QUOTE,
	EV_OP_CHAR,
	EV_BLANK,
	EV_NEWLINE,
	EV_COMMENT,
	EV_REG_CHAR,
	EV_BACKSLASH,
	MAX_EVENT,
};

typedef struct		s_lexer
{
	char			*input;
	char			*current_token;
	int				token_len;
	int				token_size;
	int				state;
	int				prev_state;
	int				event;
	t_token			*token_list[2];
}					t_lexer;

typedef struct		s_transition
{
	int				new_state;
	void			(*p_transition)(t_lexer *lexer);
}					t_transition;

void				lexer(t_lexer *lexer, char *input, int initial_state);
t_lexer				*init_lexer(char *input, int initial_state);
t_token				*init_token_node(t_lexer *lexer);
void				push_back_token(t_lexer *lexer);
void				append_char(t_lexer *lexer);
void				delimitate_token(t_lexer *lexer);
void				get_operator(t_lexer *lexer);
void				get_event(t_lexer *lexer);
void				handle_backslash(t_lexer *lexer);
void				end_of_input(t_lexer *lexer);
void				get_operator(t_lexer *lexer);
void				realloc_current_token(t_lexer *lexer);
int					is_operator(char *token);

extern t_transition	g_lexer[MAX_STATE][MAX_EVENT];
extern char			g_op_char[6];
extern char			*g_op_list[15];
#endif
