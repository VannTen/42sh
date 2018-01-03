/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:40:44 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/19 15:59:02 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void		get_operator(t_lexer *lexer)
{
	if (lexer->token_len == 0)
		append_char(lexer);
	else if (ft_strchr(g_op_char, lexer->current_token[0]))
	{
		lexer->current_token[lexer->token_len++] = *(lexer->input);
		if (is_operator(lexer->current_token) == -1)
		{
			lexer->current_token[--lexer->token_len] = '\0';
			lexer->input--;
		}
		delimitate_token(lexer);
	}
	else if (is_operator(lexer->current_token) == -1)
	{
		delimitate_token(lexer);
		append_char(lexer);
	}
}
