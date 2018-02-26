/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:43:04 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/26 13:08:21 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_expander	*init_expander(t_env *env)
{
	t_expander *exp;

	if ((exp = (t_expander*)malloc(sizeof(t_expander))) == NULL)
		return (NULL);
	exp->state = INIT_EXP;
	exp->event = START_EXP;
	exp->env = env;
	exp->buffer_size = INITIAL_SIZE;
	if (!(exp->buffer = ft_strnew(exp->buffer_size + 1)))
		return (NULL);
	exp->buffer_len = 0;
	exp->tmp = NULL;
	return (exp);
}
