/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:42:36 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/27 15:18:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_width(t_arg *p)
{
	if (p->width > p->arg_len)
	{
		return (p->width - p->arg_len - p->len.hashtag - p->len.plus -
				p->len.precision - p->len.space);
	}
	return (0);
}

int	handle_precision(t_arg *p)
{
	int	neg;

	if (p->arg != NULL)
		neg = (p->arg[0] == '-') ? 1 : 0;
	if (ft_strchr("DdioOuUxXp", p->spec) != NULL)
	{
		if (p->precision > p->arg_len - neg)
			return (p->precision - p->arg_len + neg);
		else
			return (0);
	}
	else if (p->spec != '%')
	{
		if (p->precision < p->arg_len && p->precision > -1)
			p->arg_len = p->precision;
	}
	return (0);
}
