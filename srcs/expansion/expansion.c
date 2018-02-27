/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:42:58 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/26 13:34:46 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

const t_transit	g_exp[MAX_STATE_EXP][MAX_EVENT_EXP] = {
	{{STD_EXP, {skip, skip}},
		{DQUOTE_EXP, {skip, skip}},
		{QUOTE_EXP, {skip, skip}},
		{STD_EXP, {handle_dollar, append}},
		{STD_EXP, {handle_tilde, append}},
		{STD_EXP, {handle_bckslsh, handle_bckslsh}},
		{STD_EXP, {append, append}}},

	{{STD_EXP, {NULL, NULL}},
		{DQUOTE_EXP, {skip, skip}},
		{QUOTE_EXP, {skip, skip}},
		{STD_EXP, {handle_dollar, append}},
		{STD_EXP, {handle_tilde, append}},
		{STD_EXP, {handle_bckslsh, handle_bckslsh}},
		{STD_EXP, {append, append}}},

	{{STD_EXP, {NULL, NULL}},
		{STD_EXP, {skip, skip}},
		{DQUOTE_EXP, {append, append}},
		{DQUOTE_EXP, {handle_dollar, append}},
		{DQUOTE_EXP, {append, append}},
		{DQUOTE_EXP, {handle_bckslsh_dquote, append}},
		{DQUOTE_EXP, {append, append}}},

	{{QUOTE_EXP, {NULL, NULL}},
		{QUOTE_EXP, {append, append}},
		{STD_EXP, {skip, skip}},
		{QUOTE_EXP, {append, append}},
		{QUOTE_EXP, {append, append}},
		{QUOTE_EXP, {append, append}},
		{QUOTE_EXP, {append, append}}},
};

char	*expanded_str(t_expander *exp, char *string, const size_t type)
{
	char	*str;

	exp->state = INIT_EXP;
	exp->event = START_EXP;
	exp->tmp = string;
	while (*(exp->tmp))
	{
		if (g_exp[exp->state][exp->event].p_transit[type](exp) == MALLOC_FAIL)
		{
			ft_strdel(&exp->buffer);
			return (NULL);
		}
		(exp->state != INIT_EXP) ? exp->tmp++ : 0;
		exp->state = g_expander[exp->state][exp->event].new_state;
		exp->event = get_event_exp(*(exp->tmp));
	}
	if (!(str = ft_strdup(exp->buffer)))
	{
		ft_strdel(&exp->buffer);
		return (NULL);
	}
	exp->tmp = NULL;
	exp->buffer_len = 0;
	ft_bzero(exp->buffer, exp->buffer_size);
	return (str);
}
