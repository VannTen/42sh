/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:15:35 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 15:14:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		append_char(t_lexer *lexer)
{
	if (lexer->token_len == lexer->token_size)
		if (realloc_current_token(lexer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	if (is_operator(lexer->current_token) != -1 && lexer->state == STD)
	{
		lexer->current_token[lexer->token_len++] = *(lexer->input);
		if (is_operator(lexer->current_token) == -1)
		{
			lexer->current_token[--lexer->token_len] = '\0';
			if (delimitate_token(lexer) == MALLOC_FAIL)
				return (MALLOC_FAIL);
			lexer->current_token[lexer->token_len++] = *(lexer->input);
		}
	}
	else
		lexer->current_token[lexer->token_len++] = *(lexer->input);
	return (0);
}
