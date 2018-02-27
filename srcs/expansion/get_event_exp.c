/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:28 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/27 12:59:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	get_event_exp(char c)
{
	if (c == '"')
		return (EV_DQUOTE_EXP);
	else if (c == '\'')
		return (EV_QUOTE_EXP);
	else if (c == '$')
		return (EV_DOLLAR_EXP);
	else if (c == '~')
		return (EV_TILDE_EXP);
	else if (c == '\\')
		return (EV_BACKSLASH_EXP);
	else if (c != '\0')
		return (EV_REG_CHAR_EXP);
	return (0);
}
