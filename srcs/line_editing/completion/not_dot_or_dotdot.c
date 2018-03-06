/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_dot_or_dotdot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:23:17 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/06 12:24:28 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	not_dot_or_dotdot(const char *filename)
{
	if (ft_strcmp(".", filename) && ft_strcmp("..", filename))
		return (1);
	return (0);
}
