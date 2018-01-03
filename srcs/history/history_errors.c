/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:20:47 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/09 13:09:22 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

int	history_usage(char opt, int type)
{
	ft_putstr_fd("bsh: history: -", STDERR);
	ft_putchar_fd(opt, STDERR);
	(type == INVALID_OPT) ? ft_putendl_fd(": invalid option", STDERR) :
		ft_putendl_fd(": option requires an argument", STDERR);
	ft_putendl_fd("history: usage: history [-c]", STDERR);
	return (1);
}
