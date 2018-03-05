/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exp_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:40:07 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/05 12:41:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	init_exp_input(t_string *exp_input, const int size)
{
	if (!(exp_input->str = ft_strnew(size)))
		return (MALLOC_FAIL);
	exp_input->len = 0;
	exp_input->size = size;
	return (0);
}
