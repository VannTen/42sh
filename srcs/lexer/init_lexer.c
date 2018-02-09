/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:39:37 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/22 15:15:14 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		init_lexer(t_lexer *lexer)
{
	if (!(lexer->current_token = ft_strnew(INITIAL_TOKEN_SIZE + 1)))
		return (MALLOC_FAIL);
	lexer->input = NULL;
	lexer->token_size = INITIAL_TOKEN_SIZE;
	lexer->token_len = 0;
	lexer->state = INIT;
	lexer->event = START;
	lexer->tokens[0] = NULL;
	lexer->tokens[1] = NULL;
	return (0);
}
