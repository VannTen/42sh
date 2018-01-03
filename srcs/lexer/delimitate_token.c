/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimitate_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:13:50 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/08 15:33:31 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void	delimitate_token(t_lexer *lexer)
{
	t_token	*token;

	if (lexer->token_len > 0)
	{
		token = init_token_node(lexer);
		if (!lexer->token_list[0])
		{
			token->prev = NULL;
			lexer->token_list[0] = token;
			lexer->token_list[1] = token;
		}
		else
		{
			lexer->token_list[1]->next = token;
			token->prev = lexer->token_list[1];
		}
		lexer->token_list[1] = token;
	}
}
