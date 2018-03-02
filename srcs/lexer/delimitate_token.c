/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimitate_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:13:50 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 13:32:13 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	delimitate_token(t_lexer *lexer)
{
	t_token	*token;

	if (lexer->token_len > 0)
	{
		if (!(token = init_token(lexer)))
			return (MALLOC_FAIL);
		if (!lexer->tokens[0])
		{
			token->prev = NULL;
			lexer->tokens[0] = token;
			lexer->tokens[1] = token;
		}
		else
		{
			lexer->tokens[1]->next = token;
			token->prev = lexer->tokens[1];
		}
		lexer->tokens[1] = token;
	}
	return (0);
}
