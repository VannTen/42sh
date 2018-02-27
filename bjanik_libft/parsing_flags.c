/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:54:24 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/09 16:47:26 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char			*parse_flags(const char *format, t_arg *p)
{
	if ((p->ret.flag = check_flags(p, *format)) > 0)
		format = multi_flags(format, p);
	if ((p->ret.flag2 = check_flags(p, *format)) > 0)
		format = multi_flags(format, p);
	if ((p->ret.flag3 = check_flags(p, *format)) > 0)
		format = multi_flags(format, p);
	if ((p->ret.flag4 = check_flags(p, *format)) > 0)
		format = multi_flags(format, p);
	if ((p->ret.flag5 = check_flags(p, *format)) > 0)
		format = multi_flags(format, p);
	if (valid_flags(p) == -1)
		g_error = -1;
	return (format);
}

static const char	*check_extra_wildcard(const char *format, t_arg *p)
{
	if (*format == '*' && p->width > -1)
		format++;
	return (format);
}

const char			*parse_remain(const char *format, t_arg *p, va_list ap)
{
	if ((p->ret.width = check_width(p, format, ap)) >= 0)
	{
		while (ft_isdigit(*format) == 1)
			format++;
		format = check_extra_wildcard(format, p);
	}
	if ((p->ret.precision = check_precision(p, format, ap)) > 0)
	{
		format++;
		(*format == '*') ? format++ : 0;
		if (*format == '.')
		{
			invalid_conversion_specifier('.');
			g_error = -1;
		}
		while (ft_isdigit(*format) == 1 || *format == '.')
			format++;
	}
	if ((p->ret.lenght = check_lenght(p, format)) >= 0)
		format += p->ret.lenght;
	if ((p->ret.spec = check_specifier(p, *format)) > 0)
		format++;
	if (valid_remain(p) == -1)
		g_error = -1;
	return (format);
}
