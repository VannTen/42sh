/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:39:45 by bjanik            #+#    #+#             */
/*   Updated: 2017/02/07 15:57:51 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_string(t_arg *p)
{
	int	len;

	len = p->arg_len;
	if (p->precision > -1 && p->precision < len)
		len = p->precision;
	if (p->width > len)
	{
		if (is_flag(p, '-') == 1)
		{
			ft_putnstr(p->arg, len);
			ft_putnchar(' ', p->width - len);
		}
		else
		{
			ft_putnchar(' ', p->width - len);
			ft_putnstr(p->arg, len);
		}
		return (p->width);
	}
	else
		ft_putnstr(p->arg, len);
	return (len);
}

static int	handle_special_case(t_arg *p)
{
	if (p->spec == 'c' && p->arg[0] == '\0')
		return (ft_putchar('\0'));
	if (ft_strchr("Oo", p->spec) != NULL && p->precision > -1 &&
			p->arg[0] == 0 && is_flag(p, '#') == 1)
		return (ft_putchar('0'));
	return (0);
}

static int	print_number(t_arg *p, int nb_printed)
{
	if (is_flag(p, '0') == 1)
	{
		nb_printed += ft_putnchar('+', p->len.plus);
		nb_printed += ft_putnchar(' ', p->len.space);
		nb_printed += (p->precision < 0) ? ft_putnchar('-', p->neg) : 0;
		if (p->arg[0] != 0 && p->precision == -1)
			nb_printed += ft_putstr(p->print_hashtag);
	}
	nb_printed += (is_flag(p, '-') == 0) ? ft_putstr(p->print_width) : 0;
	if (is_flag(p, '0') == 0)
	{
		nb_printed += ft_putnchar('+', p->len.plus);
		nb_printed += ft_putnchar('-', p->neg);
		nb_printed += ft_putnchar(' ', p->len.space);
		nb_printed += (p->arg[0] != 0) ? ft_putstr(p->print_hashtag) : 0;
	}
	if (p->precision > -1 && is_flag(p, '0') == 1)
		nb_printed += ft_putstr(p->print_hashtag);
	if (p->precision > -1 && is_flag(p, '0') == 1)
		nb_printed += ft_putnchar('-', p->neg);
	nb_printed += ft_putstr(p->print_precision);
	nb_printed += ft_putstr(p->arg + p->neg);
	nb_printed += handle_special_case(p);
	nb_printed += (is_flag(p, '-') == 1) ? ft_putstr(p->print_width) : 0;
	return (nb_printed);
}

int			print_output(t_arg *p, const char *format)
{
	int	nb_printed;

	nb_printed = 0;
	if (p == NULL)
		return (ft_putstr(format));
	while (p)
	{
		init_print(p);
		nb_printed += write(1, p->start_format_part, p->end_format_part -
					p->start_format_part + 1);
		if (p->spec == 's' && p->lenght[0] != 'l')
			nb_printed += print_string(p);
		else if (p->spec == 's')
			nb_printed += print_ls(p);
		else if (p->spec == 'S')
			nb_printed += print_wide_s(p);
		else if (p->spec == 'C' || (p->spec == 'c' && p->lenght[0] == 'l'))
			nb_printed += print_wide_c(p);
		else
			nb_printed = print_number(p, nb_printed);
		if (p->next == NULL)
			nb_printed += write(1, p->end_format, ft_strlen(p->end_format));
		p = p->next;
	}
	return (nb_printed);
}
