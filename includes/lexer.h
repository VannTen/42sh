/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:46:10 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/26 15:26:22 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "tokens.h"
# include "libft.h"
# define INITIAL_TOKEN_SIZE 32

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
	size_t			token_len;
	size_t			token_size;
	size_t			state;
	size_t			event;
	t_token			*tokens[2];
}					t_lexer;

typedef struct		s_transition
{
	size_t			new_state;
	int				(*p_transit)(t_lexer *lexer);
}					t_transition;

int					lexer(t_lexer *lexer, char *input);
int					init_lexer(t_lexer *lexer);
t_token				*init_token_node(t_lexer *lexer);
int					append_char(t_lexer *lexer);
int					delimitate_token(t_lexer *lexer);
int					get_operator(t_lexer *lexer);
int					handle_backslash(t_lexer *lexer);
int					end_of_input(t_lexer *lexer);
int					realloc_current_token(t_lexer *lexer);
int					is_operator(const char *token);
void				get_event(t_lexer *lexer);
void				clear_tokens(t_token **tokens);
int					reset_lexer(t_lexer *lexer);
void				display_tokens(t_token *tokens);

extern const t_transition	g_lexer[MAX_STATE][MAX_EVENT];
extern const char			g_op_char[];
extern const char			*g_op_list[];
#endif
