/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:23:36 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/09 16:20:53 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token		*init_token_node(t_lexer *lexer)
{
	t_token	*token;
	int		op;

	op = 0;
	if (!(token = (t_token*)malloc(sizeof(t_token))))
		return (NULL);
	dprintf(get_shell_data()->input.fd, "[%s]\n", lexer->current_token);
	if (!(token->value = ft_strdup(lexer->current_token)))
		return (NULL);
	if ((op = is_operator(token->value)) != -1)
		token->type = op;
	else if (!ft_strcmp(lexer->current_token, "\n") && (lexer->state == STD ||
			lexer->state == COMMENT))
		token->type = NEWLINE;
	else
		token->type = WORD;
	if (ft_str_isdigit(token->value) && (*(lexer->input) == '<' ||
			*(lexer->input) == '>'))
		token->type = IO_NUMBER;
	token->next = NULL;
	ft_bzero(lexer->current_token, lexer->token_len);
	lexer->token_len = 0;
	return (token);
}
