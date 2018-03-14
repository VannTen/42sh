/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:04 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 16:37:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		init_expander(t_expander *exp)
{
	exp->state = INIT_EXP;
	exp->event = START_EXP;
	exp->buffer_size = INITIAL_SIZE;
	if (!(exp->buffer = ft_strnew(exp->buffer_size)))
		return (MALLOC_FAIL);
	exp->buffer_len = 0;
	exp->tmp = NULL;
	return (0);
}
