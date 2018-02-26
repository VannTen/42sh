/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:28 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/26 12:43:30 by bjanik           ###   ########.fr       */
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
}
