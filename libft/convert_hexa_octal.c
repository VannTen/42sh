/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex_octal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:56:38 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/03 19:40:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_hexa_upper(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa_base((unsigned int)va_arg(ap, long long), HEXA_U);
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa_base((unsigned char)va_arg(ap, long long), HEXA_U);
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa_base((unsigned short)va_arg(ap, long long), HEXA_U);
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa_base_llu((unsigned long)va_arg(ap, long long), HEXA_U);
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa_base_llu(va_arg(ap, unsigned long long), HEXA_U);
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa_base_umax((uintmax_t)va_arg(ap, uintmax_t), HEXA_U);
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa_base_llu((size_t)va_arg(ap, long long), HEXA_U);
	return (s);
}

char	*convert_hexa_lower(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa_base((unsigned int)va_arg(ap, long long), HEXA_L);
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa_base((unsigned char)va_arg(ap, long long), HEXA_L);
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa_base((unsigned short)va_arg(ap, long long), HEXA_L);
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa_base_llu((unsigned long)va_arg(ap, long long), HEXA_L);
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa_base_llu(va_arg(ap, unsigned long long), HEXA_L);
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa_base_umax((uintmax_t)va_arg(ap, intmax_t), HEXA_L);
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa_base_llu((size_t)va_arg(ap, long long), HEXA_L);
	return (s);
}

char	*convert_octal(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa_base((unsigned int)va_arg(ap, long), OCTAL);
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa_base((unsigned char)va_arg(ap, long), OCTAL);
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa_base((unsigned short)va_arg(ap, long), OCTAL);
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa_base_llu((unsigned long)va_arg(ap, long), OCTAL);
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa_base_llu(va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa_base_umax((uintmax_t)va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa_base_llu((size_t)va_arg(ap, long), OCTAL);
	return (s);
}

char	*convert_long_octal(t_arg *p, va_list ap)
{
	char	*s;

	if (p->lenght[0] == 0)
		s = ft_itoa_base_llu((unsigned long)va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("hh", p->lenght) == 0)
		s = ft_itoa_base_llu((unsigned char)va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("h", p->lenght) == 0)
		s = ft_itoa_base_llu((unsigned short)va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("l", p->lenght) == 0)
		s = ft_itoa_base_llu((unsigned long)va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("ll", p->lenght) == 0)
		s = ft_itoa_base_llu(va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("j", p->lenght) == 0)
		s = ft_itoa_base_umax((uintmax_t)va_arg(ap, unsigned long), OCTAL);
	if (ft_strcmp("z", p->lenght) == 0)
		s = ft_itoa_base_llu((size_t)va_arg(ap, unsigned long), OCTAL);
	return (s);
}
