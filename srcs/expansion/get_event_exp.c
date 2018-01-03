/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:44:35 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/24 18:45:36 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

void	get_event_exp(t_expander *exp)
{
	if (*(exp->tmp) == '"')
		exp->event = EV_DQUOTE1;
	else if (*(exp->tmp) == '\'')
		exp->event = EV_QUOTE1;
	else if (*(exp->tmp) == '$')
		exp->event = EV_DOLLAR;
	else if (*(exp->tmp) == '~')
		exp->event = EV_TILDE;
	else if (*(exp->tmp) == '\\')
		exp->event = EV_BACKSLASH1;
	else if (*(exp->tmp) != '\0')
		exp->event = EV_REG_CHAR1;
}
