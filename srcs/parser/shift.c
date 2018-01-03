/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:33:56 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/23 11:57:20 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int					shift(t_parser *parser)
{
	if (parser->exec_list && (parser->cur_token->type >= AND_IF &&
		parser->cur_token->type <= PIPE))
	{
		parser->last_exec->cmd_separator = parser->cur_token->type;
		parser->last_exec->next = init_exec();
		parser->last_exec->next->prev = parser->last_exec;
		parser->last_exec = parser->last_exec->next;
	}
	if (parser->cur_token->pushed == 1)
	{
		parser->cur_token->pushed = 0;
		return (UNCLOSED_QUOTES);
	}
	push_token_stack(parser);
	push_state(parser);
	parser->cur_token->pushed = 1;
	if (parser->cur_token->next)
	{
		parser->cur_token->pushed = 0;
		parser->cur_token = parser->cur_token->next;
	}
	return (-1);
}
