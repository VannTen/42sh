/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:23:36 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/12 15:12:20 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	evaluate_bang(size_t token_type)
{
	if (token_type == AND_IF
			|| token_type == OR_IF
			|| token_type == PIPE
			|| token_type == SEMI)
		return (BANG);
	return (WORD);
}

t_token		*init_token_node(t_lexer *lexer)
{
	t_token	*token;
	int		op;

	op = 0;
	if (!(token = (t_token*)malloc(sizeof(t_token))))
		return (NULL);
	if (!(token->value = ft_strdup(lexer->current_token)))
		return (NULL);
	if ((op = is_operator(token->value)) != -1)
		token->type = op;
	else if (!ft_strcmp(lexer->current_token, "\n") && (lexer->state == STD ||
			lexer->state == COMMENT))
		token->type = NEWLINE;
	else
		token->type = WORD;
	if (lexer->tokens[1] && token->type == BANG)
		token->type = evaluate_bang(lexer->tokens[1]->type);
	if (ft_str_isdigit(token->value) && (*(lexer->input) == '<' ||
			*(lexer->input) == '>'))
		token->type = IO_NUMBER;
	token->next = NULL;
	ft_bzero(lexer->current_token, lexer->token_size);
	lexer->token_len = 0;
	return (token);
}
