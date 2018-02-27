/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:39:58 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/03 19:26:10 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		start_arg_or_warg(t_arg *p, va_list ap)
{
	if (p->spec == 'C' || p->spec == 'S' || ((p->spec == 's' ||
				p->spec == 'c') && p->lenght[0] == 'l'))
	{
		p->w_arg = handle_arg(p, ap);
		if (p->w_arg == NULL)
			p->arg_len = 6;
		else
			p->arg_len = ft_wstrlen(p->w_arg);
	}
	else
	{
		p->arg = handle_arg(p, ap);
		if ((p->arg && ft_strcmp(p->arg, "(null)") == 0) || p->arg == NULL)
			p->arg = ft_strdup("(null)");
		p->arg_len = ft_strlen(p->arg);
		p->neg = (p->arg[0] == '-') ? 1 : 0;
	}
}

const char	*start_arg(t_arg *p, const char *format, va_list ap)
{
	if ((format = parse_flags(format, p)) == NULL ||
			(format = parse_remain(format, p, ap)) == NULL)
		g_error = -1;
	start_arg_or_warg(p, ap);
	if (ft_strchr("xXoOdDiuU", p->spec) != NULL && p->precision == 0 &&
			p->arg != NULL && p->arg[0] == '0')
	{
		p->arg[0] = '\0';
		p->arg_len = 0;
	}
	if (p->arg && ft_strcmp(p->arg, "0x") == 0)
		p->arg = ft_strjoin_free(p->arg, "0", 1);
	if (p->arg && ft_strcmp(p->arg, "0x0") == 0 && p->spec == 'p' &&
			p->precision > -1)
	{
		p->arg[2] = '\0';
		p->arg_len = 2;
	}
	p->end_format = (char*)format;
	return (format);
}

t_arg		*go_through_format(const char *format, va_list ap)
{
	t_arg		*p;
	t_arg		*p2;
	char		*s;

	p = NULL;
	p2 = NULL;
	if (*format)
	{
		while (*format)
		{
			s = (char*)format;
			while (*format != '%' && *format)
				format++;
			if (!*(format++))
				break ;
			append_list(&p, &p2);
			p->start_format_part = s;
			p->end_format_part = (char*)format - 2;
			format = start_arg(p, format, ap);
		}
	}
	return (p2);
}

int			ft_printf(const char *format, ...)
{
	t_arg	*arg_list;
	va_list	ap;
	int		return_value;

	return_value = 0;
	g_error = 0;
	if (format == NULL)
		return (error_null_param());
	va_start(ap, format);
	arg_list = go_through_format(format, ap);
	if (g_error == -1)
	{
		free_arg_list(&arg_list);
		return (-1);
	}
	return_value = print_output(arg_list, format);
	free_arg_list(&arg_list);
	va_end(ap);
	return (return_value);
}
