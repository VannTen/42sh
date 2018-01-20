/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:15:49 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 12:14:04 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_binary(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa_base((unsigned int)va_arg(ap, long long), "01");
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa_base((unsigned char)va_arg(ap, long long), "01");
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa_base((unsigned short)va_arg(ap, long long), "01");
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa_base((unsigned long)va_arg(ap, long long), "01");
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa_base(va_arg(ap, unsigned long long), "01");
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa_base_umax((uintmax_t)va_arg(ap, unsigned long long), "01");
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa_base((size_t)va_arg(ap, unsigned long long), "01");
	return (s);
}
