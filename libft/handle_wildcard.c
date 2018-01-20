/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:48:55 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 12:11:38 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_wildcard(t_arg *p, va_list ap)
{
	char	*s;

	s = NULL;
	p->width = va_arg(ap, int);
	if (p->width < -1)
	{
		p->width = ft_abs(p->width);
		if ((s = ft_strchr(p->flags, '0')) != NULL)
			*s = '-';
		else if (is_flag(p, '-') == 0)
			p->flags[ft_strlen(p->flags)] = '-';
	}
}
