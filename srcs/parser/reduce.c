/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:34:28 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/23 12:28:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

extern t_reduce_table	g_reduce_table[NB_RULES];
extern t_switch			g_parser[MAX_STATES][MAX_EVENTS];

int		reduce(t_parser *parser)
{
	int	i;
	int	k;

	i = g_parser[parser->state][parser->cur_token->type].transition;
	if (g_reduce_table[i].save && parser->exec_list)
		g_reduce_table[i].save(parser->last_exec, parser->stack);
	k = i;
	i = g_reduce_table[i].rule_len * 2 - 1;
	while (i--)
		pop_stack(&parser->stack);
	parser->stack->sym.type = g_reduce_table[k].symbol;
	if (parser->stack->next)
		parser->state = parser->stack->next->state;
	get_successor_state(parser, parser->stack->sym.type);
	return (-2);
}
