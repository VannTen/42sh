/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:41:39 by bjanik            #+#    #+#             */
/*   Updated: 2017/11/28 12:43:23 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

t_expander	*init_expander(t_env *env)
{
	t_expander *exp;

	if ((exp = (t_expander*)malloc(sizeof(t_expander))) == NULL)
		ft_error_msg("Malloc failed\n");
	exp->state = INIT1;
	exp->event = START1;
	exp->env = env;
	exp->buffer_size = INITIAL_SIZE + 1;
	if (!(exp->buffer = (char *)malloc(exp->buffer_size)))
		ft_error_msg("Malloc failed\n");
	ft_bzero(exp->buffer, exp->buffer_size);
	exp->buffer_len = 0;
	exp->tmp = NULL;
	return (exp);
}
