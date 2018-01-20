/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:51:11 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 12:13:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_flag(t_arg *p, char c)
{
	if (ft_strchr(p->flags, c) != NULL)
		return (1);
	return (0);
}

const char	*multi_flags(const char *format, t_arg *p)
{
	while (is_flag(p, *format) == 1)
		format++;
	return (format);
}
