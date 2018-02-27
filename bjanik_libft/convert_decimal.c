/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:35:20 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 12:14:00 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_decimal(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa(va_arg(ap, int));
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa((signed char)va_arg(ap, long long));
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa((short int)va_arg(ap, long long));
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa((long int)va_arg(ap, long long));
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa((long long)va_arg(ap, long long));
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa((size_t)va_arg(ap, long long));
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa((intmax_t)va_arg(ap, long long));
	return (s);
}

char	*convert_long_decimal(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa(va_arg(ap, unsigned long));
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa((unsigned char)va_arg(ap, unsigned long long));
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa((unsigned short int)va_arg(ap, unsigned long long));
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa((unsigned long)va_arg(ap, unsigned long long));
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa((unsigned long long)va_arg(ap, unsigned long long));
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa((size_t)va_arg(ap, unsigned long long));
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa((intmax_t)va_arg(ap, unsigned long long));
	return (s);
}
