/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:40:44 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/26 13:42:23 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		get_operator(t_lexer *lexer)
{
	if (lexer->token_len == 0)
	{
		if (append_char(lexer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	else if (ft_strchr(g_op_char, lexer->current_token[0]))
	{
		lexer->current_token[lexer->token_len++] = *(lexer->input);
		if (is_operator(lexer->current_token) == -1)
		{
			lexer->current_token[--lexer->token_len] = '\0';
			lexer->input--;
			if (delimitate_token(lexer) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		}
	}
	else if (is_operator(lexer->current_token) == -1)
	{
		if (delimitate_token(lexer) == MALLOC_FAIL ||
				append_char(lexer) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	return (0);
}
