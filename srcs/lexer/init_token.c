/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:23:36 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 14:47:18 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		evaluate_bang(t_token *token)
{
	if (!token || (token->type == AND_IF
				|| token->type == OR_IF
				|| token->type == PIPE
				|| token->type == SEMI))
		return (BANG);
	return (WORD);
}

static t_token	*init_token_node(const char *cur_token)
{
	t_token	*token;

	if (!(token = (t_token*)malloc(sizeof(t_token))))
		return (NULL);
	if (!(token->value = ft_strdup(cur_token)))
	{
		ft_memdel((void**)token);
		return (NULL);
	}
	return (token);
}

t_token			*init_token(t_lexer *lexer)
{
	t_token	*token;
	int		op;

	op = 0;
	if (!(token = init_token_node(lexer->current_token)))
		return (NULL);
	if ((op = is_operator(token->value)) != -1)
		token->type = op;
	else if (!ft_strcmp(lexer->current_token, "\n") && (lexer->state == STD ||
			lexer->state == COMMENT))
		token->type = NEWLINE;
	else
		token->type = WORD;
	if (!ft_strcmp(token->value, "!"))
		token->type = evaluate_bang(lexer->tokens[1]);
	if (ft_str_isdigit(token->value) && (*(lexer->input) == '<' ||
			*(lexer->input) == '>'))
		token->type = IO_NUMBER;
	token->next = NULL;
	ft_bzero(lexer->current_token, lexer->token_size);
	lexer->token_len = 0;
	return (token);
}
