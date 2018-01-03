/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:39:47 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/20 12:13:34 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_unsigned(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa((unsigned int)va_arg(ap, unsigned int));
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa((unsigned char)va_arg(ap, unsigned long int));
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa((unsigned short)va_arg(ap, unsigned long int));
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa_llu((unsigned long)va_arg(ap, unsigned long long int));
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa_llu((unsigned long long)va_arg(ap, unsigned long long int));
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa_base_umax((uintmax_t)va_arg(ap, uintmax_t), "0123456789");
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa_llu((size_t)va_arg(ap, unsigned long int));
	return (s);
}

char	*convert_unsigned_long(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa_llu((unsigned long)va_arg(ap, unsigned long));
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa_llu((unsigned char)va_arg(ap, unsigned long int));
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa_llu((unsigned short)va_arg(ap, unsigned long int));
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa_llu((unsigned long)va_arg(ap, unsigned long long int));
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa_llu((unsigned long long)va_arg(ap, unsigned long long int));
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa_base_umax((uintmax_t)va_arg(ap, uintmax_t), "0123456789");
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa_llu((size_t)va_arg(ap, unsigned long long));
	return (s);
}
