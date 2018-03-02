/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:42:58 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 09:29:23 by ble-berr         ###   ########.fr       */
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

static void		reset_expander(t_expander *exp)
{
	exp->buffer_len = 0;
	exp->tmp = NULL;
	exp->state = INIT_EXP;
	exp->event = START_EXP;
	if (exp->buffer)
		ft_bzero(exp->buffer, exp->buffer_size);
}

char			*expanded_str(t_expander *exp, char *string, const size_t type)
{
	char	*str;

	if (!exp->buffer)
	{
		if (!(exp->buffer = ft_strnew(INITIAL_SIZE)))
			return (NULL);
		exp->buffer_size = INITIAL_SIZE;
	}
	exp->tmp = string;
	while (*(exp->tmp))
	{
		if (g_exp[exp->state][exp->event].p_transit[type](exp) == MALLOC_FAIL)
		{
			reset_expander(exp);
			return (NULL);
		}
		(exp->state != INIT_EXP) ? exp->tmp++ : 0;
		exp->state = g_exp[exp->state][exp->event].new_state;
		exp->event = get_event_exp(*(exp->tmp));
	}
	str = ft_strdup(exp->buffer);
	reset_expander(exp);
	return (str);
}
