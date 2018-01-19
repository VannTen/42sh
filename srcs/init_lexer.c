/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:39:37 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/23 11:53:07 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer		*init_lexer(char *input)
{
	t_lexer	*lexer;

	if (!(lexer = (t_lexer*)malloc(sizeof(t_lexer))))
		return (NULL);
	if (!(lexer->current_token = ft_strnew(INITIAL_TOKEN_SIZE + 1)))
		return (NULL);
	lexer->input = input;
	lexer->token_size = INITIAL_TOKEN_SIZE;
	lexer->token_len = 0;
	lexer->state = INIT;
	lexer->event = START;
	lexer->tokens[0] = NULL;
	lexer->tokens[1] = NULL;
	return (lexer);
}
