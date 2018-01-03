/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:17:02 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:00:38 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		get_event(t_lexer *lexer)
{
	char	c;

	c = *(lexer->input);
	if (c == '"')
		lexer->event = EV_DQUOTE;
	else if (c == '\\')
		lexer->event = EV_BACKSLASH;
	else if (c == '\'')
		lexer->event = EV_QUOTE;
	else if (ft_strchr(g_op_char, c))
		lexer->event = EV_OP_CHAR;
	else if (c == '\n')
		lexer->event = EV_NEWLINE;
	else if (ft_isspace(c))
		lexer->event = EV_BLANK;
	else if (c == '#' && !lexer->token_len)
		lexer->event = EV_COMMENT;
	else if (c != '\0')
		lexer->event = EV_REG_CHAR;
}
