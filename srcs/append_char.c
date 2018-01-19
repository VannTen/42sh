/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:15:35 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/18 14:16:49 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		append_char(t_lexer *lexer)
{
	if (lexer->token_len == lexer->token_size)
		realloc_current_token(lexer);
	if (is_operator(lexer->current_token) != -1 && lexer->state == STD)
	{
		lexer->current_token[lexer->token_len++] = *(lexer->input);
		if (is_operator(lexer->current_token) == -1)
		{
			lexer->current_token[--lexer->token_len] = '\0';
			delimitate_token(lexer);
			lexer->current_token[lexer->token_len++] = *(lexer->input);
		}
	}
	else
		lexer->current_token[lexer->token_len++] = *(lexer->input);
	return (0);
}
